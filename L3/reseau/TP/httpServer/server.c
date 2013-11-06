#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TAILLEMAXPORT 10000

void error(char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno, clilen;
	char buffer;
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
		portno = 8765;
		if ((portno < 0) && (portno > TAILLEMAXPORT)){
				error("ERROR port number");
			}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr,
							sizeof(serv_addr)) < 0)
		error("ERROR on binding");
		
	listen(sockfd,5);
	clilen = sizeof(cli_addr);
	
	newsockfd = accept(sockfd,
			(struct sockaddr *) &cli_addr,
			(socklen_t*) &clilen);
			
	if (newsockfd < 0)
		error("ERROR on accept");
		
	do {
		n = read(newsockfd,&buffer,1);
		write(newsockfd,&buffer, 1);
	} while(n>-1);
	
	return 0;
}
