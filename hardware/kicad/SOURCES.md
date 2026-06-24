# Fuentes KiCad V2

Inventario de archivos recibidos para trazabilidad de la revision V2 / PCB V2.2.

## Archivos KiCad recibidos

| Archivo | Bytes | SHA256 |
|---|---:|---|
| ACT_Labs_REX.kicad_pcb | 1077802 | 9e2dee5f9d20576253f815f274f827786ae155082c45b2e61ebab2c90d580dbb |
| ACT_Labs_REX.kicad_sch | 140595 | cbbf6ab59c1ef10905bf332f8b632167d06a5799f867cf0396ddaceecc035f1b |
| ACT_Labs_REX.net | 93482 | a2cc43107be7ec56e30666676d8f02687f65585a081504177cd3fbcda0b50611 |
| AutoFire.kicad_pcb | 205180 | fed2ef273afd07f11b39debccfa5cb39b0eea102a0940360c01642623262bb13 |
| AutoFire.kicad_sch | 44867 | 076f4aa571fa985e580660d043fa08aa503b9e768ba8ae257b54ab976092572d |

## Mapeo consolidado y CSV revisados

| Archivo | Bytes | SHA256 |
|---|---:|---|
| ACT_Labs_Mapeo_Consolidado(2).xlsx | 16856 | 3c96af38866a6591e5eb635b42c46d105f2fcd4d5158f589564a57f2cac543fe |
| gpio_mapping.csv | 1761 | e055b07897dd13118b223c42b29c657dfca38a54b6c3c11bb8d9f8c7cdcc401f |
| jp1_conector_puente.csv | 708 | 27429b06b6e37a4e347388ee4c4af7f5ef9d1fb7701b236b14066dd0a31979f1 |
| placa_2_autofire.csv | 820 | ba22abff1ca073972f87e695768424c50a018982d3d83bc2d325794f89aa7b11 |
| firmware_resumen.md | 937 | 0ce762d3199177ca94abaf4152a156ea20e3d9ae4d0805f59e05ee30b15f7b8f |

## Fabricacion revisada

| Archivo | Bytes | SHA256 |
|---|---:|---|
| ACT_Labs_REX_BOM(1).csv | 2761 | 9e0abb5201df1ab69832e627a1422a263def52102ac8c18f6b71d9408ae592a2 |
| ACT_Labs_REX_POS(1).csv | 3272 | 6378c1d96887a96fe68c71c632788e0f0171a2f81002fdb36f3a95f5ac6d5f05 |
| AutoFire_BOM(1).csv | 1015 | e04aec58df331842261329a50e6b3360431fafd2b8f35df1bc9e564960cf3a0c |
| AutoFire_POS(1).csv | 892 | cdc9400ff9561c061b5b081abc9a33fd7ef7e795ec37718b527ce35bfd1d2323 |

## Estructura recomendada para fuentes completas

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

Los CSV de resumen de BOM/POS de esta revision estan en `hardware/fabrication/`.
