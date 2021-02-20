#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "link_emulator/lib.h"
#include "my_msg.h"

#define HOST "127.0.0.1"
#define PORT 10001


int main(int argc,char** argv){
  //msg r;
  init(HOST,PORT);

  /*if (recv_message(&r)<0){
    perror("Receive message");
    return -1;
  }
  printf("[recv] Got msg with payload: <%s>, sending ACK...\n", r.payload);

  // Send ACK:
  sprintf(r.payload,"%s", "ACK");
  r.len = strlen(r.payload) + 1;
  send_message(&r);
  printf("[recv] ACK sent\n");
  */
  msg t, r;
  char filename[100];
  if (recv_message(&r) < 1) {
    perror("eroare");
    return -1;
  }
  printf("filename: %s\n", r.payload + sizeof(int));
  
  sprintf(t.payload, "ACK(%s)", r.payload + sizeof(int));
  t.len = r.payload + sizeof(int);
  send_message(&t);
 
  if (recv_message(&r) < 1) {
    perror("eroare");
    return -1;
  }
  int l;
  memcpy(&l, r.payload + sizeof(int), sizeof(int));
  printf("length: %d\n", l);
  sprintf(t.payload, "ACK(%s)", r.payload + sizeof(int));
  t.len = r.payload + sizeof(int);
  send_message(&t);
  
  while (l > 0) {
    if (recv_message(&r) < 1) {
      perror("eroare");
      return -1;
    }
    printf("text: %s\n", r.payload + sizeof(int));
    printf("lung: %d\n", r.len);
    l -= 1396;
    sprintf(t.payload, "ACK(%s)", r.payload + sizeof(int));
    t.len = r.payload + sizeof(int);
    send_message(&t);
  }
  return 0;
}
