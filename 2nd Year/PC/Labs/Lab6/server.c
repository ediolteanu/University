/*
*  	Protocoale de comunicatii: 
*  	Laborator 6: UDP
*	mini-server de backup fisiere
*/

#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include "helpers.h"


void usage(char*file)
{
	fprintf(stderr,"Usage: %s server_port file\n",file);
	exit(0);
}

/*
*	Utilizare: ./server server_port nume_fisier
*/
int main(int argc,char**argv)
{
	int fd;

	if (argc!=3)
		usage(argv[0]);
	
	struct sockaddr_in my_sockaddr, from_station ;
	char buf[BUFLEN];


	/*Deschidere socket*/
	int sockfd = socket(PF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
	  printf("\nEROARE SOCKET\n");
	}
	
	/*Setare struct sockaddr_in pentru a asculta pe portul respectiv */
  my_sockaddr.sin_family = AF_INET;
	my_sockaddr.sin_port = htons(atoi(argv[1]));
	
	struct in_addr saddr;
	saddr.s_addr = INADDR_ANY;
	my_sockaddr.sin_addr = saddr;
	
	/* Legare proprietati de socket */
  int rs = bind(sockfd, (struct sockaddr *) &my_sockaddr, sizeof(my_sockaddr));
	if (rs == -1) {
   /* trateaza eroare */
   printf("EROARE BIND");
  }
	
	/* Deschidere fisier pentru scriere */
	DIE((fd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644))==-1,"open file");
	
	/*
	*  cat_timp  mai_pot_citi
	*		citeste din socket
	*		pune in fisier
	*/
	int x;
	socklen_t addrlen;
	printf("while recv1\n");
	int bytesread = recvfrom(sockfd, buf, BUFLEN, 0, 
              (struct sockaddr *) &from_station, &addrlen);
  printf("while recv\n");
  while ((bytesread > 0)) {
    printf("while recv\n");
    printf("%s", buf);
    x = write(fd, buf, bytesread);
    if (x == -1) {
    /* trateaza eroare */
      printf("\nEROARE \n");
    }
    bytesread = recvfrom(sockfd, buf, BUFLEN, 0, 
              (struct sockaddr *) &from_station, &addrlen);
    if (bytesread == -1) {
    /* trateaza eroare */
      printf("\nEROARE RECV\n");
    }
  }

	/*Inchidere socket*/	
  close(sockfd);
	
	/*Inchidere fisier*/
  close(fd);
	return 0;
}
