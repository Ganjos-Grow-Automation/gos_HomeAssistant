# Die Installation des GanjOS

>[!CAUTION]
>  
>Wir vom Projektteam übernehmen keine Haftung für Anschluss- oder Konfigurationsfehler, die beim Einsatz der GanjOS Grow Automation auftreten können. Es liegt in eurer Verantwortung, sicherzustellen, dass euer Setup korrekt funktioniert und euren Pflanzen die bestmögliche Umgebung bietet. Ebenso haften wir nicht für Fehler oder Schäden, die durch unsachgemäße Elektroanschlüsse entstehen. Bitte beachtet, dass die Nutzung dieser Lösung ausschließlich im Rahmen der gesetzlichen Bestimmungen in Deutschland oder anderen Ländern erlaubt ist. Die Verantwortung für die Einhaltung dieser Vorschriften liegt bei euch als Anwender.

## Vorraussetzungen

>[!IMPORTANT]
>
>Für die Nutzung der GanjOS Grow Automation wird passende Hardware benötigt. Eine vollständige Übersicht der kompatiblen und erforderlichen Geräte findest du in der [Hardwareliste](./HARDWARE.md).

Was wird benötigt? Was brauche ich um den GanjOS einzusetzen? 

Für den Einsatz des GanjOS wird folgendes benötigt:
* Ein Home Assistant Server
* Die Hardware für die jeweilig einzusetzenden GanjOS Module
* ggfs. Funksteckdosen oder andere Hardware (siehe [Hardwareliste](./HARDWARE.md)) zur Ansteuerung entsprechender Hardware

### Basis
Für das Basismodul wird eine Home Assistant fähige Hardware benötigt. Welche sich hier am Besten eignet, findest du im [Hardware Dokument](./HARDWARE.md). 

>[!TIP]
>
>Für die Installation von Home Assistant findest du bereits zahlreiche hervorragende Anleitungen in Online-Foren und auf YouTube, die dir Schritt für Schritt weiterhelfen. Aus diesem Grund lassen wir diesen Installationsschritt in dieser Anleitung aus.

>[!NOTE]
>
>Trotz der bereits verfügbaren Anleitungen planen wir, in Zukunft eine eigene Schritt-für-Schritt-Videoanleitung für die vollständige GanjOS-Konfiguration und alle erforderlichen Schritte auf unseren Social-Media-Kanälen bereitzustellen. Damit möchten wir euch umfassend unterstützen und sicherstellen, dass ihr euer Setup problemlos einrichten könnt. Bleibt dran, um keine Updates zu verpassen!

Falls du schon einen Home Assistant Server im Einsatz hast kannst du den nächsten Schritt überspringen und mit den Schritt der Add-Ons und Integrationen weiter machen.

#### Installation Home Assistant
Nachfolgend findest Möglichkeiten, um die GanjOS Home Assistant Konfiguration zu installieren. 

##### Importieren der fertigen Lösung ohne Konfiguration
>[!TIP]
>
>Wir entwickeln derzeit eine Lösung, die eine einfache und direkte Installation der Konfiguration ermöglicht. Diese Funktion wird von unserem Team intensiv ausgearbeitet und getestet.

##### Importieren der GanjOS Konfiguration
Die zweite Möglichkeit setzt etwas Geschick oder Erfahrung in Home Assistant voraus.

Hierbei werden alle Dateien aus dem Ordner [Home Assistant](./HomeAssistant/) in den Quellcode deiner Home Assistant-Konfiguration integriert. Für erfahrene Benutzer ist dieser Schritt vertraut, kann jedoch für Einsteiger eine größere Herausforderung darstellen. Solltest du dabei auf Schwierigkeiten stoßen, findest du hilfreiche Anleitungen auf YouTube unter dem Suchbegriff "Home Assistant Configuration" oder speziell auf dem Kanal von [Simon42](https://www.youtube.com/@simon42).

Um GanjOS initial einzurichten, kopierst du einfach alle Dateien in das Home Assistant-Verzeichnis und fügst zusätzlich eine secrets.yaml-Datei mit deinen persönlichen Daten hinzu.

##### Anpassungen der GanjOS Konfiguration

###### Secret Datei

Die secrets.yaml Datei muss folgende Bestandteile beinhalten.

```
influxdb_password: DeinPasswortFürDieInfluxDB
latitude: X
longitude: X
```

###### Anpassungen in Node-Red

Nachdem du alle Flows erfolgreich in Node-Red importiert hast, musst du die Flows mit dem Präfix "[DC]" anpassen, um deine Geräte zu steuern. Wähle dazu in den jeweiligen "turn on", "turn off" oder "dimm"-Aktionen das entsprechende Gerät aus, das du steuern möchtest.

>[!CAUTION]
>
>Wenn du die Flows, die den Präfix "[DC]" nicht enthalten anpasst, kann unter Umständen der Automatismus auf Fehler laufen. Daher ist dies nur für erfahrene Nutzer empfohlen. 

Zusätzlich musst du im Flow "[Area-Values] Area 1" die Sensoren anpassen, damit sie mit den bei dir eingesetzten Sensoren übereinstimmen.

##### Bestehende GanjOS Konfiguration updaten

Um deinen GanjOS auf die neueste Version zu aktualisieren, müssen die entsprechenden YAML-Dateien oder Node-RED-Automationen angepasst werden. Die jeweiligen Patchnotes enthalten alle Informationen zu den Neuerungen und Änderungen im Update.

>[!TIP]
>
>Wie du deine eigene GanjOS Konfiguration updaten kannst werden wir in naher Zukunft in einem Tutorial-Video genauer erläutern. 
##### Deine eigene GanjOS Konfiguration erstellen

>[!TIP]
>
>Wie du deine eigene GanjOS Konfiguration erstellen kannst werden wir in naher Zukunft in einem Tutorial-Video genauer erläutern.
#### Installation Integrationen und Add-Ons

##### Integrationen
>[!NOTE]
>
> Die nachfolgenden Integrationen sind im Entwicklungs-Setup vom GanjOS Projektteam vorhanden und teilweise für die Verwendung der Grow Automation erforderlich.

Erforderlich:
* HACS
* Node-RED Companion

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
* Grafana


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
* [Home Assistant VPD Chart](https://github.com/mentalilll/ha-vpd-chart) - Das müsst ihr als benutzerdefiniertes Repository einbinden.

### GanjOS Module


#### Air-Monitoring
Um die Luftbedingungen zu überwachen, benötigst du entsprechende Geräte wie eine ESP-32-Platine sowie Sensoren für Temperatur, Luftfeuchtigkeit und CO2-Gehalt. Alternativ kannst du auch fertige Sensoren verwenden, die sich in Home Assistant integrieren lassen. In unserem Setup setzen wir auf ESP32-Platinen mit Sensoren, die über ESPHome eingebunden werden. Eine detaillierte Hardware-Liste findest du [hier](./HARDWARE.md).

>[!NOTE]
>
>Eine genaue Anleitung, wie du das Modul anschließt findest du [hier](./ESPHome/AirMonitoring/moduleDescription.md).

#### Air-Control
Um auf die Werte aus dem Air-Monitoring zu reagieren, ist eine Steuerung der Geräte erforderlich. Es gibt viele Möglichkeiten, wie du darauf reagieren kannst, z.B. durch einen Luftbefeuchter, Luftentfeuchter, eine Abluftanlage oder eine Klimaanlage. Da jedes Setup individuell ist und nicht jeder Homegrower alle Geräte im Einsatz hat, haben wir die Funktion integriert, bei der ein Gerät mehrere Aufgaben übernehmen kann – zum Beispiel die Luftentfeuchtung und die Klimaregulierung über die Abluft. In den Bereicheinstellungen kannst du die entsprechenden Werte für diese Funktionen anpassen.

Auf dem Markt gibt es eine Vielzahl an Hardware, die sich direkt oder indirekt in Home Assistant und GanjOS integrieren lässt. Um eine einfache Integration zu ermöglichen, setzen wir teilweise auf Funksteckdosen. Diese Geräte werden durch einfaches Ein- und Ausschalten gesteuert.

Wir arbeiten jedoch intensiv daran, Geräte mit Dimmfunktion direkt zu integrieren. Da dies jedoch mit erheblichen Kosten verbunden ist und das Projekt keinen direkten finanziellen Ertrag generiert, ist der Fortschritt in diesem Bereich derzeit begrenzt. Wir ermutigen jedoch die Community, Integrationen zu teilen oder sich an der Entwicklung zu beteiligen, damit wir GanjOS weiter verbessern und auf ein neues Level heben können.

>[!NOTE]
>
> Eine genaue Anleitung, wie du das Modul anschließt findest du [hier](./ESPHome/AirControl/moduleDescription.md).

#### Water-Monitoring
>[!NOTE]
>
>Dieses Modul ist noch in der Entwicklung und wird in einem zukünftigen Release veröffentlicht.

#### Water-Control
>[!NOTE]
>
>Dieses Modul ist noch in der Entwicklung und wird in einem zukünftigen Release veröffentlicht.


#### Soil-Monitoring
>[!NOTE]
>
>Dieses Modul ist noch in der Entwicklung und wird in einem zukünftigen Release veröffentlicht.
