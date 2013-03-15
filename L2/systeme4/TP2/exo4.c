#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
void displayInfos(void);
int main(int argc, char** argv) {
	pid_t pidFils;
	int circ;
	displayInfos();
	switch(fork()) {
		case -1:
			return EXIT_FAILURE;
		case 0:
			printf("Je suis le fils\n");
			displayInfos();
			return EXIT_SUCCESS;
		default:
			wait(&circ);
			printf("Je suis le père, le fils s'est terminé avec le code %d\n", circ);
			displayInfos();
			return EXIT_SUCCESS;
	}

	return 0;
}

void displayInfos(void) {
	printf("Processus courant: %d\n", getpid());
	printf("Père: %d\n", getppid());
	printf("UID: %d\n\n", getuid());
}
