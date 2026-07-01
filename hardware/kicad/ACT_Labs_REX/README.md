# ACT Labs REX KiCad Sources

Fuentes editables de KiCad para **ACT Labs REX PCB V2.2**.

## Uso

Esta carpeta es para editar el proyecto en KiCad.

Para fabricar usar los Gerbers exportados en:

```text
hardware/fabrication/gerbers/ACT_Labs_REX/
```

## Archivos principales

| Archivo | Proposito |
|---|---|
| ACT_Labs_REX.kicad_pro | Proyecto KiCad |
| ACT_Labs_REX.kicad_sch | Esquematico principal |
| ACT_Labs_REX.kicad_pcb | PCB principal |
| Placa_2.kicad_sch | Esquematico de placa secundaria / AutoFire |

## Reglas

- Mantener aqui solo fuentes editables de KiCad.
- No mezclar Gerbers ni salidas de fabricacion en esta carpeta.
- No subir backups, autosaves ni archivos temporales.
- Exportar salidas de fabricacion hacia `hardware/fabrication/gerbers/ACT_Labs_REX/`.
