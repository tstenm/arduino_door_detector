#ifndef WIFI_H
#define WIFI_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    WIFI_STATUS_OK = 0,
    WIFI_STATUS_TIMEOUT = 1,
    WIFI_STATUS_ERROR = 2
} wifi_status_t;

wifi_status_t wifi_init(void);
wifi_status_t wifi_check_connection(void);
void handle_wifi_status(wifi_status_t);
#ifdef __cplusplus
}
#endif

#endif

