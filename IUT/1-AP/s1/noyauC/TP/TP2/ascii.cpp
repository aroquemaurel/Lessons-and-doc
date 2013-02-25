//------------------------------------------
//TP : ASCII
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

#include <iostream>

int main() {
	int x;
	char y;
	
	ecrire (uneChaine("Ecrire une lettre : "));
	lire (y);
	printf ("%d", y);
	
	ecrire (uneChaine("Ecrire un chiffre : "));
	lire (x);
	putchar (x);
	ecrire (uneChaine("\n"));
	return 0 ;
}
