# Revision V2 / PCB V2.2

## Estado recibido

- Proyecto principal: `ACT_Labs_REX`
- Titulo PCB principal: `CONVERSION PLACA ARCADE PS1-BLUETOOTH`
- Revision PCB principal: `2.2`
- KiCad: 10.0
- BLE: operativo
- PS1: en depuracion de `ACK` / `DATA`

## Cambios incorporados a documentacion

| Area | Ajuste |
|---|---|
| Arquitectura | Se documenta ESP32 DevKit V1, TP4056 externo, bateria PS Vita 3.7 V, LD1117-3.3 y Schottky |
| BOM | Se actualiza desde CSV KiCad V2 |
| Conectores | Se agrega TP4056, bateria PS Vita, J1-J6, JP1 y AutoFire |
| Firmware | Se documentan pines Rev 1.4 / V2 y resumen de protocolo PS1 |
| Mapeo GPIO | Se sincroniza con ACT_Labs_Mapeo_Consolidado(2).xlsx y gpio_mapping.csv |
| Fabricacion | Se agregan BOM/POS de placa principal y AutoFire |

## Valores importantes Rev 1.4 / V2

| Senal / componente | Valor / GPIO |
|---|---|
| DATA | GPIO19 |
| CMD | GPIO23 |
| ATT | GPIO5 |
| CLK | GPIO18 |
| ACK | GPIO4 |
| START | GPIO2 |
| SELECT | GPIO16 |
| AF_MODE | GPIO15 |
| Regulador | LD1117S33TR_SOT223 |
| Schottky | SS14 / 1N5817 |

## Archivos revisados en esta actualizacion

| Archivo | Uso |
|---|---|
| `ACT_Labs_Mapeo_Consolidado(2).xlsx` | Mapeo consolidado Rev 1.4 |
| `gpio_mapping.csv` | Fuente tabular del mapeo GPIO |
| `jp1_conector_puente.csv` | Fuente de verdad para pines JP1 |
| `placa_2_autofire.csv` | Tabla funcional de switches AutoFire |
| `firmware_resumen.md` | Resumen de modo, turbo y protocolo PS1 |
| `ACT_Labs_REX_BOM(1).csv` | BOM placa principal |
| `ACT_Labs_REX_POS(1).csv` | POS placa principal |
| `AutoFire_BOM(1).csv` | BOM AutoFire |
| `AutoFire_POS(1).csv` | POS AutoFire |

## Correcciones aplicadas

1. `START` queda en GPIO2.
2. `SELECT` queda en GPIO16.
3. El README y la documentacion de firmware fueron corregidos para reemplazar GPIO21/GPIO22.
4. La tabla de conectores usa `jp1_conector_puente.csv` como fuente de verdad para JP1.
5. Se documenta una inconsistencia detectada en `placa_2_autofire.csv`: algunos pines JP1 no coinciden con la tabla JP1. En conectores se normaliza usando JP1.

## Pendientes tecnicos

1. Subir fuentes KiCad completas si se requiere tener el proyecto 100% editable dentro del repositorio.
2. Generar Gerbers oficiales desde KiCad 10.
3. Validar footprints de switches SPDT antes de fabricar.
4. Medir timing PS1 con analizador logico.
5. Confirmar si el termistor de bateria PS Vita se deja aislado o se integra a una proteccion futura.
