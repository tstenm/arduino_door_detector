#include <WiFi.h>    // ESP32 Systembibliothek
#include <Arduino.h>
#include "wifi.h"
#include "main.h"







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
    wifi_status_t wifi_status = wifi_init();
    handle_wifi_status(wifi_status);
    
}





void loop() {
    wifi_status = wifi_check_connection();
    handle_wifi_status(wifi_status);

}