#include <WiFi.h>
#include <Arduino.h>
#include "debug_handler.h"
#include "wifi.h"        /* eigenes Interface immer zuerst */
#include "auth.h"        /* nur wenn hier benötigt */




/*******************************************************************************
 * @brief    Initiates a wifi connection. SSID and password are specified in auth.h. The functions tries to init a wifi connection. It either return
 *
 * @param    /
 *
 * @return  WIFI_STATUS_OK, WIFI_STATUS_TIMEOUT or WIFI_STATUS_ERROR
 ******************************************************************************/

system_code_t wifi_init() {
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

 unsigned long startTime = millis();

    while (WiFi.status() != WL_CONNECTED) {
        if (millis() - startTime >= 1000u) {
            return WIFI_STATUS_TIMEOUT;
        }
        if (WiFi.status() == WL_CONNECT_FAILED)
        {
            return WIFI_STATUS_ERROR;
        }

    }
    return WIFI_STATUS_OK;
}


/*******************************************************************************
 * @brief   Tests existing wifi connection. If it fails try to reconnect
 *
 * @param   /
 *
 * @return  WIFI_STATUS_OK or WIFI_STATUS_ERROR
 ******************************************************************************/

system_code_t wifi_check_connection(){
     if(WiFi.status() == WL_CONNECTED){
        return WIFI_STATUS_OK;
   }
   else{
        return wifi_init();
   }
}


