#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10001

int main(void)
{
	msg r, t;
	int i, res;
	t.rlc = 0;
	printf("[RECEIVER] Starting.\n");
	init(HOST, PORT);
	
	while(1) {
	  
	  res = recv_message(&r);
	  for (int i = 0; i < strlen(r.payload); i++)
	    t.rlc = t.rlc ^ r.payload[i];
	  if (res < 0) {
			perror("[RECEIVER] Receive error. Exiting.\n");
			return -1;
		}
		if (r.stop == 1) break;
		res = send_message(&r);
		if (res < 0) {
			perror("[RECEIVER] Send ACK error. Exiting.\n");
			return -1;
		}
	}
	if (t. rlc == r. rlc) printf("E bine.\n");
	/*for (i = 0; i < COUNT; i++) {
		/* wait for message 
		res = recv_message(&r);
		if (res < 0) {
			perror("[RECEIVER] Receive error. Exiting.\n");
			return -1;
		}
		
		/* send dummy ACK 
		res = send_message(&r);
		if (res < 0) {
			perror("[RECEIVER] Send ACK error. Exiting.\n");
			return -1;
		}
	}*/

	printf("[RECEIVER] Finished receiving..\n");
	return 0;
}
