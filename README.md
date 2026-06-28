# KrabenStick ESP32

Plataforma open-source para arcade sticks y controles personalizados basados en ESP32.

Este proyecto comenzó como una conversión de tablero ACT-LABS / PS1 a control híbrido PS1-Bluetooth, pero la marca queda preparada para crecer hacia una plataforma más amplia: modo PS1 cableado, Bluetooth HID, AutoFire y futuras variantes multi-consola.

> Estado actual: Hardware V2 / PCB V2.2, BLE operativo y protocolo PS1 en depuración de ACK/DATA.

## Sitio del proyecto

La landing page inicial está en:

[`docs/index.html`](docs/index.html)

Cuando GitHub Pages esté activo desde la carpeta `docs/`, el sitio se podrá publicar como:

```text
https://kraben.github.io/act-labs-ps1-bluetooth/
```

Si más adelante se cambia el nombre del repositorio, GitHub redirige automáticamente la URL anterior, pero conviene actualizar los enlaces internos.

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
│       ├── architecture.md
│       ├── ps1.md
│       ├── snes.md
│       ├── genesis.md
│       ├── n64.md
│       └── gamecube.md
├── hardware/
│   ├── README.md
│   ├── fabrication/
│   │   ├── ACT_Labs_REX_BOM_summary.csv
│   │   ├── ACT_Labs_REX_POS_summary.csv
│   │   ├── autofire_bom_summary.txt
│   │   └── autofire_pos_summary.txt
│   ├── kicad/
│   │   └── SOURCES.md
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

El sistema usa un ESP32 DevKit V1 como controlador principal. El mismo hardware debe poder funcionar en tres escenarios:

1. **Modo PS1/PS2 cableado**: el ESP32 emula un control digital PS1 usando DATA, CMD, ATT, CLK y ACK.
2. **Modo Bluetooth HID**: el ESP32 funciona como gamepad BLE cuando se usa con batería.
3. **AutoFire**: una placa secundaria con switches SPDT permite activar turbo por botón y controlar el encendido desde batería.

## Estado técnico V2

| Área | Estado |
|---|---|
| Hardware | V2 / PCB V2.2 |
| KiCad | Archivos generados en KiCad 10 |
| BLE | Operativo |
| PS1 | En depuración de ACK/DATA |
| Alimentación | TP4056 externo, batería PS Vita 3.7 V, LD1117-3.3 y diodo Schottky |

## Interfaces de consola

La documentación de protocolos queda separada en `docs/interfaces/` para permitir futuras salidas cableadas sin mezclar PS1 con otros protocolos.

| Interfaz | Archivo | Estado |
|---|---|---|
| Arquitectura común | [`docs/interfaces/architecture.md`](docs/interfaces/architecture.md) | Base común |
| PS1 | [`docs/interfaces/ps1.md`](docs/interfaces/ps1.md) | En depuración ACK/DATA |
| SNES | [`docs/interfaces/snes.md`](docs/interfaces/snes.md) | Futuro |
| Genesis / Mega Drive | [`docs/interfaces/genesis.md`](docs/interfaces/genesis.md) | Futuro |
| Nintendo 64 | [`docs/interfaces/n64.md`](docs/interfaces/n64.md) | Futuro |
| GameCube | [`docs/interfaces/gamecube.md`](docs/interfaces/gamecube.md) | Futuro |

## Referencias rápidas

- Esquemático principal PDF: [`hardware/pdf/ACT_Labs_REX.pdf`](hardware/pdf/ACT_Labs_REX.pdf)
- PCB principal PDF: [`hardware/pdf/ArcLabsPCB.pdf`](hardware/pdf/ArcLabsPCB.pdf)
- Esquemático AutoFire PDF: [`hardware/pdf/AutoFire.pdf`](hardware/pdf/AutoFire.pdf)
- PCB AutoFire PDF: [`hardware/pdf/AutoFirePCB.pdf`](hardware/pdf/AutoFirePCB.pdf)
- BOM/POS de fabricación: [`hardware/fabrication/`](hardware/fabrication/)
- Inventario de fuentes KiCad recibidas: [`hardware/kicad/SOURCES.md`](hardware/kicad/SOURCES.md)
- Mapeo completo: [`data/ACT_Labs_Mapeo_Consolidado.xlsx`](data/ACT_Labs_Mapeo_Consolidado.xlsx)

## Pines principales V2

| Señal | GPIO |
|---|---:|
| DATA | 19 |
| CMD | 23 |
| ATT | 5 |
| CLK | 18 |
| ACK | 4 |
| START | 2 |
| SELECT | 16 |
| AF_MODE | 15 |

## Próximos pasos

1. Validar continuidad entre PCB principal, placa AutoFire y conectores JP.
2. Revisar la ruta de alimentación `BATT_FROM_TP`, TP4056, LD1117-3.3 y D1.
3. Depurar ACK/DATA del protocolo PS1 con analizador lógico.
4. Confirmar pull-ups reales contra la PCB antes de fabricar.
5. Mantener BOM/POS exportados desde KiCad antes de fabricar.
6. Activar GitHub Pages desde `Settings > Pages > Deploy from branch > main / docs`.
