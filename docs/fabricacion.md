# Fabricación V2

Archivos KiCad actualizados para la revisión V2. Los Gerbers quedan pendientes de regenerar desde la revisión KiCad actual antes de enviar a fabricación.

## Estado actual

| Área | Estado |
|---|---|
| KiCad principal | Actualizado en `hardware/kicad/ACT_Labs_REX/` |
| Gerbers principal | Pendientes de regenerar |
| BOM/POS | Revalidar después de regenerar Gerbers |
| Firmware PS1 | PS1 Digital v1.1 OK |

## Archivos CSV

| Archivo | Descripción |
|---|---|
| `hardware/fabrication/ACT_Labs_REX_BOM.csv` | Lista de materiales de la placa principal |
| `hardware/fabrication/ACT_Labs_REX_POS.csv` | Posiciones de componentes de la placa principal |
| `hardware/fabrication/AutoFire_BOM.csv` | Lista de materiales de la placa AutoFire |
| `hardware/fabrication/AutoFire_POS.csv` | Posiciones de componentes de la placa AutoFire |

## Resumen de placa principal `ACT_Labs_REX`

- Componentes relevantes: ESP32 DevKit V1, LD1117S33TR, TP4056 pads, SS14, LED, switches SPDT, START/SELECT Omron, conectores JP y PS1.
- START/SELECT deben validarse por continuidad: señal abierta sin presionar y continuidad a GND al presionar.
- El pinout PS1 debe mantenerse alineado con el firmware usado en pruebas.

## Resumen de placa AutoFire

- Componentes: 10 switches SPDT, LED, resistencia 220Ω y conector 1x13.
- Validar continuidad entre placa principal, placa AutoFire y conectores JP antes de energizar.

## Checklist antes de fabricar

1. Abrir `ACT_Labs_REX.kicad_pcb` y `AutoFire.kicad_pcb` en KiCad 10.
2. Ejecutar DRC y corregir warnings críticos.
3. Confirmar orientación de `D1`, `D3`, `U2`, `C1`, `C3` y `C4`.
4. Validar START/SELECT con multímetro: abierto sin presionar y continuidad a GND al presionar.
5. Revisar footprints `Button_Switch_THT:Untitled_1` de los SPDT de la placa principal.
6. Revisar el footprint `SW_CK_JS202011CQN_DPDT_Straight` en AutoFire.
7. Regenerar Gerbers, BOM y POS desde la misma revisión antes de enviar a fabricación.
8. Confirmar que las unidades del POS sean compatibles con el ensamblador.
9. Abrir Gerbers nuevos en visualizador externo antes de ordenar PCB.

## Observaciones

- La placa principal mezcla componentes top y bottom; esto puede afectar ensamble manual o pick-and-place.
- La placa AutoFire es más simple: todos los componentes están en top.
- La documentación de BOM en `docs/bom.md` está resumida; los CSV son la fuente exacta para fabricación.
- Los Gerbers existentes pueden estar desfasados frente a los archivos KiCad actuales hasta que se suba la nueva exportación.
