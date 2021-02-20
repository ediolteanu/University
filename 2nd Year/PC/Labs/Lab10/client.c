#include <stdio.h>      /* printf, sprintf */
#include <stdlib.h>     /* exit, atoi, malloc, free */
#include <unistd.h>     /* read, write, close */
#include <string.h>     /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h>      /* struct hostent, gethostbyname */
#include <arpa/inet.h>
#include "helpers.h"
#include "requests.h"

int main(int argc, char *argv[])
{
    char *message;
    char *response;
    int sockfd;

    sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
    
    // Ex 1.1: GET dummy from main server
    message = compute_get_request("ec2-3-8-116-10.eu-west-2.compute.amazonaws.com",
              "/api/v1/dummy", NULL, NULL, 0);
    printf("%s\n", message);
    // Ex 1.2: POST dummy and print response from main server
    char **data = malloc(sizeof(char *));
    data[0] = calloc(LINELEN, sizeof(char));
    strcat(data[0], "Salut!\n");
    message = compute_post_request("ec2-3-8-116-10.eu-west-2.compute.amazonaws.com",
              "/api/v1/dummy", 
              "application/x-www-form-urlencoded", data, 1, NULL, 0);
    send_to_server(sockfd, message);
    response = receive_from_server(sockfd);
    printf("%s\n", response);
    // Ex 2: Login into main server
    
    char **cookies = malloc(sizeof(char *));
    cookies[0] = calloc(300, sizeof(char));
    //strcat(cookies[0], "username=student");
    //strcat(cookies[1], "password=student");
    
    //char **data = malloc(sizeof(char *));
    data[0] = calloc(LINELEN, sizeof(char));
    data[1] = calloc(LINELEN, sizeof(char));
    strcat(data[0], "username=student");
    strcat(data[1], "password=student");
    message = compute_post_request("ec2-3-8-116-10.eu-west-2.compute.amazonaws.com",
              "/api/v1/auth/login", 
              "application/x-www-form-urlencoded", data, 2, cookies, 0);
    send_to_server(sockfd, message);
    response = receive_from_server(sockfd);
    printf("%s\n", response);
    
    strcat(cookies[0], "connect.sid=s%3AaLWJuqQIhobjFh2H3_Cjh4KRXGRVsBvy.HKUyiV92m3t7AIbZfxhTfM3XZmppLNsFQBMx01MU8uE; Path=/; HttpOnly");
    message = compute_get_request("ec2-3-8-116-10.eu-west-2.compute.amazonaws.com",
              "/api/v1/weather/key", NULL, cookies, 1);
    send_to_server(sockfd, message);
    response = receive_from_server(sockfd);
    printf("%s\n", response);
    
    message = compute_get_request("ec2-3-8-116-10.eu-west-2.compute.amazonaws.com",
              "/api/v1/auth/logout", NULL, cookies, 1);
    send_to_server(sockfd, message);
    response = receive_from_server(sockfd);
    printf("%s\n", response);
    // Ex 3: GET weather key from main server
    // Ex 4: GET weather data from OpenWeather API
    // Ex 5: POST weather data for verification to main server
    // Ex 6: Logout from main server

    // BONUS: make the main server return "Already logged in!"

    // free the allocated data at the end!

    return 0;
}
