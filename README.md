# ACT Labs REX PS1 Replacement PCB

> Placa de repuesto open-source para el **ACT Labs REX Arcade Stick de PS1**.

```text
Status: Hardware V2 / PCB V2.2
Firmware: PS1 actualizado
BLE: operativo
PS2 / Hybrid: listo, reservado para distribucion privada
Fabricacion: Gerbers actualizados
Edicion: KiCad completo actualizado
```

## Project Dashboard

| Area | Estado | Alcance |
|---|---|---|
| Hardware | V2 / PCB V2.2 | Publico |
| Firmware PS1 | Actualizado manualmente | Publico |
| BLE HID | Operativo | Publico |
| AutoFire | Documentado | Publico |
| KiCad editable | Actualizado en `hardware/kicad/ACT_Labs_REX/` | Publico |
| Gerbers fabricacion | Actualizados en `hardware/fabrication/gerbers/ACT_Labs_REX/` | Publico |
| PS2 / DualShock | Listo | Reservado |
| PS1/PS2/BLE Hybrid | Listo | Reservado |

## Quick Links

| Recurso | Link |
|---|---|
| Sitio web | https://kraben.github.io/act-labs-ps1-bluetooth/ |
| Firmware | [`docs/firmware.md`](docs/firmware.md) |
| Interfaz PS1 | [`docs/interfaces/ps1.md`](docs/interfaces/ps1.md) |
| Mapeo GPIO | [`docs/mapeo-gpio.md`](docs/mapeo-gpio.md) |
| Conectores | [`docs/conectores.md`](docs/conectores.md) |
| AutoFire | [`docs/autofire.md`](docs/autofire.md) |
| BOM | [`docs/bom.md`](docs/bom.md) |
| Fabricacion | [`docs/fabricacion.md`](docs/fabricacion.md) |
| KiCad editable | [`hardware/kicad/ACT_Labs_REX/`](hardware/kicad/ACT_Labs_REX/) |
| Gerbers listos para fabricar | [`hardware/fabrication/gerbers/ACT_Labs_REX/`](hardware/fabrication/gerbers/ACT_Labs_REX/) |

## Resumen

El objetivo de este repositorio es conservar y documentar una alternativa de reemplazo para el control ACT Labs REX, ya que la pieza original ya no se fabrica ni se consigue facilmente.

El sistema usa un ESP32 DevKit V1 como controlador principal para reemplazar la electronica del ACT Labs REX Arcade Stick de PS1.

## Modos documentados

| Modo | Descripcion | Estado |
|---|---|---|
| PS1 cableado | ESP32 emula un control digital PS1 usando DATA, CMD, ATT, CLK y ACK. | Publico |
| Bluetooth HID | ESP32 funciona como gamepad BLE cuando se usa con bateria. | Publico |
| AutoFire | Placa secundaria con switches SPDT para activar turbo por boton. | Publico |
| Firmware hibrido | PS1/PS2/BLE | Reservado |

## Estructura limpia

```text
.
├── docs/
│   ├── firmware.md
│   ├── mapeo-gpio.md
│   ├── conectores.md
│   ├── autofire.md
│   └── interfaces/ps1.md
├── hardware/
│   ├── fabrication/
│   │   └── gerbers/
│   │       └── ACT_Labs_REX/
│   ├── kicad/
│   │   └── ACT_Labs_REX/
│   ├── pdf/
│   └── images/
├── data/
└── firmware/
    └── ACT_Labs_Controller/
```

## Para fabricar vs para editar

| Uso | Carpeta | Contenido |
|---|---|---|
| Fabricar PCB | [`hardware/fabrication/gerbers/ACT_Labs_REX/`](hardware/fabrication/gerbers/ACT_Labs_REX/) | Gerbers, drills y job file exportados desde KiCad |
| Editar proyecto | [`hardware/kicad/ACT_Labs_REX/`](hardware/kicad/ACT_Labs_REX/) | Proyecto KiCad completo |
| Revisar PDFs | [`hardware/pdf/`](hardware/pdf/) | Esquematicos y PCB en PDF |
| Revisar datos | [`data/`](data/) | Mapeos, CSV y hojas de apoyo |

## Archivos de fabricacion actuales

| Archivo | Proposito |
|---|---|
| `ACT_Labs_REX-F_Cu.gbr` | Cobre superior |
| `ACT_Labs_REX-B_Cu.gbr` | Cobre inferior |
| `ACT_Labs_REX-F_Mask.gbr` | Mascara superior |
| `ACT_Labs_REX-B_Mask.gbr` | Mascara inferior |
| `ACT_Labs_REX-F_Silkscreen.gbr` | Serigrafia superior |
| `ACT_Labs_REX-B_Silkscreen.gbr` | Serigrafia inferior |
| `ACT_Labs_REX-Edge_Cuts.gbr` | Contorno de PCB |
| `ACT_Labs_REX-PTH.drl` | Taladros metalizados |
| `ACT_Labs_REX-NPTH.drl` | Taladros no metalizados |
| `ACT_Labs_REX-job.gbrjob` | Job file de fabricacion |

## Referencias de hardware

| Archivo | Descripcion |
|---|---|
| [`hardware/pdf/ACT_Labs_REX.pdf`](hardware/pdf/ACT_Labs_REX.pdf) | Esquematico principal |
| [`hardware/pdf/ArcLabsPCB.pdf`](hardware/pdf/ArcLabsPCB.pdf) | PCB principal |
| [`hardware/pdf/AutoFire.pdf`](hardware/pdf/AutoFire.pdf) | Esquematico AutoFire |
| [`hardware/pdf/AutoFirePCB.pdf`](hardware/pdf/AutoFirePCB.pdf) | PCB AutoFire |
| [`hardware/fabrication/`](hardware/fabrication/) | BOM/POS de fabricacion |

## Pines principales V2

| Signal | GPIO |
|---|---:|
| DATA | 19 |
| CMD | 23 |
| ATT | 5 |
| CLK | 18 |
| ACK | 4 |
| START | 2 |
| SELECT | 16 |
| AF_MODE | 15 |

## Proximos pasos

- [ ] Validar Gerbers actuales contra visualizador antes de mandar a fabricar.
- [ ] Corregir el corto START/SELECT reportado en issues antes de una nueva fabricacion.
- [ ] Validar continuidad entre PCB principal, placa AutoFire y conectores JP.
- [ ] Revisar la ruta de alimentacion `BATT_FROM_TP`, TP4056, LD1117-3.3 y D1.
- [ ] Validar el firmware PS1 actualizado contra hardware fisico.
- [ ] Confirmar pull-ups reales contra la PCB antes de fabricar.
