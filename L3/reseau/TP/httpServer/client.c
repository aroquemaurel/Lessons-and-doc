#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdbool.h>
#include <fcntl.h>

#include "util.h"

typedef enum { GET, PUT, TEST} TypeQuery;

void error(char *msg, const int code);
char* error_usage(void);
void query(const int sockfd, char* msg, char* file, const TypeQuery test);
void get(const int sockfd, char* file);
void put(const int sockfd, char* file);
void decaler(char* buff);
bool supprimerEntete(char c);


int main(int argc, char *argv[]) {
	int portno, sockfd;
	char buffer[256];
	char* file = argv[4];
	struct sockaddr_in serv_addr;
	struct hostent *server;

	// Arguments error
	if((strcmp(argv[1], "get") != 0 && strcmp(argv[1], "put") != 0 && strcmp(argv[1], "test") != 0) || argc != 5) {
		strcpy(buffer, error_usage());
		error(buffer, 2);
	}
	
	portno = atoi(argv[3]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		error("ERROR opening socket", 1);
	}

	server = gethostbyname(argv[2]);
	if (server == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	
	if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)  {
		error("ERROR connecting", 3);
	}
		
	if(strcmp(argv[1], "get") == 0){
		get(sockfd, file);
	} else if(strcmp(argv[1], "put") == 0) {

	} else if(strcmp(argv[1], "test") == 0) {
		strcat(buffer, argv[4]);
		strcat(buffer, "\r\n\r\n");
		query(sockfd, buffer, NULL, TEST);
	}

	
	return 0;
}

void get(const int sockfd, char* file) {
	char msg[256] = "GET ";

	strcat(msg, file);
	strcat(msg, " HTTP/1.0\r\n\r\n");

	query(sockfd, msg, file, GET);
}

void put(const int sockfd, char* file) {
}

void query(const int sockfd, char* msg, char* file, const TypeQuery typeQuery) {
	char buffer[256];
	bool beginFile = false;
	char answer;
	char buff[4];
	int i = 0;
	int nbChars = 0;
	char** split;
	int output;

	if(typeQuery == GET) {
		split = str_split(file,'/');

		for(i=0 ; split[i] != NULL ; ++i);
		strcpy(buffer, "./");
		strcat(buffer, split[i-1]);
		output = open(buffer, O_CREAT|O_WRONLY, 0755); 
	}

	// send requete
	for(i=0 ; i < strlen(msg); ++i) {
		write(sockfd,msg+i,1);
	}

	// get result
	while(read(sockfd,&answer,1) != 0) {
			switch(typeQuery) {
				case GET:
					if(beginFile) {
						write(output, &answer, 1); 
					} else if(typeQuery == GET) {
						beginFile = supprimerEntete(answer);
					}
					break;
				case PUT:
				case TEST:
					printf("%c", answer); 
					break;
			}
			// Fin de l'entête == premier \r\n\r\n 
	}
}

bool supprimerEntete(char c) {
	static int nbChars = 0;
	bool ret = false;
	if(nbChars % 2 ==0) { // on attend un \r
		if(c == '\r') {
			++nbChars;
		} else {
			nbChars = 0;
		}
	} else { // on attend  // on attend un \n
		if(c == '\n') {
			++nbChars;
		} else {
			nbChars = 0;
		}
	}

	if(nbChars == 4) {
		ret = true;
	}

	return ret;

}

void decaler(char* tab) {
	int i;
	for(i = 0 ; i < 3 ; ++i) {
		tab[i] = tab[i+1];
	}

}
char* error_usage(void) {
	return "usage: ./client get|put|test hostname portno file";
}

void error(char *msg, const int code) {
	fprintf(stderr, msg);
	exit(code);
}
