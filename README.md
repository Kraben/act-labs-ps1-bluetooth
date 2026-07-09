# ACT Labs REX PS1 Replacement PCB

> Placa de repuesto open-source para el **ACT Labs REX Arcade Stick de PS1**.

```text
Status: Hardware V2 / KiCad actualizado
Firmware publico: PS1 Digital v1.1 OK
Firmware de apoyo: Hybrid AUTO PS1 / PS2 / BLE
BLE: operativo
Fabricacion: Gerbers pendientes de actualizar
Edicion: KiCad completo actualizado
```

## Project Dashboard

| Area | Estado | Alcance |
|---|---|---|
| Hardware | V2 / KiCad actualizado | Publico |
| Firmware PS1 | PS1 Digital v1.1 OK | Publico |
| Firmware binary | [`ActLabs_PS1_Digital_v1.1_OK.bin`](firmware/releases/PS1_Digital/v1.1/ActLabs_PS1_Digital_v1.1_OK.bin) | Publico |
| BLE HID | Operativo | Publico |
| AutoFire | Documentado | Publico |
| KiCad editable | Actualizado en `hardware/kicad/ACT_Labs_REX/` | Publico |
| Gerbers fabricacion | Pendientes de regenerar desde la revision KiCad actual | Publico |
| PS2 / DualShock | Listo en firmware Hybrid AUTO | Build de apoyo / donativos |
| PS1/PS2/BLE Hybrid | Listo en firmware Hybrid AUTO | Build de apoyo / donativos |

## Quick Links

| Recurso | Link |
|---|---|
| Sitio web | https://kraben.github.io/act-labs-ps1-bluetooth/ |
| Descargar firmware PS1 v1.1 | [`ActLabs_PS1_Digital_v1.1_OK.bin`](firmware/releases/PS1_Digital/v1.1/ActLabs_PS1_Digital_v1.1_OK.bin) |
| Firmware notes | [`docs/firmware.md`](docs/firmware.md) |
| Firmware Hybrid AUTO | [`docs/supporter-build.md`](docs/supporter-build.md) |
| Interfaz PS1 | [`docs/interfaces/ps1.md`](docs/interfaces/ps1.md) |
| Mapeo GPIO | [`docs/mapeo-gpio.md`](docs/mapeo-gpio.md) |
| Conectores | [`docs/conectores.md`](docs/conectores.md) |
| AutoFire | [`docs/autofire.md`](docs/autofire.md) |
| BOM | [`docs/bom.md`](docs/bom.md) |
| Fabricacion | [`docs/fabricacion.md`](docs/fabricacion.md) |
| KiCad editable | [`hardware/kicad/ACT_Labs_REX/`](hardware/kicad/ACT_Labs_REX/) |
| Gerbers | [`hardware/fabrication/gerbers/ACT_Labs_REX/`](hardware/fabrication/gerbers/ACT_Labs_REX/) |

## Resumen

El objetivo de este repositorio es conservar y documentar una alternativa de reemplazo para el control ACT Labs REX, ya que la pieza original ya no se fabrica ni se consigue facilmente.

El sistema usa un ESP32 DevKit V1 como controlador principal para reemplazar la electronica del ACT Labs REX Arcade Stick de PS1.

## Firmware publico PS1

La version publica actual del firmware es:

```text
ActLabs_PS1_Digital_v1.1_OK.bin
```

| Campo | Valor |
|---|---|
| Version | PS1 Digital v1.1 |
| Estado | OK |
| Target | ACT Labs REX PS1 Replacement PCB |
| Hardware | V2 / KiCad actualizado |
| Ruta | [`firmware/releases/PS1_Digital/v1.1/`](firmware/releases/PS1_Digital/v1.1/) |
| Archivo | [`ActLabs_PS1_Digital_v1.1_OK.bin`](firmware/releases/PS1_Digital/v1.1/ActLabs_PS1_Digital_v1.1_OK.bin) |
| SHA256 | `0a8994050381326bf345bf8123c105abefadabf30187247be9129a8c7f34b15c` |
| MD5 | `f61375d0dea1b9e42a6903105f5fba79` |

## Firmware Hybrid AUTO de apoyo

El firmware Hybrid AUTO es una build avanzada para ESP32 pensada como opcion de apoyo/donativos al proyecto.

| Funcion | Estado |
|---|---|
| PS1 cableado | Listo |
| PS2 / DualShock | Listo |
| Bluetooth BLE HID | Listo |
| Deteccion automatica PS1 / PS2 / BLE | Listo |

La documentacion publica se mantiene en [`docs/supporter-build.md`](docs/supporter-build.md). El codigo fuente completo del firmware Hybrid AUTO no se publica en este repositorio publico.

## Modos documentados

| Modo | Descripcion | Estado |
|---|---|---|
| PS1 cableado | ESP32 emula un control digital PS1 usando DATA, CMD, ATT, CLK y ACK. | Publico |
| Bluetooth HID | ESP32 funciona como gamepad BLE cuando se usa con bateria. | Publico |
| AutoFire | Placa secundaria con switches SPDT para activar turbo por boton. | Publico |
| Firmware Hybrid AUTO | PS1 / PS2 / BLE con deteccion automatica. | Build de apoyo / donativos |

## Estructura limpia

```text
.
├── docs/
│   ├── firmware.md
│   ├── supporter-build.md
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
    ├── ACT_Labs_Controller/
    └── releases/
        └── PS1_Digital/
            └── v1.1/
```

## Para fabricar vs para editar

| Uso | Carpeta | Contenido |
|---|---|---|
| Editar proyecto | [`hardware/kicad/ACT_Labs_REX/`](hardware/kicad/ACT_Labs_REX/) | Proyecto KiCad completo actualizado |
| Fabricar PCB | [`hardware/fabrication/gerbers/ACT_Labs_REX/`](hardware/fabrication/gerbers/ACT_Labs_REX/) | Gerbers pendientes de regenerar desde la revision KiCad actual |
| Firmware publico | [`firmware/releases/PS1_Digital/v1.1/`](firmware/releases/PS1_Digital/v1.1/) | Binario PS1 Digital v1.1 |
| Revisar PDFs | [`hardware/pdf/`](hardware/pdf/) | Esquematicos y PCB en PDF |
| Revisar datos | [`data/`](data/) | Mapeos, CSV y hojas de apoyo |

## Archivos de fabricacion actuales

> Nota: los Gerbers existentes pueden no corresponder todavia a la revision KiCad mas reciente. Regenerar y validar antes de fabricar.

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

## Apoyo / donativos

GitHub Pages puede funcionar como landing page del proyecto y enlazar a una plataforma externa para apoyo/donativos.

Opciones recomendadas:

| Opcion | Uso recomendado |
|---|---|
| GitHub Pages + PayPal/Mercado Pago | Catalogo simple y contacto directo |
| GitHub Pages + Gumroad/Payhip/Ko-fi | Entrega de builds de apoyo, firmware o archivos digitales |
| GitHub Pages + Stripe Payment Links | Botones de pago profesionales sin backend propio |
| GitHub Sponsors | Apoyo/donaciones recurrentes |

El repositorio publico mantiene hardware, documentacion y firmware PS1 disponible. La build Hybrid AUTO se maneja como opcion avanzada de apoyo para sostener el desarrollo.

## Proximos pasos

- [ ] Regenerar Gerbers desde la revision KiCad actual.
- [ ] Validar Gerbers nuevos contra visualizador antes de mandar a fabricar.
- [ ] Validar continuidad START/SELECT contra GND en PCB actualizada.
- [ ] Validar continuidad entre PCB principal, placa AutoFire y conectores JP.
- [ ] Revisar la ruta de alimentacion `BATT_FROM_TP`, TP4056, LD1117-3.3 y diodos SS14.
- [ ] Validar el firmware PS1 actualizado contra hardware fisico.
- [ ] Confirmar pull-ups reales contra la PCB antes de fabricar.
- [ ] Preparar binario, checksums y guia de flasheo para la build Hybrid AUTO de apoyo.
