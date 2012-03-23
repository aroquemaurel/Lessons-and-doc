//------------------------------------------
//TP : moyenne
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int main ()
{
	int entier;
	int moyenne = 0;
	
	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = (moyenne + entier);

	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = (moyenne + entier);

	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = (moyenne + entier);

	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = (moyenne + entier);

	ecrire (uneChaine("Entrer une note : "));
	lire (entier);
	moyenne = ((moyenne + entier)/5);

	ecrire (uneChaine("La moyenne de l'élève est de "));
	ecrireNL (moyenne);
}
