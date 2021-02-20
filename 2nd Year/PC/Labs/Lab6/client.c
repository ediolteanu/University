#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include "helpers.h"
#include <arpa/inet.h>

void usage(char*file)
{
	fprintf(stderr,"Usage: %s ip_server port_server file\n",file);
	exit(0);
}

/*
*	Utilizare: ./client ip_server port_server nume_fisier_trimis
*/
int main(int argc,char**argv)
{
	if (argc!=4)
		usage(argv[0]);

	int fd;
	char buf[BUFLEN];

	
	int sockfd = socket(PF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    printf("EROARE SOCKET\n");
  }
	/* Deschidere fisier pentru citire */
	DIE((fd=open(argv[3],O_RDONLY))==-1,"open file");

	
	struct sockaddr_in to_station;
	to_station.sin_family = AF_INET;
	to_station.sin_port = htons(atoi(argv[2]));
	inet_aton(argv[1], &(to_station.sin_addr));
	
	/*
	*  cat_timp  mai_pot_citi
	*		citeste din fisier
	*		trimite pe socket
	*/
	int x = read(fd, buf, BUFLEN);
	while(x > 0){
		int bytessent = sendto(sockfd, buf, x, 0, 
		      (struct sockaddr *) &to_station, sizeof(to_station));
		x = read(fd, buf, BUFLEN);  
		printf("while client\n");   
		if (bytessent == -1)
		{
		  printf("EROARE SEND\n");
		}
	}

	int socket_close = close(sockfd);

	if(socket_close == -1) {
		printf("error socket close\n");
	}

	close(fd);
	return 0;
}
