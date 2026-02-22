
#include <Arduino.h>
#include "http.h"
#include "debug_handler.h"
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

static const char* servername = "https://87.106.5.130/door_state_altered";

system_code_t http_send_negate() {

    WiFiClientSecure client;
    client.setInsecure();   // ⚠️ akzeptiert jedes Zertifikat (nur zum Testen!)

    HTTPClient http;
    http.begin(client, servername);

    int httpResponseCode = http.GET();
    Serial.println(httpResponseCode);

    http.end();
    delay(1000);
    return HTTP_OK;

}