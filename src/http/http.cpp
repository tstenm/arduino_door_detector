
#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <stdint.h>
#include "http.h"
#include "hall_sensor.h"
#include "debug_handler.h"


static const char* servername = "https://87.106.5.130/door_state_altered";



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
    int httpResponseCode = http.GET();  
    if(httpResponseCode == HTTP_CODE_OK){
        return HTTP_STATUS_OK;
    }
    else{
        return HTTP_STATUS_ERROR;
    }
     http.end();
}

http_code_t decide_http_function(hall_state_t door_state, bool door_state_altered){
    if(door_state_altered){
        return http_send_manual_door_status(door_state);
    }
    else{
        return NO_HTTP_REQUEST;
    }
}

