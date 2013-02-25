//------------------------------------------
//TP : Perimetre
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int perimetre (int a, int b);
int surface (int a, int b);

int main ()
{
	int l;        // largeur
	int L;        // Longeur

	ecrire (uneChaine ("Donnez la valeur de la largeur : "));
	lire (l);
	ecrire (uneChaine ("Donnez la valeur de la longueur : "));
	lire (L);
	ecrire (uneChaine ("Le perimetre est de "));
	ecrireNL (perimetre (l,L));
	ecrire (uneChaine ("La surface est de "));
	ecrireNL (surface (l,L));
	return 0 ;
}

int perimetre (int a,int b)
{
	return (a+b)*2;
}

int surface (int a, int b)
{
	return (a*b);
}	
