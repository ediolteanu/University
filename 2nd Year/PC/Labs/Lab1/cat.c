#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void tac(char *token) 
{
  token = strtok(NULL, "\n");
  if (token != NULL) {
    tac(token);
    printf("%s\n", token);
  }
}

int main()
{
  int file = open("de_afisat.txt", O_RDONLY);
  
  char buff[1000];
  int x = read(file, buff, 1000);
  
  printf("%s", buff);
  
  printf("\n");
  
  char *token = strtok(buff, "\n");
  tac(token); 
  printf("%s\n", token);
  close(file);
}


