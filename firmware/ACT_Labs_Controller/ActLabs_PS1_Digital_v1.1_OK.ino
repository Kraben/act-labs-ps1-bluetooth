/*
  ACT Labs / Arcade Rex ESP32
  PS1 DIGITAL ONLY v1.1

  Basado en el codigo PS1 que ya funciono en consola PS1.

  Caracteristicas:
  - Emula control digital PS1 clasico.
  - Respuesta fija:
      FF 41 5A buttonsLow buttonsHigh
  - CLK en RISING.
  - DATA y ACK tipo open-drain / high-Z usando registros GPIO.
  - Sin BLE en esta version para reducir jitter.
  - Sin comandos PS2/config.
  - Todos los botones arcade mapeados.
  - Palanca corregida.
  - Turbo opcional.

  Pines protocolo:
    DATA = GPIO19  ESP32 -> PS1
    CMD  = GPIO23  PS1 -> ESP32
    ATT  = GPIO5   PS1 -> ESP32
    CLK  = GPIO18  PS1 -> ESP32
    ACK  = GPIO4   ESP32 -> PS1

  Pull-ups recomendados:
    DATA -> 10k a 3.3V
    ACK  -> 10k a 3.3V
    CMD  -> 10k a 3.3V si hace falta
    GND comun entre PS1 y ESP32
*/

#include <Arduino.h>
#include "soc/gpio_struct.h"
#include "esp_rom_sys.h"

// =====================================================
// CONFIG
// =====================================================

// 0 = turbo apagado
// 1 = turbo activo por mantener boton presionado
#define ENABLE_TURBO 0

#define TURBO_PERIOD_MS  50
#define TURBO_HOLD_MS    150

// Debug cada 2 segundos
#define DEBUG_PS1 1

// =====================================================
// PINES PS1
// =====================================================

#define PS1_DATA  19
#define PS1_CMD   23
#define PS1_ATT   5
#define PS1_CLK   18
#define PS1_ACK   4

// =====================================================
// BOTONES SEGUN ESQUEMATICO ACTLABS
// =====================================================

#define PIN_TRIANGULO  14
#define PIN_CIRCULO    26
#define PIN_CUADRADO   12
#define PIN_CRUZ       25

#define PIN_L1         27
#define PIN_L2         32
#define PIN_R1         33
#define PIN_R2         13

// Palanca corregida
// Estos pines tienen resistencias fisicas externas de 10k.
#define PIN_ARRIBA     34
#define PIN_ABAJO      36
#define PIN_IZQUIERDA  39
#define PIN_DERECHA    35

#define PIN_START      21
#define PIN_SELECT     22
#define PIN_AF_MODE    15

// =====================================================
// MAPA PS1 DIGITAL
// Activo bajo:
// 1 = suelto
// 0 = presionado
// =====================================================
//
// Byte 3 / buttonsLow:
// bit0 Select
// bit1 L3
// bit2 R3
// bit3 Start
// bit4 Up
// bit5 Right
// bit6 Down
// bit7 Left
//
// Byte 4 / buttonsHigh:
// bit0 L2
// bit1 R2
// bit2 L1
// bit3 R1
// bit4 Triangle
// bit5 Circle
// bit6 X / Cross
// bit7 Square

#define PS1_SELECT    0x0001
#define PS1_L3        0x0002
#define PS1_R3        0x0004
#define PS1_START     0x0008
#define PS1_UP        0x0010
#define PS1_RIGHT     0x0020
#define PS1_DOWN      0x0040
#define PS1_LEFT      0x0080

#define PS1_L2        0x0100
#define PS1_R2        0x0200
#define PS1_L1        0x0400
#define PS1_R1        0x0800
#define PS1_TRIANGLE  0x1000
#define PS1_CIRCLE    0x2000
#define PS1_CROSS     0x4000
#define PS1_SQUARE    0x8000

// =====================================================
// TURBO
// =====================================================

struct TurboButton {
  uint8_t pin;
  uint16_t mask;
  bool estadoReportado;
  bool turboActivo;
  unsigned long tiempoLow;
};

TurboButton turboButtons[] = {
  {PIN_TRIANGULO, PS1_TRIANGLE, false, false, 0},
  {PIN_CIRCULO,   PS1_CIRCLE,   false, false, 0},
  {PIN_CUADRADO,  PS1_SQUARE,   false, false, 0},
  {PIN_CRUZ,      PS1_CROSS,    false, false, 0},
  {PIN_L1,        PS1_L1,       false, false, 0},
  {PIN_L2,        PS1_L2,       false, false, 0},
  {PIN_R1,        PS1_R1,       false, false, 0},
  {PIN_R2,        PS1_R2,       false, false, 0},
};

#define NUM_TURBO_BUTTONS 8

unsigned long turboTimer = 0;
bool turboPulse = false;

// =====================================================
// PS1 STATE
// =====================================================

volatile uint8_t ps1_resp[5] = {
  0xFF, 0x41, 0x5A, 0xFF, 0xFF
};

volatile uint8_t ps1_byteIdx = 0;
volatile uint8_t ps1_bitIdx  = 0;
volatile bool ps1_active = false;

volatile uint32_t ps1_att_count = 0;
volatile uint32_t ps1_clk_count = 0;

static const uint32_t DATA_MASK = (1UL << PS1_DATA);
static const uint32_t ACK_MASK  = (1UL << PS1_ACK);

// =====================================================
// LINEAS OPEN-DRAIN POR REGISTRO
// HIGH = alta impedancia
// LOW  = tirar a GND
// =====================================================

inline void IRAM_ATTR dataHighZ() {
  GPIO.enable_w1tc = DATA_MASK;
}

inline void IRAM_ATTR dataLow() {
  GPIO.out_w1tc = DATA_MASK;
  GPIO.enable_w1ts = DATA_MASK;
}

inline void IRAM_ATTR ackHighZ() {
  GPIO.enable_w1tc = ACK_MASK;
}

inline void IRAM_ATTR ackLow() {
  GPIO.out_w1tc = ACK_MASK;
  GPIO.enable_w1ts = ACK_MASK;
}

inline void IRAM_ATTR setDataBit(bool bitValue) {
  if (bitValue) {
    dataHighZ();
  } else {
    dataLow();
  }
}

inline void IRAM_ATTR pulseAck() {
  // Timing tomado del codigo que funciono en PS1.
  esp_rom_delay_us(4);
  ackLow();
  esp_rom_delay_us(8);
  ackHighZ();
}

// =====================================================
// ISR PS1
// =====================================================

void IRAM_ATTR attISR() {
  ps1_att_count++;

  if (digitalRead(PS1_ATT) == LOW) {
    ps1_active = true;
    ps1_byteIdx = 0;
    ps1_bitIdx = 0;

    // Primer bit listo antes del primer clock.
    setDataBit(ps1_resp[0] & 0x01);
  } else {
    ps1_active = false;
    dataHighZ();
    ackHighZ();
  }
}

void IRAM_ATTR clkISR() {
  if (!ps1_active) return;
  if (digitalRead(PS1_ATT) == HIGH) return;

  ps1_clk_count++;

  ps1_bitIdx++;

  if (ps1_bitIdx >= 8) {
    ps1_bitIdx = 0;
    ps1_byteIdx++;

    // ACK despues de cada byte excepto despues del ultimo.
    if (ps1_byteIdx < 5) {
      pulseAck();
    }
  }

  if (ps1_byteIdx < 5) {
    setDataBit(ps1_resp[ps1_byteIdx] & (1 << ps1_bitIdx));
  } else {
    dataHighZ();
  }
}

// =====================================================
// INPUTS
// =====================================================

bool pressed(uint8_t pin) {
  return digitalRead(pin) == LOW;
}

void setupInputs() {
  // Botones normales con pull-up interno.
  pinMode(PIN_TRIANGULO, INPUT_PULLUP);
  pinMode(PIN_CIRCULO,   INPUT_PULLUP);
  pinMode(PIN_CUADRADO,  INPUT_PULLUP);
  pinMode(PIN_CRUZ,      INPUT_PULLUP);

  pinMode(PIN_L1, INPUT_PULLUP);
  pinMode(PIN_L2, INPUT_PULLUP);
  pinMode(PIN_R1, INPUT_PULLUP);
  pinMode(PIN_R2, INPUT_PULLUP);

  pinMode(PIN_START, INPUT_PULLUP);
  pinMode(PIN_SELECT, INPUT_PULLUP);
  pinMode(PIN_AF_MODE, INPUT_PULLUP);

  // Palanca: GPIO34/35/36/39 con resistencias fisicas externas de 10k.
  pinMode(PIN_ARRIBA, INPUT);
  pinMode(PIN_ABAJO, INPUT);
  pinMode(PIN_IZQUIERDA, INPUT);
  pinMode(PIN_DERECHA, INPUT);
}

// =====================================================
// TURBO / BOTONES
// =====================================================

void actualizarTurbo() {
#if ENABLE_TURBO
  unsigned long ahora = millis();

  if (ahora - turboTimer >= TURBO_PERIOD_MS) {
    turboPulse = !turboPulse;
    turboTimer = ahora;
  }

  for (int i = 0; i < NUM_TURBO_BUTTONS; i++) {
    bool low = pressed(turboButtons[i].pin);

    if (!low) {
      turboButtons[i].estadoReportado = false;
      turboButtons[i].turboActivo = false;
      turboButtons[i].tiempoLow = 0;
    } else {
      if (!turboButtons[i].tiempoLow) {
        turboButtons[i].tiempoLow = ahora;
      }

      if (ahora - turboButtons[i].tiempoLow >= TURBO_HOLD_MS) {
        turboButtons[i].turboActivo = true;
        turboButtons[i].estadoReportado = turboPulse;
      } else {
        turboButtons[i].turboActivo = false;
        turboButtons[i].estadoReportado = true;
      }
    }
  }
#else
  for (int i = 0; i < NUM_TURBO_BUTTONS; i++) {
    turboButtons[i].estadoReportado = pressed(turboButtons[i].pin);
    turboButtons[i].turboActivo = false;
    turboButtons[i].tiempoLow = 0;
  }
#endif
}

bool turboPressed(uint16_t mask) {
  for (int i = 0; i < NUM_TURBO_BUTTONS; i++) {
    if (turboButtons[i].mask == mask) {
      return turboButtons[i].estadoReportado;
    }
  }

  return false;
}

// =====================================================
// BUILD PS1 PACKET
// =====================================================

void buildPs1Packet() {
  uint16_t buttons = 0xFFFF;

  // Sistema
  if (pressed(PIN_SELECT)) buttons &= ~PS1_SELECT;
  if (pressed(PIN_START))  buttons &= ~PS1_START;

  // D-Pad corregido
  if (pressed(PIN_ARRIBA))     buttons &= ~PS1_UP;
  if (pressed(PIN_DERECHA))    buttons &= ~PS1_RIGHT;
  if (pressed(PIN_ABAJO))      buttons &= ~PS1_DOWN;
  if (pressed(PIN_IZQUIERDA))  buttons &= ~PS1_LEFT;

  // Accion / hombros
  if (turboPressed(PS1_L2))       buttons &= ~PS1_L2;
  if (turboPressed(PS1_R2))       buttons &= ~PS1_R2;
  if (turboPressed(PS1_L1))       buttons &= ~PS1_L1;
  if (turboPressed(PS1_R1))       buttons &= ~PS1_R1;

  if (turboPressed(PS1_TRIANGLE)) buttons &= ~PS1_TRIANGLE;
  if (turboPressed(PS1_CIRCLE))   buttons &= ~PS1_CIRCLE;
  if (turboPressed(PS1_CROSS))    buttons &= ~PS1_CROSS;
  if (turboPressed(PS1_SQUARE))   buttons &= ~PS1_SQUARE;

  uint8_t b3 = (uint8_t)(buttons & 0xFF);
  uint8_t b4 = (uint8_t)((buttons >> 8) & 0xFF);

  noInterrupts();
  ps1_resp[0] = 0xFF;
  ps1_resp[1] = 0x41;
  ps1_resp[2] = 0x5A;
  ps1_resp[3] = b3;
  ps1_resp[4] = b4;
  interrupts();
}

// =====================================================
// SETUP PS1
// =====================================================

void setupPs1Pins() {
  pinMode(PS1_CMD, INPUT);
  pinMode(PS1_ATT, INPUT_PULLUP);
  pinMode(PS1_CLK, INPUT_PULLUP);

  // DATA y ACK quedan high-Z.
  dataHighZ();
  ackHighZ();

  attachInterrupt(digitalPinToInterrupt(PS1_ATT), attISR, CHANGE);

  // PS1 funcional: RISING.
  attachInterrupt(digitalPinToInterrupt(PS1_CLK), clkISR, RISING);
}

// =====================================================
// DEBUG
// =====================================================

void printButtonsHuman(uint8_t b3, uint8_t b4) {
  bool any = false;

  auto one = [&](const char* name) {
    if (any) Serial.print(",");
    Serial.print(name);
    any = true;
  };

  if ((b3 & (1 << 0)) == 0) one("SELECT");
  if ((b3 & (1 << 3)) == 0) one("START");
  if ((b3 & (1 << 4)) == 0) one("UP");
  if ((b3 & (1 << 5)) == 0) one("RIGHT");
  if ((b3 & (1 << 6)) == 0) one("DOWN");
  if ((b3 & (1 << 7)) == 0) one("LEFT");

  if ((b4 & (1 << 0)) == 0) one("L2");
  if ((b4 & (1 << 1)) == 0) one("R2");
  if ((b4 & (1 << 2)) == 0) one("L1");
  if ((b4 & (1 << 3)) == 0) one("R1");
  if ((b4 & (1 << 4)) == 0) one("TRIANGLE");
  if ((b4 & (1 << 5)) == 0) one("CIRCLE");
  if ((b4 & (1 << 6)) == 0) one("X");
  if ((b4 & (1 << 7)) == 0) one("SQUARE");

  if (!any) Serial.print("NONE");
}

void debugPs1() {
#if DEBUG_PS1
  static unsigned long debugTimer = 0;
  static uint32_t lastAtt = 0;
  static uint32_t lastClk = 0;
  static uint8_t lastB3 = 0xFF;
  static uint8_t lastB4 = 0xFF;

  uint8_t b3;
  uint8_t b4;

  noInterrupts();
  b3 = ps1_resp[3];
  b4 = ps1_resp[4];
  interrupts();

  bool buttonsChanged = (b3 != lastB3) || (b4 != lastB4);

  if (millis() - debugTimer >= 2000 || buttonsChanged) {
    debugTimer = millis();

    uint32_t attNow = ps1_att_count;
    uint32_t clkNow = ps1_clk_count;

    uint32_t attDelta = attNow - lastAtt;
    uint32_t clkDelta = clkNow - lastClk;

    lastAtt = attNow;
    lastClk = clkNow;
    lastB3 = b3;
    lastB4 = b4;

    Serial.printf(
      "ATT:%lu CLK:%lu | resp: FF 41 5A %02X %02X | buttons=",
      attDelta,
      clkDelta,
      b3,
      b4
    );

    printButtonsHuman(b3, b4);
    Serial.println();
  }
#endif
}

// =====================================================
// SETUP / LOOP
// =====================================================

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println();
  Serial.println("ACT Labs / Arcade Rex ESP32");
  Serial.println("PS1 DIGITAL ONLY v1.1");
  Serial.println("CLK ISR: RISING");
  Serial.println("DATA/ACK: GPIO high-Z open-drain");
  Serial.println();

#if ENABLE_TURBO
  Serial.println("Turbo: ON");
#else
  Serial.println("Turbo: OFF");
#endif

  setupInputs();
  setupPs1Pins();

  actualizarTurbo();
  buildPs1Packet();

  Serial.println();
  Serial.println("Mapeo:");
  Serial.println("GPIO25 = X / CRUZ");
  Serial.println("GPIO26 = CIRCLE / CIRCULO");
  Serial.println("GPIO12 = SQUARE / CUADRADO");
  Serial.println("GPIO14 = TRIANGLE / TRIANGULO");
  Serial.println("GPIO27 = L1");
  Serial.println("GPIO33 = R1");
  Serial.println("GPIO32 = L2");
  Serial.println("GPIO13 = R2");
  Serial.println("GPIO21 = START");
  Serial.println("GPIO22 = SELECT");
  Serial.println("GPIO34 = UP");
  Serial.println("GPIO36 = DOWN");
  Serial.println("GPIO39 = LEFT");
  Serial.println("GPIO35 = RIGHT");
  Serial.println();

  Serial.println("Esperado:");
  Serial.println("NONE     -> FF 41 5A FF FF");
  Serial.println("X        -> FF 41 5A FF BF");
  Serial.println("CIRCLE   -> FF 41 5A FF DF");
  Serial.println("SQUARE   -> FF 41 5A FF 7F");
  Serial.println("TRIANGLE -> FF 41 5A FF EF");
  Serial.println("UP       -> FF 41 5A EF FF");
  Serial.println("DOWN     -> FF 41 5A BF FF");
  Serial.println("LEFT     -> FF 41 5A 7F FF");
  Serial.println("RIGHT    -> FF 41 5A DF FF");
  Serial.println();
}

void loop() {
  actualizarTurbo();
  buildPs1Packet();
  debugPs1();
}