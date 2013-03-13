#include <stdlib.h>
#include <stdio.h>
#include "arbreGRB.h"
#include "file.h"

int main(void) {
	Arbre a = creerArbreGRD();
	File f = creerFile( );
	int val;
	for(int i = 0 ; i < 5 ; ++i) {
		scanf("%d", &val);
		a = ajouterEntier(a,val);
	}

	triGRD(a);

	f = enfile(f,42);
	f = enfile(f,2);
	f = enfile(f,9);
	f = enfile(f,10);
	f = defiler(f);
	f = defiler(f);
	printf("%d ", premier(f));
	printf("%d ", dernier(f));
	return EXIT_SUCCESS;
}
