#include "debug_handler.h"
#include "http.h"
#include "wifi.h"


void debug_handler(wifi_status_t wifi_status, http_status_t http_status){

    if (wifi_status == WIFI_STATUS_OK) {
        
        if (http_status == HTTP_STATUS_OK) {
            // return value for LED off
        } else {
            // return value for solid LED
        }

    } else if (wifi_status == WIFI_STATUS_TIMEOUT) {
        // return value for slow blinking LED
    } else if (wifi_status == WIFI_STATUS_ERROR) {
        // return value for fast blinking LED
    }

}