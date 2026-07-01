# ACT Labs REX Gerbers

Gerbers exportados desde KiCad para **ACT Labs REX PCB V2.2**.

## Uso

Esta carpeta es para fabricacion de PCB.

Para editar el proyecto usar:

```text
hardware/kicad/ACT_Labs_REX/
```

## Archivos esperados

| Archivo | Funcion |
|---|---|
| ACT_Labs_REX-F_Cu.gbr | Cobre superior |
| ACT_Labs_REX-B_Cu.gbr | Cobre inferior |
| ACT_Labs_REX-F_Mask.gbr | Mascara superior |
| ACT_Labs_REX-B_Mask.gbr | Mascara inferior |
| ACT_Labs_REX-F_Paste.gbr | Pasta superior |
| ACT_Labs_REX-B_Paste.gbr | Pasta inferior |
| ACT_Labs_REX-F_Silkscreen.gbr | Serigrafia superior |
| ACT_Labs_REX-B_Silkscreen.gbr | Serigrafia inferior |
| ACT_Labs_REX-Edge_Cuts.gbr | Contorno PCB |
| ACT_Labs_REX-PTH.drl | Taladros metalizados |
| ACT_Labs_REX-NPTH.drl | Taladros no metalizados |
| ACT_Labs_REX-job.gbrjob | Job file de fabricacion |

## Datos del job file

- Generado por KiCad / Pcbnew 10.0.3.
- Revision del proyecto: 2.2.
- Capas: 2.
- Grosor: 1.6 mm.
- Tamano reportado: 138.9318 mm x 120.15 mm.

## Checklist antes de fabricar

- [ ] Abrir `ACT_Labs_REX-job.gbrjob` o el ZIP de gerbers en un visor Gerber.
- [ ] Confirmar contorno `Edge_Cuts`.
- [ ] Confirmar taladros PTH y NPTH.
- [ ] Confirmar orientacion de silkscreen.
- [ ] Confirmar que los archivos son de la revision correcta.
- [ ] Confirmar corto START/SELECT antes de ordenar nueva fabricacion.
