#ifndef WIFI_H
#define WIFI_H
#include "debug_handler.h"



system_code_t wifi_init(void);
system_code_t wifi_check_connection(void);
void handle_wifi_status(system_code_t);


#endif

