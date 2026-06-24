# Mapeo GPIO ESP32

## Botones frontales

| # | Señal / función | GPIO ESP32 | JP / conector | Pin conector | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 1 | △ Triángulo | GPIO14 | JP1 / JP2 | 6 / 1 | INPUT | Interno | AF_TRIANGULO — SW7 Placa_2 |
| 2 | ○ Círculo | GPIO26 | JP1 / JP2 | 7 / 2 | INPUT | Interno | AF_CIRCULO — SW3 Placa_2 |
| 3 | □ Cuadrado | GPIO12 | JP1 / JP2 | 4 / 6 | INPUT | Interno | AF_CUADRADO — SW6 Placa_2 |
| 4 | × Cruz | GPIO25 | JP1 / JP2 | 8 / 4 | INPUT | Interno | AF_CRUZ — SW2 Placa_2 |

## Botones laterales

| # | Señal / función | GPIO ESP32 | JP / conector | Pin conector | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 6 | L1 | GPIO27 | JP1 / JP4 | 7 / 5 | INPUT | Interno | AF_L1 — SW1 Placa_2 |
| 7 | L2 | GPIO32 | JP1 / JP4 | 10 / 4 | INPUT | Interno | AF_L2 — SW4 Placa_2 |
| 8 | R1 | GPIO33 | JP1 / JP4 | 8 / 1 | INPUT | Interno | AF_R1 — SW5 Placa_2 |
| 9 | R2 | GPIO13 | JP1 / JP4 | 3 / 7 | INPUT | Interno | AF_R2 — SW8 Placa_2 |

## Palanca direccional JP3

| # | Señal / función | GPIO ESP32 | JP | Pin | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 11 | D-Pad Arriba | GPIO36 | JP3 | 8 | INPUT ONLY | 10 kΩ externo R1 | GPIO sin pull-up interno |
| 12 | D-Pad Abajo | GPIO34 | JP3 | 2 | INPUT ONLY | 10 kΩ externo R4 | GPIO sin pull-up interno |
| 13 | D-Pad Izquierda | GPIO35 | JP3 | 4 | INPUT ONLY | 10 kΩ externo R3 | GPIO sin pull-up interno |
| 14 | D-Pad Derecha | GPIO39 | JP3 | 6 | INPUT ONLY | 10 kΩ externo R5 | GPIO sin pull-up interno |

## START / SELECT

| # | Señal | GPIO ESP32 | Conector | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|
| 16 | START | GPIO2 | JP1 / START1 | INPUT | Interno + R6 15 kΩ | SW_Push_Dual |
| 17 | SELECT | GPIO16 | JP1 / SELECT1 | INPUT | Interno + R7 15 kΩ | SW_Push_Dual |

## Interfaz PS1 SPI

| # | Señal | GPIO ESP32 | Conector | Pin | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 19 | PS1_DATA / MISO | GPIO19 | PS1_Conn | 1 | OUTPUT | R1 1 kΩ a 3V3 | Mando → consola |
| 20 | PS1_CMD / MOSI | GPIO23 | PS1_Conn | 2 | INPUT | — | Consola → mando |
| 21 | PS1_ATT / CS | GPIO5 | PS1_Conn | 6 | INPUT | — | LOW = consola inicia comunicación |
| 22 | PS1_CLK | GPIO18 | PS1_Conn | 7 | INPUT | — | ~250 kHz |
| 23 | PS1_ACK | GPIO4 | PS1_Conn | 8 | OUTPUT | — | Pulso LOW ~2 µs |

## AutoFire / alimentación

| # | Señal | GPIO ESP32 | JP | Pin | Tipo | Notas |
|---:|---|---|---|---|---|---|
| 25 | AF_MODE | GPIO15 | JP1 | 2 | INPUT | SW9 Placa_2 — modo turbo global |
| 26 | BATT_FROM_TP | VIN | JP1 | 12 | PWR | SW10 Placa_2 — encendido modo BT |
| 27 | VCC_3V3 | 3V3 | JP1 | 1 | PWR | Alimenta Placa_2 |
| 28 | GND | GND | JP1 | 13 | GND | Referencia común |
