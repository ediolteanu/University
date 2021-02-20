// Protocoale de comunicatii
// Laborator 9 - DNS
// dns.c

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int usage(char* name)
{
	printf("Usage:\n\t%s -n <NAME>\n\t%s -a <IP>\n", name, name);
	return 1;
}

// Receives a name and prints IP addresses
void get_ip(char* name)
{
	int ret, rc;
	struct addrinfo hints, *result, *p;

	// TODO: set hints
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	
	// TODO: get addresses
  ret = getaddrinfo(name, NULL, &hints, &result);
  if (ret != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
    exit(EXIT_FAILURE);
  }
  
	// TODO: iterate through addresses and print them
	
	printf("Flags\tPort\tFamily\tSock\tProtocol\tAddress\n");
  for (p = result; p != NULL; p = p->ai_next) {
    if (p->ai_family == AF_INET) {
      char dst[INET_ADDRSTRLEN];
      struct sockaddr_in *aux = (struct sockaddr_in *) p->ai_addr;
      inet_ntop(p->ai_family, &aux->sin_addr, dst,
                          sizeof(struct sockaddr_in));
      printf("%d\t%d\t%d\t%d\t%d\t%s\n", p->ai_flags, aux->sin_port, p->ai_family, 
                                    p->ai_socktype, p->ai_protocol, dst);
    } 
    if (p->ai_family == AF_INET6) {
      char dst[INET6_ADDRSTRLEN];
      struct sockaddr_in6 *aux6 = (struct sockaddr_in6 *) p->ai_addr;
      inet_ntop(p->ai_family, &aux6->sin6_addr, dst,
                          sizeof(struct sockaddr_in6));
      printf("%d\t%d\t%d\t%d\t%d\t%s\n", p->ai_flags, aux6->sin6_port, p->ai_family, 
                                    p->ai_socktype, p->ai_protocol, dst);
    }
    
  }
  
	// TODO: free allocated data
	freeaddrinfo(result);
}

// Receives an address and prints the associated name and service
void get_name(char* ip)
{
	int ret;
	struct sockaddr_in addr;
	char host[1024];
	char service[20];

	// TODO: fill in address data
	memset(&addr, 0, sizeof(struct sockaddr_in));
  addr.sin_port = htons(80);
  addr.sin_family = AF_INET;
  struct in_addr aux;
  inet_aton(ip, &aux);
  addr.sin_addr = aux;
	// TODO: get name and service
  ret = getnameinfo((struct sockaddr *) &addr, sizeof(struct sockaddr),
              host, sizeof(host), service, sizeof(service), 0);
	// TODO: print name and service
	printf("%s\t%s\n", host, service);
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		return usage(argv[0]);
	}

	if (strncmp(argv[1], "-n", 2) == 0) {
		get_ip(argv[2]);
	} else if (strncmp(argv[1], "-a", 2) == 0) {
		get_name(argv[2]);
	} else {
		return usage(argv[0]);
	}

	return 0;
}
