#include <WiFi.h>    // ESP32 Systembibliothek
#include <Arduino.h>
#include <stdint.h>
#include "http.h" 
#include "wifi.h"
#include "main.h"
#include "hall_sensor.h"





static door_state_t door_state;

void setup() {
    Serial.begin(SERIAL_BAUD);
    wifi_code_t wifi_status = wifi_init();
    wifi_debug_handler(wifi_status);
    init_hall_pin();
    hall_state_t hall_value = read_hall_sensor();
    init_door_state(&door_state, hall_value);
}

void loop() {
    wifi_code_t wifi_status = wifi_check_connection();
    wifi_debug_handler(wifi_status);
    hall_state_t hall_value = read_hall_sensor();
    update_door_state(&door_state, hall_value);
    bool door_state_altered_indicator;
    door_state_altered_indicator = door_state_altered(&door_state);

    // https_code_t https_status = ...

    http_debug_handler(wifi_status, 0); // https_status is not yet implemented
}