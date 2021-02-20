#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <string.h>     
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netdb.h>
#include <arpa/inet.h>
#include "helpers.h"
#include "requests.h"

int get_code(char *message) {
  char *copy = (char *) malloc(strlen(message) * sizeof(char));
  strcpy(copy, message);
  char *token;
  token = strtok(copy, " ");
  token = strtok(NULL, " ");
  int code = atoi(token);
  return code;
}

char *get_cookie(char *message) {
  char *copy = (char *) malloc(strlen(message) * sizeof(char));
  strcpy(copy, message);
  char *token;
  char *token2;
  token = strtok(copy, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token2 = strtok(token, " ");
  token2 = strtok(NULL, " ");
  token2[strlen(token2) - 1] = 0;
  return token2;
}

char *get_jwt(char *message) {
  char *copy = (char *) malloc(strlen(message) * sizeof(char));
  strcpy(copy, message);
  char *token;
  char *token2;
  token = strtok(copy, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token = strtok(NULL, "\n");
  token2 = strtok(token, "\"");
  token2 = strtok(NULL, "\"");
  token2 = strtok(NULL, "\"");
  token2 = strtok(NULL, "\"");
  return token2;
}

int verify_integer(char *in) {
  for(int i = 0; i < strlen(in); i++) {
    if ((in[i] < 48) || (in[i] > 57))
      return 0;
  }
  return 1;
}

int main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0) ;
    char *message;
    char *response;
    int sockfd;
    char buf[20];
    char username[100], password[100], title[1000], author[100];
    char genre[100], publisher[100], id[100], page_count[100];
    int code;
    char **cookies = (char **) malloc(sizeof(char *));
    int cookies_nr = 0;
    int isLogged = 0;
    char *jwt;
    char **data;
    
    while(1) {
      memset(buf, 0, sizeof(buf));
      read(0, buf, sizeof(buf));
      if (strcmp(buf, "register\n") == 0) {
        memset(username, 0, sizeof(username));
        memset(password, 0, sizeof(password));
        printf("username=");
        read(0, username, sizeof(username));
        username[strlen(username) - 1] = 0;
        printf("password=");
        read(0, password, sizeof(password));
        password[strlen(password) - 1] = 0;
        
        sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
        
        char **data = malloc(sizeof(char *));
        data[0] = calloc(LINELEN, sizeof(char));
        strcat(data[0], "{\"username\":\"");
        strcat(data[0], username);
        strcat(data[0], "\",");
        strcat(data[0], "\"password\":\"");
        strcat(data[0], password);
        strcat(data[0], "\"}");
        
        message = compute_post_request(
                  "ec2-3-8-116-10.eu-west-2.compute.amazonaws.com", 
                  "/api/v1/tema/auth/register", "application/json",
                  data, 1, NULL, NULL, 0);
        send_to_server(sockfd, message);
        
        response = receive_from_server(sockfd);
        code = get_code(response);
        
        if (code == 201) {
          printf("Succes! Contul a fost creat.\n");
        } else {
          printf("Eroare! Username-ul deja exista.\n");
        }
        
        close_connection(sockfd);
        
      } else if (strcmp(buf, "login\n") == 0) {
        if (isLogged) {
          printf("Un cont este deja logat!\n");
        } else {
          memset(username, 0, sizeof(username));
          memset(password, 0, sizeof(password));
          printf("username=");
          read(0, username, sizeof(username));
          username[strlen(username) - 1] = 0;
          printf("password=");
          read(0, password, sizeof(password));
          password[strlen(password) - 1] = 0;
          
          sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
          
          data = (char **) malloc(sizeof(char *));
          data[0] = calloc(LINELEN, sizeof(char));
          strcat(data[0], "{\"username\":\"");
          strcat(data[0], username);
          strcat(data[0], "\",");
          strcat(data[0], "\"password\":\"");
          strcat(data[0], password);
          strcat(data[0], "\"}");
          
          message = compute_post_request(
                    "ec2-3-8-116-10.eu-west-2.compute.amazonaws.com", 
                    "/api/v1/tema/auth/login", "application/json", 
                    data, 1, NULL, NULL, 0);
          send_to_server(sockfd, message);
          
          response = receive_from_server(sockfd);
          code = get_code(response);
          if (code == 200) {
            printf("Succes! V-ati logat.\n");
            isLogged = 1;
            cookies[0] = (char *) malloc(LINELEN * sizeof(char));
            strcpy(cookies[0], get_cookie(response));
            cookies_nr = 1;
          } else {
            printf("Eroare! Credentialele nu se potrivesc.\n");
          }
          
          close_connection(sockfd);
        }
      } else if (strcmp(buf, "enter_library\n") == 0) {
        sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
        
        message = compute_get_request(
                        "ec2-3-8-116-10.eu-west-2.compute.amazonaws.com", 
                        "/api/v1/tema/library/access", NULL, NULL, NULL,
                        cookies, cookies_nr);
        
        send_to_server(sockfd, message);
          
        response = receive_from_server(sockfd);
        code = get_code(response);
        if (code == 200) {
          printf("Succes! Ati primit acces la biblioteca.\n");
          jwt = (char *) malloc(LINELEN * sizeof(char));
          strcpy(jwt, get_jwt(response));
        } else {
          printf("Eroare! Nu ati demonstrat ca sunteti autentificat.\n");
        }
        
        close_connection(sockfd);
        
      } else if (strcmp(buf, "get_books\n") == 0) {
        sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
        
        message = compute_get_request(
                        "ec2-3-8-116-10.eu-west-2.compute.amazonaws.com", 
                        "/api/v1/tema/library/books", NULL, jwt, NULL,
                        cookies, cookies_nr);
        send_to_server(sockfd, message);
          
        response = receive_from_server(sockfd);
        code = get_code(response);
        
        if (code == 200) {
          printf("Succes! Ati primit cartile.\n");
          printf("%s\n", basic_extract_json_response(response));
        } else {
          printf("Eroare! Nu ati demonstrat ca aveti acces la biblioteca.\n");
        }
        
        close_connection(sockfd);
        
      } else if (strcmp(buf, "get_book\n") == 0) {
        memset(id, 0, sizeof(id));
        printf("id=");
        read(0, id, sizeof(id));
        id[strlen(id) - 1] = 0;
        while(!verify_integer(id)) {
          printf("Id trebuie sa fie numar!\n");
          printf("id=");
          memset(id, 0, sizeof(id));
          read(0, id, sizeof(id));
          id[strlen(id) - 1] = 0;
        }
        
        sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
        
        message = compute_get_request(
                        "ec2-3-8-116-10.eu-west-2.compute.amazonaws.com", 
                        "/api/v1/tema/library/books", NULL, jwt, id,
                        cookies, cookies_nr);
        send_to_server(sockfd, message);
        
        response = receive_from_server(sockfd);
        code = get_code(response);

        if (code == 200) {
          printf("Succes! Ati primit cartea.\n");
          printf("%s\n", basic_extract_json_response(response));
        } else if (code == 404) {
          printf("Cartea cu id-ul %s nu exista!\n", id);
        } else {
          printf("Eroare! Nu ati demonstrat ca aveti acces la biblioteca.\n");
        }
        
        close_connection(sockfd);
      
      } else if (strcmp(buf, "add_book\n") == 0) {
        memset(title, 0, sizeof(title));
        memset(author, 0, sizeof(author));
        memset(genre, 0, sizeof(genre));
        memset(publisher, 0, sizeof(publisher));
        memset(page_count, 0, sizeof(page_count));
        printf("title=");
        read(0, title, sizeof(title));
        title[strlen(title) - 1] = 0;
        printf("author=");
        read(0, author, sizeof(author));
        author[strlen(author) - 1] = 0;
        printf("genre=");
        read(0, genre, sizeof(genre));
        genre[strlen(genre) - 1] = 0;
        printf("publisher=");
        read(0, publisher, sizeof(publisher));
        publisher[strlen(publisher) - 1] = 0;
        printf("page_count=");
        read(0, page_count, sizeof(page_count));
        page_count[strlen(page_count) - 1] = 0;
        while(!verify_integer(page_count)) {
          printf("page_count trebuie sa fie numar!\n");
          printf("page_count=");
          memset(page_count, 0, sizeof(page_count));
          read(0, page_count, sizeof(page_count));
          page_count[strlen(page_count) - 1] = 0;
        }
        
        data = (char **) malloc(sizeof(char *));
        data[0] = calloc(LINELEN, sizeof(char));
        strcat(data[0], "{\"title\":\"");
        strcat(data[0], title);
        strcat(data[0], "\",");
        strcat(data[0], "\"author\":\"");
        strcat(data[0], author);
        strcat(data[0], "\",");
        strcat(data[0], "\"publisher\":\"");
        strcat(data[0], publisher);
        strcat(data[0], "\",");
        strcat(data[0], "\"genre\":\"");
        strcat(data[0], genre);
        strcat(data[0], "\",");
        strcat(data[0], "\"page_count\":\"");
        strcat(data[0], page_count);
        strcat(data[0], "\"}");
        
        sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
        
        message = compute_post_request(
                        "ec2-3-8-116-10.eu-west-2.compute.amazonaws.com", 
                        "/api/v1/tema/library/books", "application/json",
                        data, 1, jwt, cookies, cookies_nr);
        send_to_server(sockfd, message);
        
        response = receive_from_server(sockfd);
        code = get_code(response);
        
        if (code == 200) {
          printf("Succes! Ati adaugat cartea.\n");
        } else {
          printf("Eroare! Nu ati demonstrat ca aveti acces la biblioteca.\n");
        }
        
        close_connection(sockfd);
      
      } else if (strcmp(buf, "delete_book\n") == 0) {
        memset(id, 0, sizeof(id));
        printf("id=");
        read(0, id, sizeof(id));
        id[strlen(id) - 1] = 0;
        while(!verify_integer(id)) {
          printf("Id trebuie sa fie numar!\n");
          printf("id=");
          memset(id, 0, sizeof(id));
          read(0, id, sizeof(id));
          id[strlen(id) - 1] = 0;
        }
        
        sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
        
        message = compute_delete_request(
                        "ec2-3-8-116-10.eu-west-2.compute.amazonaws.com", 
                        "/api/v1/tema/library/books", NULL, jwt, id,
                        cookies, cookies_nr);
        send_to_server(sockfd, message);
        
        response = receive_from_server(sockfd);
        code = get_code(response);
        
        if (code == 200) {
          printf("Succes! Ati sters cartea.\n");
        } else if (code == 404) {
          printf("Cartea cu id-ul %s nu exista!\n", id);
        } else {
          printf("Eroare! Nu ati demonstrat ca aveti acces la biblioteca.\n");
        }
        
        close_connection(sockfd);
      
      } else if (strcmp(buf, "logout\n") == 0) {
        if (isLogged) {
          sockfd = open_connection("3.8.116.10", 8080, AF_INET, SOCK_STREAM, 0);
          
          message = compute_get_request(
                        "ec2-3-8-116-10.eu-west-2.compute.amazonaws.com", 
                        "/api/v1/tema/auth/logout", NULL, NULL, NULL,
                        cookies, cookies_nr);
          send_to_server(sockfd, message);
          
          response = receive_from_server(sockfd);
          code = get_code(response);
          
          if (code == 200) {
            printf("Succes! V-ati delogat.\n");
            isLogged = 0;
            free(cookies[0]);
            cookies_nr = 0;
            free(jwt);
          } else {
            printf("Eroare! Nu ati demonstrat ca sunteti autentificat.\n");
          }
        } else {
          printf("Nu sunteti logat!\n");
        }
      } else if (strcmp(buf, "exit\n") == 0) {
        printf("Programul a fost inchis!\n");
        break;
      } else {
        printf("Comanda introdusa nu exista!\n");
      }
    }
    
    return 0;
}
