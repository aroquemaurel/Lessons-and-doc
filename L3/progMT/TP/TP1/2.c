#include <stdlib.h>
#include <unistd.h>

/* 
 * Exercice 2
 */
int main(int argc, char** argv) {
	switch(fork()) {
		case -1:
			error("Erreur dans le lancement du fork", EXIT_FAILURE);
			break;
		case 0:
			execlp("date", "date", NULL);
			exit(EXIT_FAILURE);
		default:
			wait(NULL);
			execlp("ps", "ps", "-al", NULL);
			break;
	}

	return EXIT_SUCCESS;
}
