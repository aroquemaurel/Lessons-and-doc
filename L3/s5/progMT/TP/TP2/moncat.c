#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

#include "util.h"
#include "afficher.h"

int main(int argc,char** argv) {
	int i;
	int fout;
	int redirection = util_searchFirstOccurenceInArray(argv,argc,">");

	if(redirection != -1) {
		if((fout = open(argv[redirection+1], O_CREAT|O_WRONLY, 0666)) == -1) {
			error("Erreur lors de l'ouverture du fichier", EXIT_FAILURE);
		}
		dup2(fout, 1);
	}
	
	for(i = 1 ; i < argc && (strcmp(argv[i], ">") != 0); ++i) {
		if(display(argv[i]) == -1) {
			error("Problème lors de l'affichage", 2);
		}
	}

	return EXIT_SUCCESS;
}
