# Conectores V2

## TP4056

| Punto | Conexión |
|---|---|
| OUT+ | `BATT_FROM_TP` |
| OUT- | `GND` |
| BATT+ | Positivo de batería PS Vita |
| BATT- | Negativo de batería PS Vita |

## Batería PS Vita

| Cable | Señal | Nota |
|---|---|---|
| Rojo | `BAT+` | Positivo batería |
| Negro | `BAT-` | Negativo batería |
| Blanco | Termistor | Sin uso en esta revisión |

## Conector PS1 `J1`

| Pin | Señal |
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

## Conectores internos de placa principal

| Ref | Nombre | Pines | Función |
|---|---|---:|---|
| J2 | JP1 Autofire | 13 | Puente hacia placa AutoFire / señales de turbo |
| J3 | JP3 Palanca Direccional | 8 | D-Pad / palanca direccional |
| J4 | JP4 Botones Frontales | 8 | Triángulo, círculo, cruz, cuadrado y GND |
| J5 | JP5 Botones laterales | 8 | L1, L2, R1, R2 y GND |
| J6 | JP6 Autofire | 13 | Segundo conector de AutoFire según PCB V2 |

## Placa AutoFire

| Ref | Nombre | Pines | Función |
|---|---|---:|---|
| J1 | Conn_01x13 | 13 | Conexión de la placa AutoFire con la principal |
| SW1–SW10 | SW_SPDT | 3 cada uno | Activación/desactivación de turbo y encendido |
| D1 | LED | 2 | Indicador |
| R1 | 220Ω | 2 | Limitación de corriente para LED |

## Validaciones antes de energizar

1. Confirmar continuidad de `GND` entre TP4056, placa principal y AutoFire.
2. Confirmar que `OUT+` del TP4056 llegue a `BATT_FROM_TP` y no directamente a `VCC_3V3`.
3. Confirmar que el cable blanco de la batería PS Vita quede aislado si no se usa termistor.
4. Verificar orientación de diodos Schottky D1/D3 antes de conectar batería.
