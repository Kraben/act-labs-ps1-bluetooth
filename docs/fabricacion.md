# Fabricación V2

Archivos de fabricación recibidos y documentados para la revisión V2 / PCB V2.2.

## Archivos CSV

| Archivo | Descripción |
|---|---|
| `hardware/fabrication/ACT_Labs_REX_BOM.csv` | Lista de materiales de la placa principal |
| `hardware/fabrication/ACT_Labs_REX_POS.csv` | Posiciones de componentes de la placa principal |
| `hardware/fabrication/AutoFire_BOM.csv` | Lista de materiales de la placa AutoFire |
| `hardware/fabrication/AutoFire_POS.csv` | Posiciones de componentes de la placa AutoFire |

## Resumen de placa principal `ACT_Labs_REX`

- BOM: 35 líneas de componentes.
- POS: 40 componentes colocados.
- Distribución POS: 27 componentes en top y 13 en bottom.
- Componentes relevantes: ESP32 DevKit V1, LD1117S33TR, TP4056 pads, SS14, LED, switches SPDT, START/SELECT Omron, conectores JP y PS1.

## Resumen de placa AutoFire

- BOM: 13 líneas de componentes.
- POS: 13 componentes colocados.
- Distribución POS: todos los componentes están en top.
- Componentes: 10 switches SPDT, LED, resistencia 220Ω y conector 1x13.

## Checklist antes de fabricar

1. Abrir `ACT_Labs_REX.kicad_pcb` y `AutoFire.kicad_pcb` en KiCad 10.
2. Ejecutar DRC y corregir warnings críticos.
3. Confirmar orientación de `D1`, `D3`, `U2`, `C1`, `C3` y `C4`.
4. Revisar footprints `Button_Switch_THT:Untitled_1` de los SPDT de la placa principal.
5. Revisar el footprint `SW_CK_JS202011CQN_DPDT_Straight` en AutoFire.
6. Regenerar Gerbers, BOM y POS desde la misma revisión antes de enviar a fabricación.
7. Confirmar que las unidades del POS sean compatibles con el ensamblador.

## Observaciones

- La placa principal mezcla componentes top y bottom; esto puede afectar ensamble manual o pick-and-place.
- La placa AutoFire es más simple: todos los componentes están en top.
- La documentación de BOM en `docs/bom.md` está resumida; los CSV son la fuente exacta para fabricación.
