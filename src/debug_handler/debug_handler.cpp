#include "debug_handler.h"
#include "http.h"
#include "wifi.h"
#include "led.h"
/*******************************************************************************
 * @brief   Returns a led function identifier depending on the wifi status. If a error occurs a person should know
 *
 * @param   wifi_code_t
 *
 * @return  led_state_t
 ******************************************************************************/
led_state_t wifi_debug_handler(wifi_code_t wifi_status) {
    if (wifi_status == WIFI_STATUS_OK) {
        return LED_OFF;
    } else if (wifi_status == WIFI_STATUS_TIMEOUT) {
        return LED_BLINK_SLOW;
    } else {
        return LED_BLINK_FAST;
    } 
}   
/*******************************************************************************
 * @brief   Decides which LED code to return, so that the led module can decide which led function to call. Debug reasons. Debugs http codes
 * core idea : if the wifi does not work it does not make sense to debug a http error, because wifi is essential to even make http requests
 *
 * @param   wifi_code_t, http_code_t
 *
 * @return  led_state_t
 ******************************************************************************/
led_state_t http_debug_handler(wifi_code_t wifi_status, http_code_t http_status){

    switch (wifi_status)
    {
        case WIFI_STATUS_OK:
        if (http_status == HTTP_STATUS_OK || http_status == NO_HTTP_REQUEST) {
            return LED_OFF;
        }
        else 
        {
            return LED_ON;
        }
        case WIFI_STATUS_TIMEOUT: return LED_BLINK_SLOW;
        case WIFI_STATUS_ERROR: return LED_BLINK_FAST; 
        default : return LED_ON; 
      
    }
}