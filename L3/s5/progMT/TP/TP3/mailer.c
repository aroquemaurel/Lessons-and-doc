#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

int tube[2];

void error(bool predicat, char* message, int codeErr);
int main(int argc, char** argv) {
	char* user;
	char message[1024];
	char buff;

	error(argc > 1, "Erreur dans le nombre d'arguments", 1);	
	error(pipe(tube) != -1, "Erreur dans la création du tube", 2);

	user = argv[1];
	switch(fork()) {
		case -1:
			error(false, "Erreur dans la création du fils", 3);
		case 0:
			dup2(0, tube[0]);
			close(tube[0]);
			close(tube[1]);
			execlp("mail",  "mail", "-s", "le super sujet", "aroquemaurel",NULL);
	}
	close(tube[0]);
//	scanf("%s", message);
//	
//	while(scanf("%s", message) != EOF) {
//		write(tube[1], message, strlen(message));	
//	}
//	scanf("%s", message);
	fgets(message, 16, stdin);
	message[strlen(message)] = '\0';
//	printf("%s", message);
	write(tube[1], message, 6);	

	close(tube[1]);
	while(wait(NULL) != 1);

	return EXIT_SUCCESS;
}

void error(bool predicat, char* message, int codeErr) {
	if(!predicat) {
		fprintf(stderr, message);
		exit(codeErr);
	}
}
