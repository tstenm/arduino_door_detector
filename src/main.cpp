#include <WiFi.h>    
#include <Arduino.h>
#include <stdint.h>
#include "http.h" 
#include "wifi.h"
#include "main.h"
#include "hall_sensor.h"
#include "debug_handler.h"
#include "led.h"
#include "door_state_handler.h"



static door_state_t door_state;

void setup() {
    Serial.begin(SERIAL_BAUD);
    init_led();
    wifi_code_t wifi_status = wifi_init();
    init_hall_pin();
    hall_state_t hall_value = read_hall_sensor();
    init_door_state(&door_state, hall_value);
    wifi_status = wifi_check_connection();
    led_state_t led_state = wifi_debug_handler(wifi_status);
    led_error_message(led_state);
    decide_http_function(door_state.current_value, true);
}

void loop() {
    
    wifi_code_t wifi_status = wifi_check_connection();    
    led_state_t led_state = wifi_debug_handler(wifi_status);
    led_error_message(led_state);
    hall_state_t hall_value = read_hall_sensor();
    update_door_state(&door_state, hall_value);    
    bool door_state_altered_indicator = door_state_altered(&door_state);
    decide_http_function(door_state.current_value, door_state_altered_indicator);
}