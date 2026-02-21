#include <WiFi.h>    // ESP32 Systembibliothek
#include <Arduino.h>
#include "wifi.h"
#include "main.h"
#include "hall_sensor.h"






void setup() {
    Serial.begin(SERIAL_BAUD);
    wifi_status_t wifi_status = wifi_init();
    handle_wifi_status(wifi_status);
    init_hall_pin();
}



void loop() {
    wifi_status_t wifi_status = wifi_check_connection();
    handle_wifi_status(wifi_status);
    tmp_hall_sensor();
}