#include <WiFi.h>
#include <Arduino.h>
#include "wifi.h"        /* eigenes Interface immer zuerst */
#include "auth.h"        /* nur wenn hier benötigt */



/*******************************************************************************
 * @brief    Initiates a wifi connection. SSID and password are specified in auth.h. The functions tries to init a wifi connection. It either return
 *
 * @param    /
 *
 * @return  WIFI_STATUS_OK, WIFI_STATUS_TIMEOUT or WIFI_STATUS_ERROR
 ******************************************************************************/

wifi_status_t wifi_init() {
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
 * @brief   Tests existing wifi connection.
 *
 * @param   /
 *
 * @return  WIFI_STATUS_OK or WIFI_STATUS_ERROR
 ******************************************************************************/

wifi_status_t wifi_check_connection(){
     if(WiFi.status() == WL_CONNECTED){
        return WIFI_STATUS_OK;
   }
   else{
        return WIFI_STATUS_ERROR;
   }
}


/*******************************************************************************
 * @brief   Tests existing wifi connection. If the connection is lost or cant be established, the function calls a led blink function and tries to reiniate the connection
 *
 * @param   WIFI_STATUS OK or WIFI_STATUS_ERROR
 *
 * @return  void
 ******************************************************************************/

void handle_wifi_status(wifi_status_t wifi_status){
    if(wifi_status == WIFI_STATUS_OK){
    }
    else{
        /* Todo : Blink Function, to indicate problem*/
        wifi_init();
    }
}

