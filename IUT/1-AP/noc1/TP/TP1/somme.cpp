//------------------------------------------
//TP : somme
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

void calculerSomme (int a, int b, int &resultat)
{
	resultat =  a + b;
}

int main ()
{
	int entier1;
	int entier2;
	int somme = 0;
	ecrire (uneChaine("Ecrire 1 : "));
	lire (entier1);
	ecrire (uneChaine ("Ecrire 2 : "));
	lire (entier2);
	calculerSomme (entier1, entier2, somme);
	ecrire (somme);

	return 0;
}
