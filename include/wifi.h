#ifndef WIFI_H
#define WIFI_H


typedef enum {
    WIFI_STATUS_OK = 0,
    WIFI_STATUS_TIMEOUT = 1,
    WIFI_STATUS_ERROR = 2
} wifi_status_t;

wifi_status_t wifi_init(void);
wifi_status_t wifi_check_connection(void);
void handle_wifi_status(wifi_status_t);


#endif

