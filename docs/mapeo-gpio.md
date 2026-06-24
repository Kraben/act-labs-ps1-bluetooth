# Mapeo GPIO ESP32 Rev 1.4 / V2

Mapa funcional actualizado desde `ACT_Labs_Mapeo_Consolidado(2).xlsx` y `gpio_mapping.csv`.

## Botones frontales

| # | Señal / función | GPIO ESP32 | JP / conector | Pin conector | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 1 | Triángulo | GPIO14 | JP1 / JP2 | 6 / 1 | INPUT | PULLUP interno | AF_TRIANGULO - SW7 Placa_2 |
| 2 | Círculo | GPIO26 | JP1 / JP2 | 7 / 2 | INPUT | PULLUP interno | AF_CIRCULO - SW3 Placa_2 |
| 3 | Cuadrado | GPIO12 | JP1 / JP2 | 4 / 6 | INPUT | PULLUP interno | AF_CUADRADO - SW6 Placa_2 |
| 4 | Cruz | GPIO25 | JP1 / JP2 | 8 / 4 | INPUT | PULLUP interno | AF_CRUZ - SW2 Placa_2 |

## Botones laterales

| # | Señal / función | GPIO ESP32 | JP / conector | Pin conector | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 6 | L1 | GPIO27 | JP1 / JP4 | 7 / 5 | INPUT | PULLUP interno | AF_L1 - SW1 Placa_2 |
| 7 | L2 | GPIO32 | JP1 / JP4 | 10 / 4 | INPUT | PULLUP interno | AF_L2 - SW4 Placa_2 |
| 8 | R1 | GPIO33 | JP1 / JP4 | 8 / 1 | INPUT | PULLUP interno | AF_R1 - SW5 Placa_2 |
| 9 | R2 | GPIO13 | JP1 / JP4 | 3 / 7 | INPUT | PULLUP interno | AF_R2 - SW8 Placa_2 |

## D-Pad

| # | Señal / función | GPIO ESP32 | JP | Pin | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 11 | Arriba | GPIO36 | JP3 | 8 | INPUT ONLY | 10k externo R1 | Sin pull-up interno |
| 12 | Abajo | GPIO34 | JP3 | 2 | INPUT ONLY | 10k externo R4 | Sin pull-up interno |
| 13 | Izquierda | GPIO35 | JP3 | 4 | INPUT ONLY | 10k externo R3 | Sin pull-up interno |
| 14 | Derecha | GPIO39 | JP3 | 6 | INPUT ONLY | 10k externo R5 | Sin pull-up interno |

## START / SELECT

| # | Señal | GPIO ESP32 | Conector | Pin conector | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 16 | START | GPIO2 | JP1 / START1 | 12 / - | INPUT | PULLUP interno + R6 15k | SW_Push_Dual |
| 17 | SELECT | GPIO16 | JP1 / SELECT1 | 12 / - | INPUT | PULLUP interno + R7 15k | SW_Push_Dual |

## Interfaz PS1 SPI

| # | Señal | GPIO ESP32 | Conector | Pin | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 19 | PS1_DATA / MISO | GPIO19 | PS1_Conn | 1 | OUTPUT | R1 1k a 3V3 | Mando a consola |
| 20 | PS1_CMD / MOSI | GPIO23 | PS1_Conn | 2 | INPUT | - | Consola a mando |
| 21 | PS1_ATT / CS | GPIO5 | PS1_Conn | 6 | INPUT | - | LOW = consola iniciando comunicación |
| 22 | PS1_CLK | GPIO18 | PS1_Conn | 7 | INPUT | - | Reloj aprox 250kHz |
| 23 | PS1_ACK | GPIO4 | PS1_Conn | 8 | OUTPUT | - | Pulso LOW aprox 2us |

## AutoFire / alimentación

| # | Señal | GPIO ESP32 | JP | Pin | Tipo | Pull-up | Notas |
|---:|---|---|---|---|---|---|---|
| 25 | AF_MODE | GPIO15 | JP1 | 2 | INPUT | PULLUP interno | SW9 Placa_2 |
| 26 | BATT_FROM_TP | VIN | JP1 | 12 | PWR | - | SW10 Placa_2 - Encendido modo BT |
| 27 | VCC_3V3 | 3V3 | JP1 | 1 | PWR | - | Alimenta Placa_2 |
| 28 | GND | GND | JP1 | 13 | GND | - | Referencia común |

## Constantes sugeridas para firmware

```cpp
static constexpr uint8_t PIN_PS1_DATA = 19;
static constexpr uint8_t PIN_PS1_CMD  = 23;
static constexpr uint8_t PIN_PS1_ATT  = 5;
static constexpr uint8_t PIN_PS1_CLK  = 18;
static constexpr uint8_t PIN_PS1_ACK  = 4;

static constexpr uint8_t PIN_START   = 2;
static constexpr uint8_t PIN_SELECT  = 16;
static constexpr uint8_t PIN_AF_MODE = 15;
```

## Nota de revisión

El mapeo consolidado Rev 1.4 corrige `START` a GPIO2 y `SELECT` a GPIO16. Esto reemplaza la tabla anterior que los listaba como GPIO21/GPIO22.
