//------------------------------------------
//TP : MAJ2
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

bool estMinuscule (char a)
{
	return (a >='a' && a <= 'z');
}

bool estMajuscule (char a)
{
	return (a >='A' && a <= 'Z');
}

bool estUnChiffre (char a)
{
	return (a >= '0' && a <= '9');
}

int main ()
{
	char a;

	ecrire (uneChaine("Saisir une suite de caractère terminée par '.' : "));
	do
	{
	lire (a);
	}	
	while (a != '.') ;
/* if (estMinuscule (a))
	{	
		ecrire (uneChaine("le caractere entré est une minuscule \n"));
	} else if (estMajuscule (a)) { 
		ecrire (uneChaine("le caractere entré est une majsucule\n"));
    } else {
		ecrire (uneChaine ("est un chiffre\n"));
	}
*/	
	return 0;
}
		
