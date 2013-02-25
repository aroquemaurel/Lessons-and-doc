//------------------------------------------
//TP : minToMaj
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

bool estMinuscule (char a)
{
	return (a >='a' && a<= 'z');
}

bool estMajuscule (char a)
{
	return (a >='A' && a<= 'Z');
}

int main ()
{
	Chaine x;

	ecrire (uneChaine("entrer une chaine de caractere : "));
	lire (x);
	
	for (int i = 0 ; i < longueur(x) ; i++)
	{
		if (estMinuscule (x.chaine[i]))
		{	
			x.chaine[i] = 'A' + (x.chaine[i] - 'a') ;
		}
		else if (estMajuscule (x.chaine[i]))
		{
			x.chaine[i] = 'a' + (x.chaine[i] - 'A') ;
		}	

	}

	ecrireNL (x) ;

	return 0 ;
}


