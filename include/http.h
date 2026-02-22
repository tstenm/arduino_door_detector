#ifndef HTTP_H
#define HTTP_H

typedef enum {
    HTTP_STATUS_OK = 200,
    HTTP_STATUS_ERROR = -1,
} http_code_t;

http_code_t http_check_connection(void);


#endif

