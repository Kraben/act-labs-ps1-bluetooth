#include <Arduino.h>
#include <BleGamepad.h>
#include "soc/gpio_struct.h"
#include "esp_rom_sys.h"

// ================= PINES PS1 V1 =================
#define PS1_DATA  19
#define PS1_CMD   23
#define PS1_ATT   5
#define PS1_CLK   18
#define PS1_ACK   4

// ================= BOTONES =================
#define PIN_TRIANGULO  14
#define PIN_CIRCULO    26
#define PIN_CUADRADO   12
#define PIN_CRUZ       25

#define PIN_L1         27
#define PIN_L2         32
#define PIN_R1         33
#define PIN_R2         13

#define PIN_ARRIBA     34
#define PIN_ABAJO      36
#define PIN_IZQUIERDA  39
#define PIN_DERECHA    35

#define PIN_START      21
#define PIN_SELECT     22
#define PIN_AF_MODE    15

// ================= TURBO =================
#define TURBO_PERIOD_MS  50
#define TURBO_HOLD_MS   150

struct Boton {
  uint8_t pin;
  bool estadoReportado;
  bool turboActivo;
  unsigned long tiempoLow;
};

Boton af[] = {
  {PIN_TRIANGULO,false,false,0},
  {PIN_CIRCULO,  false,false,0},
  {PIN_CUADRADO, false,false,0},
  {PIN_CRUZ,     false,false,0},
  {PIN_L1,       false,false,0},
  {PIN_L2,       false,false,0},
  {PIN_R1,       false,false,0},
  {PIN_R2,       false,false,0},
};

#define NUM_AF 8
#define iT  0
#define iO  1
#define iQ  2
#define iX  3
#define iL1 4
#define iL2 5
#define iR1 6
#define iR2 7

unsigned long turbo_t = 0;
bool turbo_pulso = false;

void actualizarTurbo() {
  unsigned long ahora = millis();

  if (ahora - turbo_t >= TURBO_PERIOD_MS) {
    turbo_pulso = !turbo_pulso;
    turbo_t = ahora;
  }

  for (int i = 0; i < NUM_AF; i++) {
    bool low = (digitalRead(af[i].pin) == LOW);

    if (!low) {
      af[i].estadoReportado = false;
      af[i].turboActivo = false;
      af[i].tiempoLow = 0;
    } else {
      if (!af[i].tiempoLow) af[i].tiempoLow = ahora;

      if (ahora - af[i].tiempoLow >= TURBO_HOLD_MS) {
        af[i].turboActivo = true;
        af[i].estadoReportado = turbo_pulso;
      } else {
        af[i].turboActivo = false;
        af[i].estadoReportado = true;
      }
    }
  }
}

// ================= BLE =================
BleGamepad bleGamepad("ACT Labs PS1", "ACT-LABS", 100);

// ================= PS1 =================
volatile uint8_t ps1_resp[5] = {0xFF, 0x41, 0x5A, 0xFF, 0xFF};
volatile uint8_t ps1_byteIdx = 0;
volatile uint8_t ps1_bitIdx  = 0;
volatile bool ps1_active = false;

volatile uint32_t ps1_att_count = 0;
volatile uint32_t ps1_clk_count = 0;

static const uint32_t DATA_MASK = (1UL << PS1_DATA);
static const uint32_t ACK_MASK  = (1UL << PS1_ACK);

// HIGH = soltar linea / alta impedancia
// LOW  = tirar a GND
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

inline void IRAM_ATTR setDataBit(bool bit) {
  if (bit) dataHighZ();
  else dataLow();
}

inline void IRAM_ATTR pulseAck() {
  // prueba: ACK un poco despues de terminar byte
  esp_rom_delay_us(4);
  ackLow();
  esp_rom_delay_us(8);
  ackHighZ();
}

void IRAM_ATTR attISR() {
  ps1_att_count++;

  if (digitalRead(PS1_ATT) == LOW) {
    ps1_active = true;
    ps1_byteIdx = 0;
    ps1_bitIdx = 0;

    // Primer bit listo antes del primer clock
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

// ================= INPUTS =================
bool pressed(uint8_t pin) {
  return digitalRead(pin) == LOW;
}

void setupInputs() {
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

  pinMode(PIN_ARRIBA, INPUT);
  pinMode(PIN_ABAJO, INPUT);
  pinMode(PIN_IZQUIERDA, INPUT);
  pinMode(PIN_DERECHA, INPUT);
}

void setupPs1Pins() {
  pinMode(PS1_CMD, INPUT);
  pinMode(PS1_ATT, INPUT_PULLUP);
  pinMode(PS1_CLK, INPUT_PULLUP);

  dataHighZ();
  ackHighZ();

  attachInterrupt(digitalPinToInterrupt(PS1_ATT), attISR, CHANGE);

  // PRUEBA 1: RISING
  attachInterrupt(digitalPinToInterrupt(PS1_CLK), clkISR, RISING);

  // Si no detecta, cambia RISING por FALLING en la linea anterior.
}

void buildPs1Packet() {
  uint8_t b3 = 0xFF;
  uint8_t b4 = 0xFF;

// D-Pad SOLO PS1 - corregido por prueba real

if (pressed(PIN_ARRIBA))    b3 &= ~(1 << 4);
if (pressed(PIN_DERECHA))   b3 &= ~(1 << 5);
if (pressed(PIN_ABAJO))     b3 &= ~(1 << 6);
if (pressed(PIN_IZQUIERDA)) b3 &= ~(1 << 7);

  if (af[iL2].estadoReportado) b4 &= ~(1 << 0);
  if (af[iR2].estadoReportado) b4 &= ~(1 << 1);
  if (af[iL1].estadoReportado) b4 &= ~(1 << 2);
  if (af[iR1].estadoReportado) b4 &= ~(1 << 3);
  if (af[iT].estadoReportado)  b4 &= ~(1 << 4);
  if (af[iO].estadoReportado)  b4 &= ~(1 << 5);
  if (af[iX].estadoReportado)  b4 &= ~(1 << 6);
  if (af[iQ].estadoReportado)  b4 &= ~(1 << 7);

  noInterrupts();
  ps1_resp[0] = 0xFF;
  ps1_resp[1] = 0x41;
  ps1_resp[2] = 0x5A;
  ps1_resp[3] = b3;
  ps1_resp[4] = b4;
  interrupts();
}

// ================= BLE =================
void setupBle() {
  BleGamepadConfiguration cfg;
  cfg.setAutoReport(false);
  cfg.setControllerType(CONTROLLER_TYPE_GAMEPAD);
  cfg.setButtonCount(14);
  cfg.setHatSwitchCount(1);
  bleGamepad.begin(&cfg);
}

void updateBle() {
  if (!bleGamepad.isConnected()) return;

  if (af[iX].estadoReportado)  bleGamepad.press(BUTTON_1); else bleGamepad.release(BUTTON_1);
  if (af[iO].estadoReportado)  bleGamepad.press(BUTTON_2); else bleGamepad.release(BUTTON_2);
  if (af[iQ].estadoReportado)  bleGamepad.press(BUTTON_3); else bleGamepad.release(BUTTON_3);
  if (af[iT].estadoReportado)  bleGamepad.press(BUTTON_4); else bleGamepad.release(BUTTON_4);

  if (af[iL1].estadoReportado) bleGamepad.press(BUTTON_5); else bleGamepad.release(BUTTON_5);
  if (af[iR1].estadoReportado) bleGamepad.press(BUTTON_6); else bleGamepad.release(BUTTON_6);
  if (af[iL2].estadoReportado) bleGamepad.press(BUTTON_7); else bleGamepad.release(BUTTON_7);
  if (af[iR2].estadoReportado) bleGamepad.press(BUTTON_8); else bleGamepad.release(BUTTON_8);

  if (pressed(PIN_SELECT)) bleGamepad.press(BUTTON_9);  else bleGamepad.release(BUTTON_9);
  if (pressed(PIN_START))  bleGamepad.press(BUTTON_10); else bleGamepad.release(BUTTON_10);

  bool up = pressed(PIN_ARRIBA);
  bool down = pressed(PIN_ABAJO);
  bool left = pressed(PIN_IZQUIERDA);
  bool right = pressed(PIN_DERECHA);

  if      (up && right)    bleGamepad.setHat1(HAT_UP_RIGHT);
  else if (up && left)     bleGamepad.setHat1(HAT_UP_LEFT);
  else if (down && right)  bleGamepad.setHat1(HAT_DOWN_RIGHT);
  else if (down && left)   bleGamepad.setHat1(HAT_DOWN_LEFT);
  else if (up)             bleGamepad.setHat1(HAT_UP);
  else if (down)           bleGamepad.setHat1(HAT_DOWN);
  else if (left)           bleGamepad.setHat1(HAT_LEFT);
  else if (right)          bleGamepad.setHat1(HAT_RIGHT);
  else                     bleGamepad.setHat1(HAT_CENTERED);

  bleGamepad.sendReport();
}

bool detectPs1Activity() {
  ps1_att_count = 0;
  ps1_clk_count = 0;

  uint32_t start = millis();

  while (millis() - start < 1200) {
    if (ps1_att_count > 10) return true;
    delay(1);
  }

  return false;
}

bool modoPS1 = false;

unsigned long debug_t = 0;
uint32_t last_att = 0;
uint32_t last_clk = 0;

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("ACT Labs Hybrid PS1/BLE - PS1 timing test");
  Serial.println("V1 pins: DATA19 CMD23 ATT5 CLK18 ACK4");
  Serial.println("CLK ISR: RISING");
  Serial.println("ACK: delay 8us + low 8us");

  setupInputs();
  setupPs1Pins();

  Serial.println("Detectando PS1...");
  modoPS1 = detectPs1Activity();

  if (modoPS1) {
    Serial.println("MODO: PS1");
    Serial.printf("ATT al detectar: %lu | CLK al detectar: %lu\n", ps1_att_count, ps1_clk_count);
  } else {
    Serial.println("MODO: BLE");
    setupBle();
  }
}

void loop() {
  actualizarTurbo();
  buildPs1Packet();

  if (modoPS1) {
    if (millis() - debug_t >= 2000) {
      debug_t = millis();

      uint32_t att_delta = ps1_att_count - last_att;
      uint32_t clk_delta = ps1_clk_count - last_clk;

      last_att = ps1_att_count;
      last_clk = ps1_clk_count;

      Serial.printf(
        "ATT pulsos: %lu | CLK pulsos: %lu | resp: %02X %02X %02X %02X %02X\n",
        att_delta,
        clk_delta,
        ps1_resp[0],
        ps1_resp[1],
        ps1_resp[2],
        ps1_resp[3],
        ps1_resp[4]
      );
    }
  } else {
    updateBle();
  }
}