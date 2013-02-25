/*
 * =====================================================================================
 *
 *       Filename:  serveur.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/10/2011 15:45:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVERADDR "127.0.0.1"
#define SERVPORT "0"
#define LISTENLEN 1
#define MAXBUFFERLEN 1024
#define MAXHOSTLEN 64
#define MAXPORTLEN 6

int main(int argc, char** argv) {
	int ecode;
	char serverAddr[MAXHOSTLEN];
	char serverPort[MAXPORTLEN];
	char buffer[MAXBUFFERLEN];
	int descSockRDV;
	int descSockCOM;
	struct addrinfo hints;
	struct addrinfo *res;
	struct sockaddr_storage myinfo;
	struct sockaddr_storage from;
	socklen_t len;

	descSockRDV = socket(AF_INET, SOCK_STREAM, 0);
	if(descSockRDV == -1){
		perror("erreur socket RDV");
		exit(2);
	}
	memset(&hints, 0, sizeof(hints));

	hints.ai_flags = AI_PASSIVE;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_family = AF_INET; 
	ecode = getaddrinfo(SERVERADDR, SERVPORT, &hints, &res);
	if(ecode) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ecode));
		exit(1);
	}

	ecode = bind(descSockRDV, res->ai_addr, res->ai_addrlen);
	if(ecode == -1){
		perror("Erreur liaison de la socket de RDV");	
		exit(3);
	}
	freeaddrinfo(res);

	ecode = getsockname(descSockRDV, (struct sockaddr*) &myinfo, &len);
	if(ecode == -1){
		perror("SERVEUR: getsockname");
		exit(4);
	}
	ecode = getnameinfo((struct sockaddr*)&myinfo, sizeof(myinfo), serverAddr, MAXHOSTLEN, serverPort, MAXPORTLEN, NI_NUMERICHOST | NI_NUMERICSERV);
	if(ecode != 0){
		fprintf(stderr, "error in getnameinfo: %s\n", gai_strerror(ecode));
		exit(4);
	}
	printf("L'adresse d'écoute est %s\n", serverAddr);
	printf("Le port d'écoute est %s", serverPort);

	ecode = listen(descSockRDV, LISTENLEN);
	if(ecode == -1){
		perror("Erreur initialisation buffer d'écoute");
		exit(5);
	}
	descSockCOM = accept(descSockRDV, (struct sockaddr*) &from, &len);
	if(descSockRDV == -1){
		perror("Erreur accept \n");
		exit(6);
	}
	strcpy(buffer, "BLA BLA BLA");
	write(descSockCOM, buffer, strlen(buffer));

	close(descSockCOM);
	close(descSockRDV);
	return EXIT_SUCCESS; 
}
