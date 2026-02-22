#include <Arduino.h>
#include "debug_handler.h"
#include "led.h"
#include "wifi.h"


void debug_handler(system_code_t system_code){
    switch(system_code){
        case WIFI_STATUS_OK:
            led_off();
            break;
        case WIFI_STATUS_ERROR:
            slow_blinking();
            break;
            
        case WIFI_STATUS_TIMEOUT:
            fast_blinking();
            break;
        case HTTP_OK:
            led_off();
            break;
    }   
}