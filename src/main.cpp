#include <WiFi.h>    // ESP32 Systembibliothek
#include <Arduino.h>
#include "wifi.h"
#include "main.h"


#define HALL_PIN 34





/******************************************
 *
 *
 *
 *
 *
 *
 * ***************************************/
wifi_status_t wifi_status;

void setup() {
    Serial.begin(SERIAL_BAUD);
    pinMode(HALL_PIN, INPUT);
    wifi_status_t wifi_status = wifi_init();
    
}

/*******
 * Überprüfe in jedem Durchgang, ob die Verbindung steht
 * 
 * 
 * 
 */



void loop() {
  int hall_effect_sensor_state = digitalRead(HALL_PIN);

  if (hall_effect_sensor_state == LOW) {
    Serial.println("Magnet erkannt!");
  } else {
    Serial.println("Kein Magnet");
  }

    wifi_status = wifi_check_connection();
    handle_wifi_status(wifi_status);

}