#include <WiFi.h>
#include <Arduino.h>
#include <stdint.h>
#include "wifi.h"        
#include "auth.h"        




/*******************************************************************************
 * @brief    Initiates a wifi connection. SSID and password are specified in auth.h. The functions tries to init a wifi connection. It either return
 *
 * @param    /
 *
 * @return  WIFI_STATUS_OK, WIFI_STATUS_TIMEOUT or WIFI_STATUS_ERROR
 ******************************************************************************/

wifi_code_t wifi_init() {
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

 unsigned long startTime = millis();

    while (WiFi.status() != WL_CONNECTED) {
        if (millis() - startTime >= TIMEOUT) {
            return WIFI_STATUS_TIMEOUT;
        }
    }
    if (WiFi.status() == WL_CONNECTED)
        {
            return WIFI_STATUS_OK;
        }
        else {
            return WIFI_STATUS_ERROR;
        }

    
}


/*******************************************************************************
 * @brief   Tests existing wifi connection. If the wifi connection is lost it tries to reconnect, before 
 * returning a failure code.
 *
 * @param   /
 *
 * @return  WIFI_STATUS_OK or WIFI_STATUS_ERROR
 ******************************************************************************/

wifi_code_t wifi_check_connection(){
     if(WiFi.status() == WL_CONNECTED){
        return WIFI_STATUS_OK;
   }
   else{
        return wifi_init();
   }
}
