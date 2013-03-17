#include <stdio.h>
#include <stdlib.h>
#include "iterateur.h"
#include "listeDoublementChaine.h"

typedef Element (*ptrFctMap)(Element);
LDC map(ptrFctMap fct, LDC liste) {  
	LDC listeResultat = creer();
	Iterateur i = creerIterateur();
	while (hasNext(i)) { 
		listeResultat = ajouter(listeResultat, fct(next(i))) ;
	}

	return liste;
}

int main(int argc, char** argv) {
	return 0;
}

