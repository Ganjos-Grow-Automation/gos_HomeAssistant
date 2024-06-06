# Benötigte Hardware

## Basis
Für die Basis wird ein Home Assistant fähiger Host benötigt. Dieser kann sowohl ein Raspberry Pi, ein Thin Client oder ähnliches sein. 

Interessante Links zu diesem Thema sind folgende:
* [Simon 42 - Hardware Empfehlungen für deine Home Assistant OS Installation](https://www.simon42.com/home-assistant-hardware/)
* [Simon 42 - Home Assistant als virtuelle Maschine auf Proxmox installieren](https://www.simon42.com/home-assistant-proxmox/)


Mögliche Hardware: 
* [Fujitsu Thin Client Refurbished](https://amzn.to/4aRsIdT)
* [Lenovo Thin Client v1](https://amzn.to/3VuXxQ7)
* [Lenovo Thin Client v2](https://amzn.to/3KsXgrs)

## Module
Die Basis der Module über ESPHome stellen ESP32 Platinen dar. Zur Entwicklung wurden hierbei folgende Bestandteile verwendet:

* [DFRobot - FireBeetle 2 ESP32-E](https://www.dfrobot.com/product-2231.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) - Die Basisplatine
* [DFRobot - IO Shield for FireBeetle 2](https://www.dfrobot.com/product-2395.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) - zur Vereinfachung des Anschluss von mehreren Sensoren
* [5V USB-C Netzteil für ESP32](https://amzn.to/4bTv2BX) - zur Stromversorgung

### Air Monitoring
Für das Monitoring der Luftbedingungen sind folgende Sensoren bereits vom GrowBot Team getestet und für kompatibel befunden worden:

#### Temperatur und Luftfeuchtigkeit
* [SHT31](https://www.dfrobot.com/product-2160.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) - Der höherwertigere Sensor
* [I2C Temp & Hum Sensor](https://www.dfrobot.com/product-2600.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) - Der Low Budget Sensor, welcher etwas ungenauer ist in der Messgenauigkeit und bei hohen Luftfeuchtigkeiten ggfs. kaputt gehen kann. 

#### CO2-Messung
* [ENS160](https://www.dfrobot.com/product-2623.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) - Air Quality Sensor, der solide funktioniert. 

### Soil Monitoring
* []()

### Air Control 

## Generelle Grow Ausrüstung / Zubehör (kompatibel mit dem GrowBot)

### Funksteckdosen
* [Sehlly Smart Plugs](https://amzn.to/3WRTe3u) - WLAN Steckdose 5er Set
* [NOUS A1Z](https://amzn.to/4azvhRF) - ZigBee Steckdose
* [NOUS A1T](https://amzn.to/4aBp3kl) - Tasmota Steckdose

### Sonstiges
* [SONOFF Zigbee USB Dongle](https://amzn.to/4dXsq7Q) - zur Verbindung von ZigBee Geräten