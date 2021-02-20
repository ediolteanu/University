#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10000

int main(int argc, char *argv[])
{
	msg t;
	int i, res;
	t.stop = 0;
	t.rlc = 0;
	printf("[SENDER] Starting.\n");	
	init(HOST, PORT);

	//printf("[SENDER]: BDP=%d\n", atoi(argv[1]));
	
	char *filename = "de_citit.txt";
  int fd = open(filename, O_RDONLY);
  char buf[1400];
  int current_size = 0;
  int x;
  
  int bdp = atoi(argv[1]);
  float window_size = (bdp * 1000) / (sizeof(msg) * 8);
  printf("%f\n", window_size);
  
  while (x = read(fd, buf, sizeof(buf))) {
    sprintf(t.payload, "%s", buf);  
    t.len = MSGSIZE;
    for (int i = 0; i < strlen(t.payload); i++)
      t.rlc = t.rlc ^ t.payload[i];
    send_message(&t);
    current_size += 1;
    if (current_size == window_size) break;
  }
    
  if (recv_message(&t) < 0) {
    perror("eroare");
    return -1;
  } else {
    printf("recieved ACK\n");
  }
  
  while (x = read(fd, buf, sizeof(buf))) {
    sprintf(t.payload, "%s", buf);  
    t.len = MSGSIZE;
    for (int i = 0; i < strlen(t.payload); i++)
      t.rlc = t.rlc ^ t.payload[i];
    if (!(x = read(fd, buf, sizeof(buf)))) t.stop = 1;
    send_message(&t);
    if (recv_message(&t) < 0) {
      perror("eroare");
      return -1;
    } else {
      printf("recieved ACK\n");
    }
    
      
  }
  
  
  close(fd);
  
	/*for (i = 0; i < COUNT; i++) {
		/* cleanup msg 
		memset(&t, 0, sizeof(msg));
		
		/* gonna send an empty msg 
		t.len = MSGSIZE;
		
		/* send msg 
		res = send_message(&t);
		if (res < 0) {
			perror("[SENDER] Send error. Exiting.\n");
			return -1;
		}
		
		/* wait for ACK 
		res = recv_message(&t);
		if (res < 0) {
			perror("[SENDER] Receive error. Exiting.\n");
			return -1;
		}
	}*/

	printf("[SENDER] Job done, all sent.\n");
		
	return 0;
}
