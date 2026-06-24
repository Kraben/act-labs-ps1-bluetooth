# Revisión V2 / PCB V2.2

## Estado recibido

- Proyecto principal: `ACT_Labs_REX`
- Título PCB principal: `CONVERSION PLACA ARCADE PS1-BLUETOOTH`
- Revisión PCB principal: `2.2`
- KiCad: 10.0
- BLE: operativo
- PS1: en depuración de `ACK` / `DATA`

## Cambios incorporados a documentación

| Área | Ajuste |
|---|---|
| Arquitectura | Se documenta ESP32 DevKit V1, TP4056 externo, batería PS Vita 3.7 V, LD1117-3.3 y Schottky |
| BOM | Se actualiza desde CSV KiCad V2 |
| Conectores | Se agrega TP4056, batería PS Vita, J1–J6 y AutoFire |
| Firmware | Se documentan pines V2 y plan de depuración PS1 |
| Mapeo GPIO | Se actualizan DATA/CMD/ATT/CLK/ACK, START, SELECT y AF_MODE |
| Fabricación | Se agregan BOM/POS de placa principal y AutoFire |

## Valores importantes V2

| Señal / componente | Valor / GPIO |
|---|---|
| DATA | GPIO19 |
| CMD | GPIO23 |
| ATT | GPIO5 |
| CLK | GPIO18 |
| ACK | GPIO4 |
| START | GPIO21 |
| SELECT | GPIO22 |
| AF_MODE | GPIO15 |
| R6/R7 | 4.7 kΩ |
| Regulador | LD1117S33TR_SOT223 |
| Schottky | SS14 / 1N5817 |

## Archivos recibidos

| Archivo | Uso |
|---|---|
| `ACT_Labs_REX.kicad_sch` | Esquemático principal KiCad |
| `ACT_Labs_REX.kicad_pcb` | PCB principal KiCad |
| `ACT_Labs_REX.net` | Netlist principal |
| `AutoFire.kicad_sch` | Esquemático AutoFire |
| `AutoFire.kicad_pcb` | PCB AutoFire |
| `ACT_Labs_REX_BOM.csv` | BOM placa principal |
| `ACT_Labs_REX_POS.csv` | POS placa principal |
| `AutoFire_BOM.csv` | BOM AutoFire |
| `AutoFire_POS.csv` | POS AutoFire |
| `ACT_Labs_Mapeo_Consolidado(1).xlsx` | Mapeo consolidado actualizado |

## Pendientes técnicos

1. Subir fuentes KiCad completas si se requiere tener el proyecto 100% editable dentro del repositorio.
2. Generar Gerbers oficiales desde KiCad 10.
3. Validar footprints de switches SPDT antes de fabricar.
4. Medir timing PS1 con analizador lógico.
5. Confirmar si el termistor de batería PS Vita se deja aislado o se integra a una protección futura.
