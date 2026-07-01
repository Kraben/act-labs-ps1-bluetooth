# ACT Labs REX PS1 Replacement PCB

Placa de repuesto open-source para el **ACT Labs REX Arcade Stick de PS1**.

El objetivo de este repositorio es conservar y documentar una alternativa de reemplazo para el control ACT Labs REX, ya que la pieza original ya no se fabrica ni se consigue facilmente. Este proyecto se mantiene publico como referencia de reparacion, fabricacion y preservacion del hardware.

> Estado actual: Hardware V2 / PCB V2.2, Firmware PS1 actualizado, BLE operativo. El protocolo PS2 y el firmware hibrido PS1/PS2/BLE estan listos, pero no se publicaran en este repositorio abierto; quedaran reservados para una version privada/paywall.

## Sitio del proyecto

La landing page inicial esta en:

[`docs/index.html`](docs/index.html)

Sitio  Web:

```text
https://kraben.github.io/act-labs-ps1-bluetooth/
```

## Contenido del repositorio

```text
.
├── README.md
├── docs/
│   ├── index.html
│   ├── site.css
│   ├── arquitectura.md
│   ├── mapeo-gpio.md
│   ├── conectores.md
│   ├── autofire.md
│   ├── firmware.md
│   ├── bom.md
│   ├── fabricacion.md
│   ├── revision-v2.md
│   └── interfaces/
│       └── ps1.md
├── hardware/
│   ├── README.md
│   ├── fabrication/
│   │   ├── ACT_Labs_REX_BOM_summary.csv
│   │   ├── ACT_Labs_REX_POS_summary.csv
│   │   ├── autofire_bom_summary.txt
│   │   └── autofire_pos_summary.txt
│   ├── kicad/
│   │   ├── SOURCES.md
│   │   ├── ACT_Labs_REX/
│   │   └── AutoFire/
│   ├── pdf/
│   │   ├── ACT_Labs_REX.pdf
│   │   ├── ArcLabsPCB.pdf
│   │   ├── AutoFire.pdf
│   │   └── AutoFirePCB.pdf
│   └── images/
│       ├── Led-Switch.png
│       ├── Partcial_SCHM.png
│       └── SW_part.png
├── data/
│   ├── ACT_Labs_Consolidado_Final.xlsx
│   ├── ACT_Labs_Mapeo_Consolidado.xlsx
│   ├── gpio_mapping.csv
│   ├── placa_2_autofire.csv
│   ├── jp1_conector_puente.csv
│   └── firmware_resumen.md
└── firmware/
    └── ACT_Labs_Controller/
        └── ACT_Labs_Controller.ino
```

## Resumen del proyecto

El sistema usa un ESP32 DevKit V1 como controlador principal para reemplazar la electronica del ACT Labs REX Arcade Stick de PS1.

Escenarios documentados en este repositorio:

1. **Modo PS1 cableado**: el ESP32 emula un control digital PS1 usando DATA, CMD, ATT, CLK y ACK.
2. **Modo Bluetooth HID**: el ESP32 funciona como gamepad BLE cuando se usa con bateria.
3. **AutoFire**: una placa secundaria con switches SPDT permite activar turbo por boton y controlar el encendido desde bateria.
4. **Firmware hibrido PS1/PS2/BLE**: listo a nivel de desarrollo, pero reservado para distribucion privada/paywall. No forma parte del alcance publico de este repositorio.

> Nota: el soporte PS2 y el firmware hibrido PS1/PS2/BLE no se publican aqui. Este repositorio publico queda enfocado en la documentacion de la placa de repuesto ACT Labs REX y el firmware PS1 disponible.

## Alcance

Este repositorio queda limitado al ACT Labs REX / PS1 publico. Las funciones avanzadas PS2 e hibridas PS1/PS2/BLE se manejaran como trabajo privado/paywall separado.

## Estado tecnico V2

| Area | Estado |
|---|---|
| Hardware | V2 / PCB V2.2 |
| KiCad | Archivos generados en KiCad 10 |
| Firmware PS1 | Actualizado manualmente en el repositorio |
| BLE | Operativo |
| Protocolo PS2 | Listo, reservado para version privada/paywall |
| Firmware hibrido PS1/PS2/BLE | Listo, no publicado en este repositorio publico |
| Alimentacion | TP4056 externo, bateria PS Vita 3.7 V, LD1117-3.3 y diodo Schottky |

## Referencias rapidas

- Esquematico principal PDF: [`hardware/pdf/ACT_Labs_REX.pdf`](hardware/pdf/ACT_Labs_REX.pdf)
- PCB principal PDF: [`hardware/pdf/ArcLabsPCB.pdf`](hardware/pdf/ArcLabsPCB.pdf)
- Esquematico AutoFire PDF: [`hardware/pdf/AutoFire.pdf`](hardware/pdf/AutoFire.pdf)
- PCB AutoFire PDF: [`hardware/pdf/AutoFirePCB.pdf`](hardware/pdf/AutoFirePCB.pdf)
- BOM/POS de fabricacion: [`hardware/fabrication/`](hardware/fabrication/)
- Inventario de fuentes KiCad recibidas: [`hardware/kicad/SOURCES.md`](hardware/kicad/SOURCES.md)
- Mapeo completo: [`data/ACT_Labs_Consolidado_Final.xlsx`](data/ACT_Labs_Consolidado_Final.xlsx)
- Interfaz PS1: [`docs/interfaces/ps1.md`](docs/interfaces/ps1.md)

## Pines principales V2

| Senal | GPIO |
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

1. Corregir el corto START/SELECT reportado en issues antes de una nueva fabricacion.
2. Validar continuidad entre PCB principal, placa AutoFire y conectores JP.
3. Revisar la ruta de alimentacion `BATT_FROM_TP`, TP4056, LD1117-3.3 y D1.
4. Validar el firmware PS1 actualizado contra hardware fisico.
5. Confirmar pull-ups reales contra la PCB antes de fabricar.
6. Mantener BOM/POS exportados desde KiCad antes de fabricar.
