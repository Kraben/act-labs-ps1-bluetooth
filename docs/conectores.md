# Conectores

## JP1 — Conector puente de 13 pines

Conecta la placa principal con la placa AutoFire.

| Pin JP1 | Señal | Desde | Hacia | GPIO ESP32 | Descripción |
|---:|---|---|---|---|---|
| 1 | VCC_3V3 | Placa principal | Placa_2 | 3V3 | Alimentación 3.3 V |
| 2 | AF_MODE | Placa_2 SW9 | ESP32 | GPIO15 | Modo turbo global |
| 3 | AF_R2 | Placa_2 SW8 | ESP32 | GPIO13 | Turbo R2 |
| 4 | AF_CUADRADO | Placa_2 SW6 | ESP32 | GPIO12 | Turbo □ |
| 5 | — | — | — | NC | No conectado |
| 6 | AF_TRIANGULO | Placa_2 SW7 | ESP32 | GPIO14 | Turbo △ |
| 7 | AF_L1 | Placa_2 SW1 | ESP32 | GPIO27 | Turbo L1 |
| 8 | AF_R1 | Placa_2 SW5 | ESP32 | GPIO33 | Turbo R1 |
| 9 | AF_CRUZ | Placa_2 SW2 | ESP32 | GPIO25 | Turbo × |
| 10 | AF_CIRCULO | Placa_2 SW3 | ESP32 | GPIO26 | Turbo ○ |
| 11 | AF_L2 | Placa_2 SW4 | ESP32 | GPIO32 | Turbo L2 |
| 12 | BATT_FROM_TP | Placa_2 SW10 | ESP32 VIN + D1 | VIN | Encendido modo BT; pasa por D1 SS14 |
| 13 | GND | Placa principal | Placa_2 | GND | Referencia común |

## JP2 — Botonera frontal

| Pin | Señal |
|---:|---|
| 1 | AF_TRIANGULO |
| 2 | AF_CIRCULO |
| 3 | GND |
| 4 | AF_CRUZ |
| 5 | GND |
| 6 | AF_CUADRADO |
| 7 | GND |
| 8 | GND |

## JP3 — Palanca direccional

| Pin | Señal |
|---:|---|
| 1 | GND |
| 2 | JP3_ABAJO |
| 3 | GND |
| 4 | JP3_IZQUIERDA |
| 5 | GND |
| 6 | JP3_DERECHA |
| 7 | GND |
| 8 | JP3_ARRIBA |

## JP4 — Botones laterales

| Pin | Señal |
|---:|---|
| 1 | AF_R1 |
| 2 | GND |
| 3 | GND |
| 4 | AF_L2 |
| 5 | AF_L1 |
| 6 | GND |
| 7 | AF_R2 |
| 8 | GND |

## PS1 Connector

| Pin | Señal |
|---:|---|
| 1 | PS1_DATA |
| 2 | PS1_CMD |
| 3 | VIB_NC |
| 4 | GND |
| 5 | VCC_3V3 |
| 6 | PS1_ATT |
| 7 | PS1_CLK |
| 8 | NC |
| 9 | PS1_ACK |
