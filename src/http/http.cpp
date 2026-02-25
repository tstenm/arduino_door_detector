
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <stdint.h>
#include "http.h"
#include "hall_sensor.h"
#include "debug_handler.h"


static const char* servername = "https://87.106.5.130/door_state_altered";


/*******************************************************************************
 * @brief   This function is called, if the door status changed. It sends a http request, with a USER-AGENT to verify itself at the backend and the current door status
 *
 * @param   hall_state_t
 *
 * @return  http_code_t
 ******************************************************************************/
http_code_t http_send_manual_door_status(hall_state_t door_state) {

    WiFiClientSecure client;
    client.setInsecure();   

    HTTPClient http;
    http.setUserAgent("Im Arduino");
    char door_state_str[7];
    if(door_state == DOOR_OPEN){
        strcpy(door_state_str, "Open");
    }
    else{
        strcpy(door_state_str, "Closed");
    }   
    const bool REPLACE = false;
    const bool APPEND = false;
    http.addHeader("Accept", door_state_str, REPLACE, APPEND);
    http.begin(client, servername);
    int16_t httpResponseCode = http.GET();  
    if(httpResponseCode == HTTP_CODE_OK){
         http.end();
        return HTTP_STATUS_OK;
    }
    else{
         http.end();
        return HTTP_STATUS_ERROR;
    }
    
}
/*******************************************************************************
 * @brief   Calls the http_send_manual_door_status function, if the door state changed. Otherwise it returns a code, that indicated, that no call was made
 * @param   hall_state_t, bool
 *
 * @return  http_code_t
 ******************************************************************************/
http_code_t decide_http_function(hall_state_t door_state, bool door_state_altered){
    if(door_state_altered){
        return http_send_manual_door_status(door_state);
    }
    else{
        return NO_HTTP_REQUEST;
    }
}

