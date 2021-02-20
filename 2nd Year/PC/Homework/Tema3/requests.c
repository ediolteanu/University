#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "helpers.h"
#include "requests.h"

char *compute_get_request(char *host, char *url, char *query_params, char *jwt,
                          char *extra, char **cookies, int cookies_count)
{
    char *message = calloc(BUFLEN, sizeof(char));
    char *line = calloc(LINELEN, sizeof(char));

    if (query_params != NULL) {
        sprintf(line, "GET %s?%s HTTP/1.1", url, query_params);
    } else {
        if (extra != NULL) {
          sprintf(line, "GET %s/%s HTTP/1.1", url, extra);
        } else {
          sprintf(line, "GET %s HTTP/1.1", url);
        }
    }
    compute_message(message, line);

    memset(line, 0, LINELEN);
    strcat(line, "Host: ");
    strcat(line, host);
    compute_message(message, line);
    
    if (jwt != NULL) {
      memset(line, 0, LINELEN);
      strcat(line, "Authorization: Bearer ");
      strcat(line, jwt);
      compute_message(message, line);
    }

    if (cookies != NULL) {
      memset(line, 0, LINELEN);
      strcat(line, "Cookie: ");
      for (int i = 0; i < cookies_count; i++) {
        strcat(line, cookies[i]);
      }
      compute_message(message, line);
    }
    compute_message(message, "");
    
    return message;
}

char *compute_post_request(char *host, char *url, char* content_type, char **body_data,
                            int body_data_fields_count, char *jwt, char **cookies, int cookies_count)
{
    char *message = calloc(BUFLEN, sizeof(char));
    char *line = calloc(LINELEN, sizeof(char));
    char *body_data_buffer = calloc(LINELEN, sizeof(char));

    sprintf(line, "POST %s HTTP/1.1", url);
    compute_message(message, line);
    
    memset(line, 0, LINELEN);
    strcat(line, "Host: ");
    strcat(line, host);
    compute_message(message, line);

    memset(line, 0, LINELEN);
    strcat(line, "Content-Type: ");
    strcat(line, content_type);
    compute_message(message, line);
    
    for (int i = 0; i < body_data_fields_count; i++) {
      strcat(body_data_buffer, body_data[i]);
      if (i != body_data_fields_count - 1) {
        strcat(body_data_buffer, "&");
      }
    }
    int len = strlen(body_data_buffer);
    
    memset(line, 0, LINELEN);
    sprintf(line, "Content-Length: %d", len);
    compute_message(message, line);

    if (jwt != NULL) {
      memset(line, 0, LINELEN);
      strcat(line, "Authorization: Bearer ");
      strcat(line, jwt);
      compute_message(message, line);
    }
    if (cookies != NULL) {
      memset(line, 0, LINELEN);
      strcat(line, "Cookie: ");
      for (int i = 0; i < cookies_count; i++) {
        strcat(line, cookies[i]);
        strcat(line, "; ");
      }
      compute_message(message, line);
    }
    compute_message(message, "");

    memset(line, 0, LINELEN);
    compute_message(message, body_data_buffer);

    free(line);
    return message;
}
char *compute_delete_request(char *host, char *url, char *query_params, char *jwt,
                          char *extra, char **cookies, int cookies_count)
{
    char *message = calloc(BUFLEN, sizeof(char));
    char *line = calloc(LINELEN, sizeof(char));

    if (query_params != NULL) {
        sprintf(line, "DELETE %s?%s HTTP/1.1", url, query_params);
    } else {
        if (extra != NULL) {
          sprintf(line, "DELETE %s/%s HTTP/1.1", url, extra);
        } else {
          sprintf(line, "DELETE %s HTTP/1.1", url);
        }
    }
    compute_message(message, line);

    memset(line, 0, LINELEN);
    strcat(line, "Host: ");
    strcat(line, host);
    
    compute_message(message, line);
    
    if (jwt != NULL) {
      memset(line, 0, LINELEN);
      strcat(line, "Authorization: Bearer ");
      strcat(line, jwt);
      compute_message(message, line);
    }
    
    if (cookies != NULL) {
      memset(line, 0, LINELEN);
      strcat(line, "Cookie: ");
      for (int i = 0; i < cookies_count; i++) {
        strcat(line, cookies[i]);
      }
      compute_message(message, line);
    }
    compute_message(message, "");
    
    return message;
}

