# Benötigte & unterstützte Hardware

>[!IMPORTANT]
>
>Die hier hinterlegten Links sind Affiliate Links des Projektes. Wenn du über diese Links einkaufst unterstüzt du das Projekt, da wir hier meist eine Provision erhalten, welche direkt in die Weiterentwicklung der Lösung einfließt. Hierdurch können wir vermehrt Sensoren testen und Erfahrungsberichte hierzu teilen oder auch Grow-Equiptment auf Kompatibilität mit unserer Lösung testen. Die entsprechenden Links werden entsprechend markiert. 

## Basis
Für die Basis wird ein Home Assistant fähiger Host benötigt. Dieser kann sowohl ein Raspberry Pi, ein Thin Client oder ähnliches sein. 

>[!TIP]
>
>Interessante Beiträge zu diesem Thema:
>* [Simon 42 - Hardware Empfehlungen für deine Home Assistant OS Installation](https://www.simon42.com/home-assistant-hardware/)
>* [Simon 42 - Home Assistant als virtuelle Maschine auf Proxmox installieren](https://www.simon42.com/home-assistant-proxmox/)


Als Hardware für das Hosting des Home Assistant Servers eignen sich folgende Geräte:

* [Fujitsu Thin Client Refurbished](https://amzn.to/4aRsIdT) [Affiliate]
* [Lenovo Thin Client v1](https://amzn.to/3VuXxQ7) [Affiliate]
* [Lenovo Thin Client v2](https://amzn.to/3KsXgrs) [Affiliate]

>[!TIP]
>
>Wir empfehlen den Einsatz eines refurbished Thin Client / Mini-PC, da du hier mehr für dein Geld bekommst und die Leistung bei Bedarf meist noch erweitern kannst. 


## Module

>[!NOTE]
>
> Aktuell nutzen wir die Integration ESPHome, um Sensordaten in Home Assistant auszulesen. Generell ist es möglich alle vorhandenen Home Assistant Integrationen zu nutzen, um Daten auslesen zu können. Der von uns gewählte Weg ist nur einer von vielen und soll beispielhaft darstellen, wie Sensoren in Home Assistant integriert werden können. 
>
> Wir verfolgen dennoch weitere Integrationen in dieser Anleitung zu dokumentieren, um mehrere Möglichkeiten zur Integration von Sensordaten auflisten zu können. 


Die Basis der Module über ESPHome stellen ESP32 Platinen dar. Zur Entwicklung wurden hierbei folgende Bestandteile verwendet:

* [DFRobot - FireBeetle 2 ESP32-E](https://www.dfrobot.com/product-2231.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) [Affiliate] - Die Basisplatine
* [DFRobot - IO Shield for FireBeetle 2](https://www.dfrobot.com/product-2395.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) [Affiliate] - zur Vereinfachung des Anschluss von mehreren Sensoren
* [5V USB-C Netzteil für ESP32](https://amzn.to/4bTv2BX) [Affiliate] oder [USB C Mehrfachladegerät](https://amzn.to/4gixd4b) [Affiliate] - zur Stromversorgung

>[!IMPORTANT]
>
> Die nachfolgenden Sensoren sind lediglich die vom GanjOS Team getesteten und integrierten Sensoren. Alle ESPHome kompatiblen Sensoren findest du auf der offiziellen Homepage von [ESPHome](https://esphome.io/).

### Air Monitoring

>[!NOTE]
>
> Die Aufgabe dieses Modul liegt in der Überwachung der Luftbedingungen.

#### Temperatur und Luftfeuchtigkeit

* [SHT31](https://www.dfrobot.com/product-2160.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) [Affiliate] - Der höherwertigere Sensor
* [I2C Temp & Hum Sensor](https://www.dfrobot.com/product-2600.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) [Affiliate] - Der Low Budget Sensor

>[!CATION]
>
> Der I2C TEmp & Hum Sensor wurde vom GanjOS Team getestet und ist bei längeren Aussetzung von hohen Luftfeuchtigkeiten kaputt gegangen. Daher ist für eine gewisse Stabilität zum hochwertigeren SHT31 Sensor zu raten. 

#### CO2

* [ENS160](https://www.dfrobot.com/product-2623.html?tracking=WjyQJqF2zJKV41fDEVNqlL8iIoSaXJXcs510uBhCzQJ0RftedpYAlvGH8TibE7eY) [Affiliate] - Air Quality Sensor, der solide funktioniert.

### Soil Monitoring
>[!NOTE]
>
> Die Aufgabe dieses Modul liegt in der Überwachung der Substratbedingungen, im Konkreten hier die Boden-Bedingungen. Weitere Sensoren werden bereits von unserem Team getestet.

* [Flower Care Max Sensor](https://www.techpunt.nl/de/xiaomi-hhcc-mi-flower-care-plant-sensor-max.html) - der etwas größere Sensor
* [Flower Care Mini Sensor](https://amzn.to/4d90FZi) [Affiliate] - der kleinere Sensor

### Air Control 
>[!NOTE]
>
> Die Aufgabe dieses Modul liegt in der Steuerung von kompatiblem Equiptment zur Anpassung der Luftbedingungen

* [PWM Converter](https://amzn.to/4fwRR0Z) [Affiliate] - zur Steuerung von PWM Lüftern
* [12V Netzteil](https://amzn.to/3WTSvy8) [Affiliate] - zur Stromversorgung der PWM Steuerung


## Generelles Grow Equiptment / Zubehör

>[!NOTE]
>
>Das hier aufgelistete Grow-Equiptment ist lediglich eine Auflistung dessen, welches bereits vom offiziellen GanjOS Team getestet wurde und in ein bestehendes Setup integriert wurde. Es ist auch möglich anderes Equiptment zu integrieren, jedoch können wir und unsere Community hier meist nur bedingt Hilfestellung leisten.

### Abluftventilatoren

* [Ruck EC Lüfter]()  - komplette Steuerung inkl. Dimmung siehe [Anleitung](./Guides/RuckEC.md). (coming soon)
* [Prima Klima ECBlue Serie]() - komplette Steuerung inkl. Dimmung siehe [Anleitung](./Guides/PKECBlue.md). (coming soon)

### Umluftventilatoren

* [DIY PWM Ventilatoren]() - Aufbau und Anschluss siehe [Anleitung](./Guides/PWMVentilation.md). (coming soon)

### Beleuchtung

* [SANLight Evo Serie]() - komplette Steuerung inkl. Dimmung siehe [Anleitung](./Guides/SANLightEvo.md). (coming soon)
* [SANLight Flex Serie]() - Ein-/Ausschalten über eine Funksteckdose möglich
* [Migro Array Serie] - komplette Steuerung inkl. Dimmung siehe [Anleitung](./Guides/MigroArray.md). (coming soon)

### Luftbefeuchter

* [LEVOIT 6L Luftbefeuchter](https://amzn.to/3WyrkI8) [Affiliate]

### Funksteckdosen

* [Shelly Smart Plugs](https://amzn.to/3WRTe3u) [Affiliate] - WLAN Steckdose 5er Set
* [NOUS A1Z](https://amzn.to/4azvhRF) [Affiliate] - ZigBee Steckdose
* [NOUS A1T](https://amzn.to/4aBp3kl) [Affiliate] - Tasmota Steckdose

### Dimmer

* [Shelly Dimmer 0-10V](https://amzn.to/46Ivv8U) - zur Steuerung und Dimmung von kompatiblen Geräten

### Timelapse Aufnahmen
* [Reolink 4k Kamera](https://amzn.to/4f5R1qu) - Eine sehr hochwertige Outdoor Kamera mit 4K auflösung
* [Synology NAS](https://amzn.to/3ZAuOMU) - Zur Speicherung der Backups und der Timelapse Aufnahmen

### Nützliches Equiptment & Sonstiges

* [SONOFF Zigbee USB Dongle](https://amzn.to/4dXsq7Q) [Affiliate] - zur Verbindung von ZigBee Geräten
* [WLAN USB Dongle]()
* [Blueetooth USB Dongle]()
* [Petrischalen](https://amzn.to/3LSmwYS) [Affiliate] - Zum Keimen der Samen
* [8-Fach Steckdosenleiste](https://amzn.to/3YBD9zI) [Affiliate]
* [Crimpzangen-Set](https://amzn.to/3LWoBmO) [Affiliate]
* [Netzkabel](https://amzn.to/4duyV16) [Affiliate]
* [Mikroskop](https://amzn.to/3yvMO0a) [Affiliate] - Zur Verbindung mit dem Smartphone und dem PC
* [Kabelverbinder](https://amzn.to/4fxSA20) [Affiliate]