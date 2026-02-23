#include "debug_handler.h"
#include "http.h"
#include "wifi.h"
#include "led.h"

led_state_t wifi_debug_handler(wifi_code_t wifi_status) {
    if (wifi_status == WIFI_STATUS_OK) {
        return LED_OFF;
    } else if (wifi_status == WIFI_STATUS_TIMEOUT) {
        return LED_BLINK_SLOW;
    } else {
        return LED_BLINK_FAST;
    } 
}   

led_state_t http_debug_handler(wifi_code_t wifi_status, http_code_t http_status){

    if (wifi_status == WIFI_STATUS_OK) {
        
        if (http_status == HTTP_STATUS_OK || NO_HTTP_REQUEST) {
            return LED_OFF;
        }
        else 
        {
            return LED_ON;
        }

    } else if (wifi_status == WIFI_STATUS_TIMEOUT) {
        return LED_BLINK_SLOW;
    } else if (wifi_status == WIFI_STATUS_ERROR) {
        return LED_BLINK_FAST;
    }
}