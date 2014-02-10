#include <stdio.h>
#include <stdlib.h>
// [L3][PMT]


/* 
 * Exercice 1
 */
#include "erreur.h"
#define NB_MAX 100

int main(int argc, char** argv) {
	int i;
	
	switch(fork()) {
		case -1:
			error("Erreur dans le fork", EXIT_FAILURE);
		case 0:
			for(i = 0 ; i < NB_MAX ; ++i) {
				printf("fils");
			}
			exit(0);
		default:
			for(i = 0 ; i < NB_MAX ; ++i) {
				printf("pere");
			}
	}

	return EXIT_SUCCESS;
}

