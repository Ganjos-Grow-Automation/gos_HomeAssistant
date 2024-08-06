# Die Installation des GanjOS

>[!CAUTION]
>  
> Wir vom Projektteam haften für keine Anschlussfehler oder Konfigurationsfehler beim Einsatz der GanjOS Grow Automation. Ihr seid sellbst dafür verantwortlich, dass euer Setup sauber läuft und es euren Pflanzen gut geht. Zudem übernehmen wir keine Haftung für etwaige Anschlussfehler und Fehlfunktionen beim Elektroanschluss. Der Einsatz der Lösung ist lediglich für die geltenden gesetzlichen Rahmen bestimmt. 

## Vorraussetzungen

Was wird benötigt? Was brauche ich um den GanjOS einzusetzen? 

Für den Einsatz des GanjOS wird folgendes benötigt:
* Ein Home Assistant Server
* Die Hardware für die GanjOS Module
* ggfs. Funksteckdosen (siehe [Hardwareliste](./HARDWARE.md))

#### Basismodul
Für das Basismodul wird eine Home Assitant fähige Hardware benötigt. Welche sich hier am Besten eignet findest du im [Hardware Dokument](./HARDWARE.md). Zur Installation an sich findest du in diversen Online-Foren oder auf YouTube bereits sehr gute Anleitungen, wie du den Home Assistant zum Laufen bekommst. 


Falls du schon einen Home Assistant Server im Einsatz hast kannst du diesen Schritt überspringen und mit den nächsten Schritten weiter machen. 

#### Air-Monitoring
Um die Luft-Bedingungen tracken zu können benötigst du die entsprechenden Geräte, wie z.B. eine ESP-32 Platine und Sensoren für die Temperatur, Luftfeuchtigkeit und den CO2 Gehalt deiner Umgebung. Hier kannst du aber auch fertige Sensoren verwenden, die in den Home Assistant integrierbar sind. Wir setzen in unserem Setup auf ESP32 Platinen mit Sensoren, die über ESPHome einbunden werden. Eine genauere Hardware Liste findest du [hier](./HARDWARE.md).

Eine genaue Anleitung, wie du das Modul anschließt findest du [hier](./ESPHome/AirMonitoring/moduleDescription.md).

#### Air-Control
Um die Werte aus dem Air-Monitoring zu reagieren Bedarf es einer Steuerung deiner Geräte. Hierbei gibt es viele Möglichkeiten, welche einene Hebel erzeugen. Bspw. durch einen Luftbefeuchter, Luftentfeuchter, die Abluft oder auch eine Klimaanlage. Da jedes Setup sich hier unterscheidet und nicht jeder alle Geräte zur Verfügung hat haben wir Möglichkeiten integriert, dass Geräte mehrere Aufgaben erledigen, wie z.B. die Luftentfeuchtung und die "Klimaanlage" über die Abluft geregelt wird. Hierbei hast du in den Bereicheinstellungen die Möglichkeiten entsprechende Werte zu setzen.


Zudem gibt es auf dem Markt eine große Menge an Gerätschaften, die sich direkt oder indirekt in den Home Assistant / GanjOS integrieren lassen. Um jedoch die einfachste Integration direkt zu ermöglichen nutzen wir Funksteckdosen. Somit werden die Geräte durch einfaches ein-/ausschalten angesteuert.

Wir arbeiten jedoch mit Hochdruck daran Geräte inkl. Dimmung direkt integrieren zu können. Da dies jedoch enorme Kosten einnimmt, das Projekt hingegen direkt kein Geld generiert ist hier nur ein langsamer Fortschritt zu erwarten. Hier ist jedoch auch die Community angehalten gerne Integrationen zu teilen oder mit zu entwickeln, damit wir den GanjOS auf ein neues Level heben können. 

Eine genaue Anleitung, wie du das Modul anschließt findest du [hier](./ESPHome/AirControl/moduleDescription.md).

#### Water-Monitoring

Dieses Modul ist noch in der Entwicklung und wir in einem zukünftigen Release veröffentlicht.

#### Water-Control

Dieses Modul ist noch in der Entwicklung und wir in einem zukünftigen Release veröffentlicht.

### Welche Addons und Integrationen werden in Home Assistant benötigt?

Innerhalb Home Assistant benötigen wir für den GanjOS weitere Integrationen und Addons, um die Dashboards und weitere Funktionen nutzen zu können. 

#### Add-Ons
In den Add-Ons sind nachfolgende von uns im Einsatz und sind teilweise für die Verwendung des GanjOS erforderlich.

* Advanced SSH & Web Terminal 
* Node-RED  - **erforderlich**
* Samba Backup - **empfohlen**
* Samba Share - **Samba share**
* InfluxDB - **erforderlich**
* Studio Code Server - **empfohlen**
* ESPHome - **erforderlich**

#### HACS Add-Ons und Integrationen
Im Bereich von HACS müssen folgende Integrationen und Lovelace Add-Ons hinzugefügt werden:

##### Integrationen
* HACS
* UI Lovelace Minimalist
* Scheduler component
* Node-RED Companion
* [Home Assistant Plant](https://github.com/Olen/homeassistant-plant) - Das müsst ihr als benutzerdefiniertes Repository einbinden.

##### Lovelace
* Digital Clock
* Mushroom
* mini-graph-card
* button-card
* Scheduler Card
* Config Template Card
* Bar Card
* Flower Card
* [Home Assistant VPD Chart](https://github.com/mentalilll/ha-vpd-chart) - Das müsst ihr als benutzerdefiniertes Repository einbinden.

#### Integrationen
Im Bereich der Integrationen müssen folgende Integrationen hinzugefügt und eine Instanz erstellt werden: 

* Lokales To-Do
* Einkaufsliste
* Node-RED Companion
* Plant Monitor
* Scheduler 
* Shelly - Wenn ihr Shelly-Funksteckdosen verwendet
* UI Lovelace Minimalist

## Die Installation des GanjOS

### Variante 1: Restore aus einem Backup
Diese Variante wird gerade getestet und zeitnah veröffentlicht. 

### Variante 2: Einfügen der einzelnen Config files

Die zweite Möglichkeit setzt etwas Geschick oder Erfahrung in Home Assistant voraus. 

Hier werden alle Files aus dem Ordner [Home Assistant](./HomeAssistant/) in den Quellcode deiner Home Assistant Konfiguration eingefügt. Für erfahrene Home Assistant Benutzer ist das bereits bekannt, für Neulinge jedoch eine große Herausforderung. Falls du hier Probleme hast findest du tolle Anleitungen auf YouTube unter dem Suchbegriff "Home Assistant Configuration" oder auch speziell auf dem Kanal von [Simon42](https://www.youtube.com/@simon42).

Um den GanjOS initial einzurichten kopierst du hier alle Dateien in dein Verzeichnis des Home Assistant hinnein und fügst noch zusätzlich eine secrets.yaml Datei mit deinen entsprechenden Daten ein.



### Generelle Anpassungen

#### Secret Datei
Die secrets.yaml Datei muss folgende Bestandteile haben. 
```
influxdb_password: DeinPasswortFürDieInfluxDB
latitude: X
longitude: X
```

#### Anpassungen im Quellcode
Im Quellcode der Lösung müssen bestimmte Zeilen auf deine Geräte und deine Sensoren angepasst werden. Die entsprechenden Zeilen wurden mit folgendem vorangestellten Kommentar gekennzeichnet oder dem Dateinamen gbConfig_*.yaml gekennzeichnet. 
```
#to be configured
```

Wenn du diese Zeilen angepasst hast oder die entsprechenden Elemente in den Dashboards bei nicht-Verwendung mit "#" auskommentiert hast sollte alles erfolgreich bei dir funktionieren. Überprüfen kannst du das in den Entwicklerwerkzeugen indem du schaust, welchen Zustand deine jeweiligen Sensoren haben. Ist hier ein Fehler bei den Entitäten _sensor.area_ZAHL_automation_* dann läuft der Automatismus auf Fehler. Versiche zuerst diese Fehler zu beheben, bevor du mit dem folgenden Schritt weiter machst. 

#### Anpassungen in Node-Red 
Nachdem du alle Flows erfolgreich in Node-Red importiert hast (eine Anleitung hierfür findest du unter anderem auch in mehreren YouTube Videos) muss du alle Flows mit dem Präfix "[DC]" anpassen, um deine jeweiligen Geräte anzusteuern. Wähle hierzu in der jeweiligen Aktion turn on / turn off dein Gerät aus, welches hier gesteuert werden soll. 

Um mehrere Bereiche in diesem Flow steuern zu können musst du ein zukünftiges Update abwarten oder den Haupt-Flow der Air Control anpassen. Das Update von unserer Seite wird vorraussichtlich in den kommenden Wochen veröffentlicht. 

## Den GanjOS updaten
Um den GanjOS auf eine neue Version zu heben, müssen die entsprechenden YAML Files oder die Node-Red Flows angepasst werden. In den jeweiligen Patchnotes wird vermerkt sein, welche das betrifft, um somit punktuell die Anpassungen einfügen zu können. 

Wie man ein Update einspielt werden wir zudem in einer Video-Anleitung in Zukunft ausarbeiten. 

## Die eigene GanjOS Konfiguration erstellen

Wir werden in naher Zukunft eine komplette Video-Anleitung erstellen in der wir die Installation Schritt für Schritt erklären und auch auf Themen, wie die Konfiguration des GanjOS angepasst auf das eigene Setup eingehen werden. 