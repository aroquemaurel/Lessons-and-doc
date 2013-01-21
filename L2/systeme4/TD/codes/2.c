#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	char *valeur;

	if(argc != 2) {
		fprintf(stderr, "Usage : %s variable\n", argv[0]);
		return (1);
	}

	valeur = getenv(argv[1]);

	if(valeur == NULL) {
		fprintf(stderr, "Variable %s inconnue \n", argv[1]);
		return (2);
	}

	printf("%s=%s", argv[1], valeur);

	return 0;
}

