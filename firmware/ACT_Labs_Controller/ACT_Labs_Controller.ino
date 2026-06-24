/*
  ACT Labs PS1 Bluetooth / AutoFire
  Plantilla inicial de firmware para ESP32.

  Modos previstos:
  - PS1: emulación de control digital PS1 cuando PS1_ATT está LOW al arrancar.
  - Bluetooth: HID Gamepad BLE cuando PS1_ATT está HIGH al arrancar.

  Nota: esta plantilla documenta pines y lógica base. Falta completar el backend
  PS1 SPI y BLE HID según la librería seleccionada.
*/

#include <Arduino.h>

// -------------------- Pines de botones frontales --------------------
static constexpr uint8_t PIN_TRIANGULO = 14;
static constexpr uint8_t PIN_CIRCULO   = 26;
static constexpr uint8_t PIN_CUADRADO  = 12;
static constexpr uint8_t PIN_CRUZ      = 25;

// -------------------- Pines laterales --------------------
static constexpr uint8_t PIN_L1 = 27;
static constexpr uint8_t PIN_L2 = 32;
static constexpr uint8_t PIN_R1 = 33;
static constexpr uint8_t PIN_R2 = 13;

// -------------------- D-Pad: GPIO input-only con pull-up externo --------------------
static constexpr uint8_t PIN_UP    = 36;
static constexpr uint8_t PIN_DOWN  = 34;
static constexpr uint8_t PIN_LEFT  = 35;
static constexpr uint8_t PIN_RIGHT = 39;

// -------------------- START / SELECT --------------------
static constexpr uint8_t PIN_START  = 2;
static constexpr uint8_t PIN_SELECT = 16;

// -------------------- PS1 SPI --------------------
static constexpr uint8_t PIN_PS1_DATA = 19; // Mando -> consola
static constexpr uint8_t PIN_PS1_CMD  = 23; // Consola -> mando
static constexpr uint8_t PIN_PS1_ATT  = 5;  // CS / ATT
static constexpr uint8_t PIN_PS1_CLK  = 18; // Clock
static constexpr uint8_t PIN_PS1_ACK  = 4;  // ACK LOW pulse

// -------------------- AutoFire --------------------
static constexpr uint8_t PIN_AF_MODE = 15;

static constexpr uint16_t TURBO_ARM_MS = 150;
static constexpr uint16_t TURBO_HALF_PERIOD_MS = 50; // 50 ms ON + 50 ms OFF = 10 Hz

struct ButtonState {
  const char* name;
  uint8_t pin;
  bool usesInternalPullup;
  bool physicalPressed;
  bool virtualPressed;
  bool turboActive;
  uint32_t lowSinceMs;
  uint32_t lastToggleMs;
  bool turboPhase;
};

ButtonState buttons[] = {
  {"TRIANGULO", PIN_TRIANGULO, true, false, false, false, 0, 0, false},
  {"CIRCULO",   PIN_CIRCULO,   true, false, false, false, 0, 0, false},
  {"CUADRADO",  PIN_CUADRADO,  true, false, false, false, 0, 0, false},
  {"CRUZ",      PIN_CRUZ,      true, false, false, false, 0, 0, false},
  {"L1",        PIN_L1,        true, false, false, false, 0, 0, false},
  {"L2",        PIN_L2,        true, false, false, false, 0, 0, false},
  {"R1",        PIN_R1,        true, false, false, false, 0, 0, false},
  {"R2",        PIN_R2,        true, false, false, false, 0, 0, false},
  {"UP",        PIN_UP,        false, false, false, false, 0, 0, false},
  {"DOWN",      PIN_DOWN,      false, false, false, false, 0, 0, false},
  {"LEFT",      PIN_LEFT,      false, false, false, false, 0, 0, false},
  {"RIGHT",     PIN_RIGHT,     false, false, false, false, 0, 0, false},
  {"START",     PIN_START,     true, false, false, false, 0, 0, false},
  {"SELECT",    PIN_SELECT,    true, false, false, false, 0, 0, false},
};

void configurePins() {
  for (auto& button : buttons) {
    pinMode(button.pin, button.usesInternalPullup ? INPUT_PULLUP : INPUT);
  }

  pinMode(PIN_AF_MODE, INPUT_PULLUP);

  pinMode(PIN_PS1_DATA, OUTPUT);
  pinMode(PIN_PS1_ACK, OUTPUT);
  pinMode(PIN_PS1_CMD, INPUT);
  pinMode(PIN_PS1_ATT, INPUT);
  pinMode(PIN_PS1_CLK, INPUT);

  digitalWrite(PIN_PS1_DATA, HIGH);
  digitalWrite(PIN_PS1_ACK, HIGH);
}

void updateButton(ButtonState& button, uint32_t nowMs) {
  const bool low = (digitalRead(button.pin) == LOW);
  button.physicalPressed = low;

  if (low) {
    if (button.lowSinceMs == 0) {
      button.lowSinceMs = nowMs;
      button.lastToggleMs = nowMs;
      button.turboPhase = true;
    }

    const uint32_t heldMs = nowMs - button.lowSinceMs;
    button.turboActive = heldMs > TURBO_ARM_MS;

    if (button.turboActive) {
      if (nowMs - button.lastToggleMs >= TURBO_HALF_PERIOD_MS) {
        button.turboPhase = !button.turboPhase;
        button.lastToggleMs = nowMs;
      }
      button.virtualPressed = button.turboPhase;
    } else {
      button.virtualPressed = true;
    }
  } else {
    button.lowSinceMs = 0;
    button.turboActive = false;
    button.turboPhase = false;
    button.virtualPressed = false;
  }
}

void updateInputs() {
  const uint32_t nowMs = millis();
  for (auto& button : buttons) {
    updateButton(button, nowMs);
  }
}

bool shouldStartPs1Mode() {
  return digitalRead(PIN_PS1_ATT) == LOW;
}

void runPs1Mode() {
  // TODO: implementar respuesta PS1 digital:
  // Byte 0: 0xFF
  // Byte 1: 0x41
  // Byte 2: 0x5A
  // Byte 3: Select/Start/D-Pad activo en bajo
  // Byte 4: L2/R2/L1/R1/Triangulo/Circulo/Cruz/Cuadrado activo en bajo
}

void runBleMode() {
  // TODO: integrar librería BLE HID Gamepad para ESP32.
  // Convertir virtualPressed de cada boton a reporte HID.
}

void debugPrintInputs() {
  static uint32_t lastPrintMs = 0;
  const uint32_t nowMs = millis();
  if (nowMs - lastPrintMs < 500) return;
  lastPrintMs = nowMs;

  for (const auto& button : buttons) {
    Serial.print(button.name);
    Serial.print(button.virtualPressed ? "=1 " : "=0 ");
  }
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  configurePins();

  delay(20);
  Serial.println(shouldStartPs1Mode() ? "Modo PS1" : "Modo Bluetooth");
}

void loop() {
  updateInputs();
  debugPrintInputs();

  if (shouldStartPs1Mode()) {
    runPs1Mode();
  } else {
    runBleMode();
  }
}
