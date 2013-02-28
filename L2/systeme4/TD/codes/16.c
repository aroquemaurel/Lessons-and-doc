#define POSIX_C_SOURCE 1
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TAILLE_BLOC 512

/*  code de retour */
#define TOUT_VA_BIEN		 0
#define ERR_NB_PARAM		 1	
#define ERR_ACCES_FICHIER	 2
#define ERR_CREATION_FICHIER 3

int main(int argc, char** argv) {
	int src, dest;
	int nbLus;
	char bloc[TAILLE_BLOC];

	if(argc != 3) {
		fpintf(stderr, "Usage: %s fichiersource fichierdest", argv3);
		exit(ERR_NB_PARAM);
	}

	src = open(argv[1], O_RDONLY);
	if(src == -1) {
		perror(argv[1]);
		exit(ERR_ACCES_FICHIER);
	}

	dest = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, S_IROSR|S_IWOSR|S_IRGRP);
	if(dest == -1) {
		perror(argv[2]);
		close(src);
		exit(ERR_CREATION_FICHIER);
	}

	while((nbLus = read(src, bloc, TAILLE_BLOC)) > 0) {
		write(dest, bloc, nbLus);
	}
	close(src);
	close(dest);

	return (TOUT_VA_BIEN);
}
