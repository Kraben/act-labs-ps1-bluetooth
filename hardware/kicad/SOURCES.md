# Fuentes KiCad V2

Inventario de archivos recibidos para trazabilidad de la revision V2 / PCB V2.2.

## Estructura actual

```text
hardware/kicad/
├── ACT_Labs_REX/
│   ├── ACT_Labs_REX.kicad_pro
│   ├── ACT_Labs_REX.kicad_sch
│   ├── ACT_Labs_REX.kicad_pcb
│   └── Placa_2.kicad_sch
└── SOURCES.md
```

## Fabricacion

Los Gerbers actuales estan separados de las fuentes editables:

```text
hardware/fabrication/gerbers/ACT_Labs_REX/
├── ACT_Labs_REX-F_Cu.gbr
├── ACT_Labs_REX-B_Cu.gbr
├── ACT_Labs_REX-F_Mask.gbr
├── ACT_Labs_REX-B_Mask.gbr
├── ACT_Labs_REX-F_Paste.gbr
├── ACT_Labs_REX-B_Paste.gbr
├── ACT_Labs_REX-F_Silkscreen.gbr
├── ACT_Labs_REX-B_Silkscreen.gbr
├── ACT_Labs_REX-Edge_Cuts.gbr
├── ACT_Labs_REX-PTH.drl
├── ACT_Labs_REX-NPTH.drl
└── ACT_Labs_REX-job.gbrjob
```

## Regla de limpieza

- Para editar: usar `hardware/kicad/ACT_Labs_REX/`.
- Para fabricar: usar `hardware/fabrication/gerbers/ACT_Labs_REX/`.
- No mezclar archivos Gerber dentro de KiCad.
- No mezclar fuentes KiCad dentro de fabricacion.
- No subir backups, autosaves o temporales de KiCad.

## Nota

Los CSV de resumen de BOM/POS de esta revision permanecen en `hardware/fabrication/`.
