Beschreibung
Das Projekt wurde im Rahmen des Moduls Mikroprozessorpraktikum entwickelt. Funktion ist es, den Status (geschlossen/offen) der Tür unseres Uni-Cafes zu erfassen  und diesen an ein Backend zu übertragen und von der mobile-App des Cafes ausgelesen und angezeigt werden kann. Ist die Tür geschlossen, wird das Cafe als geschlossen angezeigt und vice versa. 

Hardware
ESP32 (eingebautes Wifi-Modul, LED)
Hall-Effect-Sensor 

Funktion
Der Hall-Effect-Sensor erkennt den Status der Tür. Bei einer Änderung des Status wird dem Backend die Änderung über eine HTTPS-Anfrage mitgeteilt. 
