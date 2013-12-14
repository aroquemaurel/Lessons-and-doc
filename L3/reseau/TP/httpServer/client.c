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
void query(const int sockfd, char* msg, char* file, char* output, const TypeQuery test);
void get(const int sockfd, char* file, char* output);
void put(const int sockfd, char* file);
void decaler(char* buff);
bool supprimerEntete(char c);


int main(int argc, char** argv) {
	int portno, sockfd;
	char buffer[256];
	char* file = argv[4];
	char* outputFile;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	// Arguments error
	if((strcmp(argv[1], "get") != 0 && strcmp(argv[1], "put") != 0 && strcmp(argv[1], "test") != 0) || argc < 5) {
		strcpy(buffer, error_usage());
		error(buffer, 2);
	}

	outputFile =(argc == 6) ? argv[5] : NULL;
	
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
	
	if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0) {
		error("ERROR connecting", 3);
	}
		
	if(strcmp(argv[1], "get") == 0){
		get(sockfd, file, outputFile);
	} else if(strcmp(argv[1], "put") == 0) {
		put(sockfd, file);
	} else if(strcmp(argv[1], "test") == 0) {
		strcat(buffer, argv[4]);
		strcat(buffer, "\r\n\r\n");
		query(sockfd, buffer, NULL, NULL, TEST);
	}

	
	return 0;
}

void get(const int sockfd, char* file, char* output) {
	char msg[256] = "GET ";

	strcat(msg, file);
	strcat(msg, " HTTP/1.0\r\n\r\n");

	query(sockfd, msg, file, output, GET);
}

void put(const int sockfd, char* file) {
	char msg[256] = "PUT "; // TODO taille tableau allocation
	int f;
	char buff[256];
	char answer;
	int sizeFile;
	struct stat stats;
	char buffChar;

	strcat(msg, file);
	strcat(msg, " HTTP/1.0\r\n");
	strcpy(buff,"./");
	strcat(buff,file);
	if((f = open(buff, O_RDONLY, 0755)) == -1) {
		fprintf(stderr, "erreur file");
	} 
	strcat(buff, "\r\n");
	
	fstat(f, &stats);
	sizeFile = stats.st_size;

	sprintf(buff, "Contents-length: %d", sizeFile);
	strcat(msg, buff);
	strcat(msg, "\r\n\r\n");

//	buff[0] = "\0";

	write(sockfd,msg,strlen(msg));
	int nbBytes;
	while((nbBytes = read(f, &buffChar, 1)) > 0) {
		// Write abortait le programme et retournait 141(?).
		// Fonctionne correctement avec send
//		write(sockfd,&buffChar,1);
		send(sockfd, &buffChar, 1, MSG_NOSIGNAL); 
	}
	printf("%s", msg);

	// get result
	// FIXME → Provoque bloquage du put.
//  while(read(sockfd,&answer,1) != 0) {
///		printf("%c", answer);
//	}
}

void query(const int sockfd, char* msg, char* file, char* outputFile, const TypeQuery typeQuery) {
	char buffer[256];
	bool beginFile = false;
	char answer;
	char buff[4];
	int i = 0;
	int nbChars = 0;
	char** split;
	int output;
	strcpy(buffer, "./");

	if(typeQuery == GET) {
		if(outputFile == NULL) {
			split = str_split(file,'/');

			for(i=0 ; split[i] != NULL ; ++i);
			strcat(buffer, split[i-1]);
		} else {
			strcat(buffer, outputFile);
		}
		if(strcmp(buffer, "./") == 0) {
			strcat(buffer, "default"); // si pas de nom de fichier spécifiés, on lui donne un nom par défaut
		}
		output = open(buffer, O_CREAT|O_WRONLY, 0755); 
	}

	// send requete
	for(i=0 ; i < strlen(msg); ++i) {
		printf("%c", msg[i]);
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
