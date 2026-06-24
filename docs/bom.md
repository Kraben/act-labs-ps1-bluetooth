# BOM V2

BOM consolidado a partir de los CSV exportados desde KiCad.

## Placa principal `ACT_Labs_REX`

Archivo fuente: `hardware/fabrication/ACT_Labs_REX_BOM.csv`.

| Cant. | Referencias | Valor / parte | Footprint |
|---:|---|---|---|
| 1 | C1 | 220µF | `Capacitor_THT:CP_Radial_D6.3mm_P2.50mm` |
| 1 | C2 | 100nF | `Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm` |
| 2 | C3, C4 | 10µF | `Capacitor_THT:CP_Radial_D6.3mm_P2.50mm` |
| 2 | D1, D3 | SS14 | `Diode_SMD:D_SMA` |
| 1 | D2 | LED | `LED_THT:LED_D3.0mm` |
| 1 | J1 | PS1_Connector1 | `Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical` |
| 1 | J2 | JP1 Autofire | `Connector_PinHeader_2.54mm:PinHeader_1x13_P2.54mm_Vertical` |
| 1 | J3 | JP3 Palanca Direccional | `Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical` |
| 1 | J4 | JP4 Botones Frontales | `Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical` |
| 1 | J5 | JP5 Botones laterales | `Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical` |
| 1 | J6 | JP6 Autofire | `Connector_PinHeader_2.54mm:PinHeader_1x13_P2.54mm_Vertical` |
| 5 | R1, R2, R3, R4, R5 | 10kΩ | `Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal` |
| 2 | R6, R7 | 4.7kΩ | `Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal` |
| 1 | R8 | 220Ω | `Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal` |
| 2 | Select1, Start1 | SW_Omron_B3FS | `Button_Switch_THT:SW_SPST_Omron_B3F-50xx` |
| 10 | SW1–SW10 | SW_SPDT | `Button_Switch_THT:Untitled_1` |
| 1 | U1 | ESP32 DevKit / 30 pin | `ESP32_Footprints:ESP32_30pin` |
| 1 | U2 | LD1117S33TR_SOT223 | `Package_TO_SOT_SMD:SOT-223-3_TabPin2` |

## Placa AutoFire

Archivo fuente: `hardware/fabrication/AutoFire_BOM.csv`.

| Cant. | Referencias | Valor / parte | Footprint |
|---:|---|---|---|
| 1 | D1 | LED | `LED_THT:LED_D3.0mm` |
| 1 | J1 | Conn_01x13 | `Connector_PinHeader_2.54mm:PinHeader_1x13_P2.54mm_Vertical` |
| 1 | R1 | 220Ω | `Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal` |
| 10 | SW1–SW10 | SW_SPDT | `Button_Switch_THT:SW_CK_JS202011CQN_DPDT_Straight` |

## Cambios importantes frente a documentación previa

- `R6` y `R7` quedan en **4.7 kΩ** para DATA/ACK según BOM V2.
- La placa principal agrega `C3` y `C4` de **10µF**.
- La placa principal tiene dos Schottky: `D1` y `D3` como **SS14**.
- La placa principal incluye `U2` como **LD1117S33TR_SOT223**.
- Los archivos POS indican 40 componentes en placa principal: 27 en top y 13 en bottom.
- La placa AutoFire tiene 13 componentes, todos en top.
