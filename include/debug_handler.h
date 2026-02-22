#pragma once
typedef enum {
    WIFI_STATUS_OK = 0,
    WIFI_STATUS_TIMEOUT = 1,
    WIFI_STATUS_ERROR = 2,
    HTTP_OK = 200,
} system_code_t;



void debug_handler(system_code_t);