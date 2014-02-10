#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

#include "erreur.h"

int display(char* fich) {
	int f;
	int nbChars;
	char buff[256];

	if((f = open(fich, O_RDONLY)) == -1) {
		error("Erreur lors de l'ouverture du fichier", EXIT_FAILURE);
	}

	while((nbChars = (read(f, buff, 256))) != 0) {
		write(1, buff, nbChars);
	}
	close(f);

	return nbChars != -1;
}

