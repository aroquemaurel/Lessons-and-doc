#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"

typedef struct {
	char** arrayCommande;
	int nbInstruction;
	_Bool esperluette;
} Instructions ;

Instructions prompt();
_Bool findEsperluette(Instructions* instructions);


/* 
 *  Développement des commandes avec leurs arguments, de la gestion d'une tâche de fond (&).
 */
int main(int argc, char** argv) {
	int i;
	Instructions instructions = prompt();

	while(strcmp(trim(instructions.arrayCommande[0]), "exit") != 0) {
		switch(fork()) {
			case -1:
				error("Erreur dans la création du fork", EXIT_FAILURE);
			case 0:
				execvp(trim(instructions.arrayCommande[0]), instructions.arrayCommande);
				return EXIT_SUCCESS;
			default:
				if(!instructions.esperluette) {
					wait(NULL);
				} else {
					printf("\nProcessus %s mis en tâche de fond.\n", instructions.arrayCommande[0]);
				}
				
		}
		instructions = prompt();
	}
	
	return EXIT_SUCCESS;
}

Instructions prompt() {
	int i;
	char commande[256] = "";
	char hostname[256];
	char username[256];
	Instructions instructions;

	gethostname(hostname, sizeof(hostname));
	getlogin_r(username, sizeof(username));
	printf("\n$%s@%s ", username, hostname);
	fflush(stdout);
	fgets(commande, sizeof(commande), stdin);
	instructions.arrayCommande = str_split(commande,' ');
	for(i=0 ; instructions.arrayCommande[i] != NULL ; ++i);
	instructions.nbInstruction = i;
	instructions.esperluette = findEsperluette(&instructions);


	return instructions;
}

_Bool findEsperluette(Instructions* instructions) {
	int i=0;
	_Bool ret = false;
	for(i=0 ; i < instructions->nbInstruction ; ++i) {
		if(ret = instructions->arrayCommande[i][strlen(instructions->arrayCommande[i])-1] == '&') {
			instructions->arrayCommande[i][strlen(instructions->arrayCommande[i])-1] = '\0';
		}
	}

	return ret;
}
