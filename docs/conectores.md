# Conectores V2

## TP4056

| Punto | Conexion |
|---|---|
| OUT+ | BATT_FROM_TP |
| OUT- | GND |
| BATT+ | Positivo de bateria PS Vita |
| BATT- | Negativo de bateria PS Vita |

## Bateria PS Vita

| Cable | Senal | Nota |
|---|---|---|
| Rojo | BAT+ | Positivo bateria |
| Negro | BAT- | Negativo bateria |
| Blanco | Termistor | Sin uso en esta revision |

## Conector PS1 J1

| Pin | Senal |
|---:|---|
| 1 | DATA |
| 2 | CMD |
| 3 | VIB_NC |
| 4 | GND |
| 5 | VCC_3V3 |
| 6 | ATT |
| 7 | CLK |
| 8 | NC |
| 9 | ACK |

## JP1 - Conector puente de 13 pines

| Pin JP1 | Senal | Desde | Hacia | GPIO ESP32 | Descripcion |
|---:|---|---|---|---|---|
| 1 | VCC_3V3 | Placa Principal | Placa_2 | 3V3 | Alimentacion 3.3V hacia Placa_2 |
| 2 | AF_MODE | Placa_2 SW9 | ESP32 | GPIO15 | Modo turbo global |
| 3 | AF_R2 | Placa_2 SW8 | ESP32 | GPIO13 | Turbo R2 |
| 4 | AF_CUADRADO | Placa_2 SW6 | ESP32 | GPIO12 | Turbo Cuadrado |
| 5 | NC | - | - | NC | No conectado |
| 6 | AF_TRIANGULO | Placa_2 SW7 | ESP32 | GPIO14 | Turbo Triangulo |
| 7 | AF_L1 | Placa_2 SW1 | ESP32 | GPIO27 | Turbo L1 |
| 8 | AF_R1 | Placa_2 SW5 | ESP32 | GPIO33 | Turbo R1 |
| 9 | AF_CRUZ | Placa_2 SW2 | ESP32 | GPIO25 | Turbo Cruz |
| 10 | AF_CIRCULO | Placa_2 SW3 | ESP32 | GPIO26 | Turbo Circulo |
| 11 | AF_L2 | Placa_2 SW4 | ESP32 | GPIO32 | Turbo L2 |
| 12 | BATT_FROM_TP | Placa_2 SW10 | ESP32 VIN + D1 | VIN | Encendido modo BT - pasa por D1 SS14 |
| 13 | GND | Placa Principal | Placa_2 | GND | Referencia comun |

## Conectores internos de placa principal

| Ref | Nombre | Pines | Funcion |
|---|---|---:|---|
| J2 | JP1 Autofire | 13 | Puente hacia placa AutoFire / senales de turbo |
| J3 | JP3 Palanca Direccional | 8 | D-Pad / palanca direccional |
| J4 | JP4 Botones Frontales | 8 | Triangulo, circulo, cruz, cuadrado y GND |
| J5 | JP5 Botones laterales | 8 | L1, L2, R1, R2 y GND |
| J6 | JP6 Autofire | 13 | Segundo conector de AutoFire segun PCB V2 |

## Placa AutoFire

| SW | Senal AF | Boton | JP1 Pin | GPIO | Funcion | Notas |
|---|---|---|---:|---|---|---|
| SW1 | AF_L1 | L1 | 7 | GPIO27 | Turbo L1 | OFF=boton directo, ON=GND->Turbo |
| SW2 | AF_CRUZ | Cruz | 9 | GPIO25 | Turbo Cruz | OFF=boton directo, ON=GND->Turbo |
| SW3 | AF_CIRCULO | Circulo | 10 | GPIO26 | Turbo Circulo | OFF=boton directo, ON=GND->Turbo |
| SW4 | AF_L2 | L2 | 11 | GPIO32 | Turbo L2 | OFF=boton directo, ON=GND->Turbo |
| SW5 | AF_R1 | R1 | 8 | GPIO33 | Turbo R1 | OFF=boton directo, ON=GND->Turbo |
| SW6 | AF_CUADRADO | Cuadrado | 4 | GPIO12 | Turbo Cuadrado | OFF=boton directo, ON=GND->Turbo |
| SW7 | AF_TRIANGULO | Triangulo | 6 | GPIO14 | Turbo Triangulo | OFF=boton directo, ON=GND->Turbo |
| SW8 | AF_R2 | R2 | 3 | GPIO13 | Turbo R2 | OFF=boton directo, ON=GND->Turbo |
| SW9 | AF_MODE | MODE | 2 | GPIO15 | Modo AF global | Reservado para uso futuro |
| SW10 | BATT_FROM_TP | - | 12 | VIN | Encendido BT | ON=alimenta ESP32 desde bateria |

## Nota de revision

El archivo `placa_2_autofire.csv` recibido lista algunos pines JP1 de forma inconsistente con `jp1_conector_puente.csv`. Para la documentacion de conectores se usa JP1 como fuente de verdad electrica: AF_CRUZ=pin 9, AF_CIRCULO=pin 10 y AF_L2=pin 11.

## Validaciones antes de energizar

1. Confirmar continuidad de GND entre TP4056, placa principal y AutoFire.
2. Confirmar que OUT+ del TP4056 llegue a BATT_FROM_TP y no directamente a VCC_3V3.
3. Confirmar que el cable blanco de la bateria PS Vita quede aislado si no se usa termistor.
4. Verificar orientacion de diodos Schottky D1/D3 antes de conectar bateria.
