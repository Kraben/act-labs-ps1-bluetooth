# Hardware

Esta carpeta contiene referencias de hardware, PDFs, imágenes, exportaciones de fabricación e inventario de fuentes KiCad del proyecto ACT Labs PS1 Bluetooth / AutoFire.

## PDFs

- `pdf/ACT_Labs_REX.pdf`: esquemático principal de conversión de tablero PS1.
- `pdf/ArcLabsPCB.pdf`: vista de PCB principal.
- `pdf/AutoFire.pdf`: esquemático de la placa AutoFire.
- `pdf/AutoFirePCB.pdf`: vista de PCB AutoFire.

## Imágenes

- `images/Led-Switch.png`: detalle de LED / switch de encendido.
- `images/Partcial_SCHM.png`: captura parcial del esquemático principal.
- `images/SW_part.png`: captura de la placa de switches AutoFire.

## Fabricación

Archivos de resumen derivados de las exportaciones KiCad recibidas:

- `fabrication/ACT_Labs_REX_BOM_summary.csv`: BOM resumido de placa principal.
- `fabrication/ACT_Labs_REX_POS_summary.csv`: posiciones resumidas de placa principal.
- `fabrication/autofire_bom_summary.txt`: BOM resumido de placa AutoFire.
- `fabrication/autofire_pos_summary.txt`: posiciones resumidas de placa AutoFire.

Resumen de exportaciones recibidas:

| Placa | BOM | POS | Componentes |
|---|---:|---:|---:|
| ACT_Labs_REX | 35 líneas | 40 líneas | 27 top / 13 bottom |
| AutoFire | 13 líneas | 13 líneas | 13 top |

## Fuentes KiCad

El inventario de fuentes KiCad recibidas y sus hashes está en `kicad/SOURCES.md`.

## Validaciones recomendadas

- Verificar continuidad de GND entre placas.
- Confirmar orientación de D1/D3 Schottky.
- Confirmar que `BATT_FROM_TP` entra a la ruta de alimentación correcta y no directamente a `3V3`.
- Confirmar pull-ups de DATA/ACK a 4.7 kΩ según BOM V2.
- Antes de fabricar, regenerar BOM/POS desde la misma revisión de KiCad que se use para Gerbers.
