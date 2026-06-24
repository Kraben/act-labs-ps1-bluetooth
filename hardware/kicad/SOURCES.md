# Fuentes KiCad V2

Inventario de archivos recibidos para trazabilidad de la revisión V2 / PCB V2.2.

## Archivos recibidos

| Archivo | Bytes | SHA256 |
|---|---:|---|
| ACT_Labs_REX.kicad_pcb | 1077802 | 9e2dee5f9d20576253f815f274f827786ae155082c45b2e61ebab2c90d580dbb |
| ACT_Labs_REX.kicad_sch | 140595 | cbbf6ab59c1ef10905bf332f8b632167d06a5799f867cf0396ddaceecc035f1b |
| ACT_Labs_REX.net | 93482 | a2cc43107be7ec56e30666676d8f02687f65585a081504177cd3fbcda0b50611 |
| AutoFire.kicad_pcb | 205180 | fed2ef273afd07f11b39debccfa5cb39b0eea102a0940360c01642623262bb13 |
| AutoFire.kicad_sch | 44867 | 076f4aa571fa985e580660d043fa08aa503b9e768ba8ae257b54ab976092572d |
| ACT_Labs_Mapeo_Consolidado(1).xlsx | 16856 | 3c96af38866a6591e5eb635b42c46d105f2fcd4d5158f589564a57f2cac543fe |

## Estructura recomendada

```text
hardware/kicad/
├── ACT_Labs_REX/
│   ├── ACT_Labs_REX.kicad_sch
│   ├── ACT_Labs_REX.kicad_pcb
│   └── ACT_Labs_REX.net
└── AutoFire/
    ├── AutoFire.kicad_sch
    └── AutoFire.kicad_pcb
```

Los CSV de BOM/POS de esta revisión están en `hardware/fabrication/`.
