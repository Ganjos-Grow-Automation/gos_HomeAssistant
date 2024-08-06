# Die Installation des GanjOS

>[!CAUTION]
>  
> Wir vom Projektteam haften für keine Anschlussfehler oder Konfigurationsfehler beim Einsatz der GanjOS Grow Automation. Ihr seid sellbst dafür verantwortlich, dass euer Setup sauber läuft und es euren Pflanzen gut geht. Zudem übernehmen wir keine Haftung für etwaige Anschlussfehler und Fehlfunktionen beim Elektroanschluss. Der Einsatz der Lösung ist lediglich für die geltenden gesetzlichen Rahmen bestimmt. 

## Vorraussetzungen

>[!IMPORTANT]
>
> Um die GanjOS Grow Automation nutzen zu können darf es entsprechender Hardware. Eine vollständige Liste der kompatiblen und benötigten Hardware findest du in der [Hardwareliste](./HARDWARE.md).

Was wird benötigt? Was brauche ich um den GanjOS einzusetzen? 

Für den Einsatz des GanjOS wird folgendes benötigt:
* Ein Home Assistant Server
* Die Hardware für die GanjOS Module
* ggfs. Funksteckdosen oder andere Hardware (siehe [Hardwareliste](./HARDWARE.md))

### Basis
Für das Basismodul wird eine Home Assistant fähige Hardware benötigt. Welche sich hier am Besten eignet findest du im [Hardware Dokument](./HARDWARE.md). 

>[!TIP]
>
>Zur Installation an sich findest du in diversen Online-Foren oder auf YouTube bereits sehr gute Anleitungen, wie du den Home Assistant zum Laufen bekommst. 

>[!NOTE]
>
>Eine komplette Einrichtung des Home Assistant Host werden wir in naher Zukunft in form eines Video-Tutorials in unserem Shop für einen kleinen Spendenbetrag veröffentlichen. Einen Link zum Shop findest du [hier](https://ko-fi.com/ganjos). 
>
> Die schriftliche Anleitung wird von unserem Team zusätzlich in den kommenden Wochen erweitert. 

Falls du schon einen Home Assistant Server im Einsatz hast kannst du den nächsten Schritt überspringen und mit den Schritt der Add-Ons und Integrationen weiter machen.

#### Installation Home Assistant

>[!TIP]
>
>Wir arbeiten gerade an einer Lösung, dass eine Konfiguration direkt als Backup importiert werden kann. Diese Möglichkeit wird aktuell von unserem Team ausgearbeitet und getestet. 
##### Importieren der GanjOS Konfiguration
Die zweite Möglichkeit setzt etwas Geschick oder Erfahrung in Home Assistant voraus.

Hier werden alle Files aus dem Ordner [Home Assistant](./HomeAssistant/) in den Quellcode deiner Home Assistant Konfiguration eingefügt. Für erfahrene Home Assistant Benutzer ist das bereits bekannt, für Neulinge jedoch eine große Herausforderung. Falls du hier Probleme hast findest du tolle Anleitungen auf YouTube unter dem Suchbegriff "Home Assistant Configuration" oder auch speziell auf dem Kanal von [Simon42](https://www.youtube.com/@simon42).

Um den GanjOS initial einzurichten kopierst du hier alle Dateien in dein Verzeichnis des Home Assistant hinnein und fügst noch zusätzlich eine secrets.yaml Datei mit deinen entsprechenden Daten ein.

##### Anpassungen der GanjOS Konfiguration

###### Secret Datei

Die secrets.yaml Datei muss folgende Bestandteile haben.

```
influxdb_password: DeinPasswortFürDieInfluxDB
latitude: X
longitude: X
```

###### Anpassungen im Quellcode

Im Quellcode der Lösung müssen bestimmte Zeilen auf deine Geräte und deine Sensoren angepasst werden. Die entsprechenden Zeilen wurden mit folgendem vorangestellten Kommentar gekennzeichnet oder dem Dateinamen gosConfig_*.yaml gekennzeichnet.

```
#to be configured
```

Wenn du diese Zeilen angepasst hast oder die entsprechenden Elemente in den Dashboards bei nicht-Verwendung löschst, sollte die GanjOS Grow Automation bei dir funktionieren.

>![TIP]
>
>Überprüfen kannst du das in den Entwicklerwerkzeugen indem du überprüfst, welchen Zustand deine jeweiligen Sensoren haben. Ist hier ein Fehler bei den Entitäten _sensor.area_ZAHL_automation_* dann läuft der Automatismus auf Fehler. Behebe zuerst diese Fehler, bevor du mit dem folgenden Schritt weiter machst.

###### Anpassungen in Node-Red

Nachdem du alle Flows erfolgreich in Node-Red importiert hast, musst du alle Flows mit dem Präfix "[DC]" anpassen, um deine jeweiligen Geräte anzusteuern. Wähle hierzu in der jeweiligen "turn on / turn off / dimm" Aktionen dein Gerät aus, welches hier gesteuert werden soll.

>![CAUTION]
>
>Wenn du die Flows, die den Präfix "[DC]" nicht enthalten anpasst, kann unter umständen der Automatismus auf Fehler laufen. Daher ist dies nur für erfahrene Nutzer empfohlen. 

##### Bestehende GanjOS Konfiguration updaten
Um deinen GanjOS auf eine neue Version zu aktualisieren, müssen die entsprechenden YAML-Files oder die NodeRed-Automationen angepasst werden. In den jeweiligen Patchnotes ist vermerkt, welche Neuerungen im Patch enthalten sind. 

Wie man ein Update einspielt werden wir zudem in einer Video-Anleitung in Zukunft ausarbeiten.
>[!TIP]
>
>Wie du deine eigene GanjOS Konfiguration updaten kannst werden wir in naher Zukunft in einem Tutorial-Video genauer erläutern. Das Video wirst du [hier](https://ko-fi.com/ganjos) finden.

##### Eigene GanjOS Konfiguration erstellen

>[!TIP]
>
>Wie du deine eigene GanjOS Konfiguration erstellen kannst werden wir in naher Zukunft in einem Tutorial-Video genauer erläutern. Das Video wirst du [hier](https://ko-fi.com/ganjos) finden. 

#### Installation Integrationen und Add-Ons

##### Integrationen
>[!NOTE]
>
> Die nachfolgenden Integrationen sind im Entwicklungs-Setup vom GanjOS Projektteam vorhanden und teilweise für die Verwendung der Grow Automation erforderlich.

Erforderlich:
* HACS
* UI Lovelace Minimalist
* Node-RED Companion


Empfohlen:
* [Home Assistant Plant](https://github.com/Olen/homeassistant-plant) - als benutzerdefiniertes Repository einbinden.

##### Add-Ons
>[!NOTE]
>
> Die nachfolgenden Add-Ons sind im Entwicklungs-Setup vom GanjOS Projektteam vorhanden und teilweise für die Verwendung der Grow Automation erforderlich. 

Erforderlich
* Node-RED 
* InfluxDB 
* ESPHome 

Empfohlen: 
* Samba Backup 
* Samba Share 
* Studio Code Server 


Optional:
* Advanced SSH & Web Terminal

#### HACS Add-Ons und Integrationen

>[!NOTE]
>
>Im Bereich von HACS müssen folgende Integrationen und Lovelace Add-Ons hinzugefügt werden:

##### Lovelace
>[!NOTE]
>
> Je nach Konfiguration deines Dashboards werden weitere Add-Ons und Integrationen benötigt. Die hier aufgelisteten Add-Ons gehen vom "Standard"-Dashboard der GanjOS Grow Automation aus.

Erfoderlich:
* Digital Clock
* Mushroom
* mini-graph-card
* button-card
* Scheduler Card
* Config Template Card
* Bar Card
* Flower Card
* [Home Assistant VPD Chart](https://github.com/mentalilll/ha-vpd-chart) - Das müsst ihr als benutzerdefiniertes Repository einbinden.

Empfohlen:

#### Integrationen
>[!NOTE]
>
> Je nach Konfiguration deines GanjOS werden entsprechende Integrationen benötigt. Die hier aufgelisteten Integrationen gehen von der "Standard"-Konfiguration der GanjOS Grow Automation aus. Im Bereich der Integrationen müssen folgende Integrationen hinzugefügt und eine Instanz erstellt werden. 

Erforderlich:
* Lokales To-Do
* Einkaufsliste
* Node-RED Companion
* Plant Monitor
* Shelly (Wenn ihr Shelly-Funksteckdosen verwendet)
* UI Lovelace Minimalist

Empfohlen:


Optional: 

#### Air-Monitoring
Um die Luft-Bedingungen tracken zu können benötigst du die entsprechenden Geräte, wie z.B. eine ESP-32 Platine und Sensoren für die Temperatur, Luftfeuchtigkeit und den CO2 Gehalt deiner Umgebung. Hier kannst du aber auch fertige Sensoren verwenden, die in den Home Assistant integrierbar sind. Wir setzen in unserem Setup auf ESP32 Platinen mit Sensoren, die über ESPHome einbunden werden. Eine genauere Hardware Liste findest du [hier](./HARDWARE.md).

>[!NOTE]
>
>Eine genaue Anleitung, wie du das Modul anschließt findest du [hier](./ESPHome/AirMonitoring/moduleDescription.md).

#### Air-Control
Um auf die Werte aus dem Air-Monitoring zu reagieren, Bedarf es einer Steuerung deiner Geräte. Hierbei gibt es viele Möglichkeiten, welche eine Reaktion erzeugen. Bspw. durch einen Luftbefeuchter, Luftentfeuchter, eine Abluft oder auch eine Klimaanlage. Da jedes Setup sich hier unterscheidet und nicht jeder Homegrower alle Geräte in seinem Setup vorhanden hat, haben wir die Funktion integriert, dass Geräte mehrere Aufgaben erledigen, wie z.B. die Luftentfeuchtung und die "Klimaregelung" über die Abluft geregelt wird. Hierbei hast du in den Bereicheinstellungen die Möglichkeiten entsprechende Werte zu setzen.


Zudem gibt es auf dem Markt eine große Menge an Hardware, die sich direkt oder indirekt in den Home Assistant / GanjOS integrieren lassen. Um jedoch die einfachste Integration direkt zu ermöglichen nutzen wir teilweise Funksteckdosen. Die Geräte werden nach dieser Methode durch einfaches ein-/ausschalten angesteuert.


Wir arbeiten jedoch mit Hochdruck daran Geräte inkl. Dimmung direkt integrieren zu können. Da dies jedoch enorme Kosten einnimmt, das Projekt hingegen keinen direkten Ertrag generiert, ist hier nur ein mäßiger Fortschritt in der Entwicklung zu erwarten. Hier ist jedoch auch die Community angehalten Integrationen zu teilen oder sich in der Entwicklung zu beteiligen, damit wir den GanjOS auf ein neues Level heben können. 

>[!NOTE]
>
> Eine genaue Anleitung, wie du das Modul anschließt findest du [hier](./ESPHome/AirControl/moduleDescription.md).

#### Water-Monitoring
>[!NOTE]
>
>Dieses Modul ist noch in der Entwicklung und wir in einem zukünftigen Release veröffentlicht.

#### Water-Control
>[!NOTE]
>
>Dieses Modul ist noch in der Entwicklung und wir in einem zukünftigen Release veröffentlicht.