# Firmware Hybrid AUTO - Build de apoyo

## Resumen

La build **Hybrid AUTO** es una version avanzada del firmware para ESP32 DevKit V1 orientada a usuarios que quieran apoyar el desarrollo del proyecto.

Esta build agrega deteccion automatica y soporte para:

- PS1 cableado.
- PS2 / DualShock cableado.
- Bluetooth BLE HID.
- AutoFire / turbo segun configuracion de la placa.

El firmware PS1 publico se mantiene disponible gratuitamente en este repositorio. La build Hybrid AUTO se maneja como opcion de apoyo/donativos para sostener el desarrollo, pruebas, documentacion y fabricacion de prototipos.

## Alcance

| Funcion | Estado |
|---|---|
| PS1 digital cableado | Listo |
| PS2 / DualShock | Listo |
| Bluetooth BLE HID | Listo |
| Deteccion automatica PS1 / PS2 / BLE | Listo |
| AutoFire | Integrado / sujeto a validacion fisica |

## Distribucion

El repositorio publico incluye:

- Hardware KiCad.
- Documentacion.
- Gerbers cuando esten validados.
- Firmware PS1 publico.
- Guias de prueba y fabricacion.

La build Hybrid AUTO se distribuye por separado como apoyo/donativo. La distribucion recomendada es publicar o entregar:

```text
Act_Labs_Hybrid_AUTO_vX.X.bin
checksums.txt
flashing_guide.md
release_notes.md
```

No se recomienda publicar el codigo fuente completo del firmware Hybrid AUTO en este repositorio publico si se desea mantenerlo como build de apoyo.

## Recomendaciones para publicar la build

Antes de entregar una build de apoyo:

1. Compilar una version estable del binario.
2. Probar PS1 en consola real.
3. Probar PS2 en consola real.
4. Probar BLE en PC o Android.
5. Generar checksums SHA256 y MD5.
6. Documentar version, fecha, hardware objetivo y cambios.
7. Incluir instrucciones de flasheo.

## Plataformas sugeridas

- GitHub Pages como landing page.
- PayPal / Mercado Pago para apoyo directo.
- Gumroad / Payhip / Ko-fi para entrega de archivo digital.
- Stripe Payment Links para pagos simples.
- GitHub Sponsors para apoyo recurrente.

## Nota de licencia y dependencias

Antes de distribuir binarios cerrados o semi-cerrados, revisar las licencias de las librerias usadas por el firmware.

Si alguna dependencia exige publicacion de fuente o avisos de licencia, incluir esos avisos junto con la build.

## Mensaje sugerido para usuarios

```text
El firmware PS1 publico esta disponible gratis en GitHub.

La build Hybrid AUTO PS1/PS2/BLE es una version avanzada para quienes quieran apoyar el desarrollo del proyecto. Tu apoyo ayuda a cubrir prototipos, pruebas en hardware real, documentacion y nuevas revisiones de PCB.
```
