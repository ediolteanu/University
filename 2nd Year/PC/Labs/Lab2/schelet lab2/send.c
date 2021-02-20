#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "link_emulator/lib.h"
#include "my_msg.h"

#define HOST "127.0.0.1"
#define PORT 10000


int main(int argc,char** argv){
  init(HOST,PORT);
  /*msg t;

  //Send dummy message:
  printf("[send] Sending dummy...\n");
  sprintf(t.payload,"%s", "This is a dummy.");
  t.len = strlen(t.payload)+1;
  send_message(&t);
  
  // Check response:
  if (recv_message(&t)<0){
    perror("Receive error ...");
    return -1;
  }
  else {
    printf("[send] Got reply with payload: %s\n", t.payload);
  }
  */
  msg msg1;
  my_msg msg2;
  char *filename = "tosend.txt";
  sprintf(msg2.payload, "%s", filename);
  msg2.type = 0;
  memcpy(msg1.payload, &msg2, sizeof(int) + strlen(msg2.payload) + 1);
  msg1.len = sizeof(int) + strlen(msg2.payload) + 1;
  send_message(&msg1);
  
  if (recv_message(&msg1) < 0) {
    perror("eroare");
    return -1;
  } else {
    printf("recieved ACK\n");
  }
  
  int fd = open(filename, O_RDONLY);
  int length = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);
  
  memcpy(msg2.payload, &length, sizeof(int));
  msg2.type = 1;
  memcpy(msg1.payload, &msg2, 2*sizeof(int));
  msg1.len = 2*sizeof(int);
  send_message(&msg1);
  if (recv_message(&msg1) < 0) {
    perror("eroare");
    return -1;
  } else {
    printf("recieved ACK\n");
  }
    
  char buff[1396];
  int x, count;
  while(x = read(fd, buff, 1396)) {
    sprintf(msg2.payload, "%s", buff);
    memcpy(msg1.payload, &msg2, sizeof(int) + strlen(msg2.payload) + 1);
    msg1.len = sizeof(int) + strlen(msg2.payload) + 1;
    send_message(&msg1);
  
    if (recv_message(&msg1) < 0) {
      perror("eroare");
      return -1;
    } else {
      printf("recieved ACK\n");
    }
  }
  close(fd);
  
  return 0;
}
