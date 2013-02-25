//------------------------------------------
//TP : gele
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int iTemp; // Température

int main ()
{
	ecrire (uneChaine("Voici la liste des liquides : \n- eau \n- fuel\n- super\n- ordinaire \n- eau salée\n\n"));
	ecrire (uneChaine("Saisir une température : "));
	lire (iTemp);
	switch (iTemp)
	{
		case (-23) : ecrireNL(uneChaine("Le super gèle"));
		case (-13) : ecrireNL(uneChaine("L'ordinaire gèle"));
		case (-5) : ecrireNL(uneChaine("Le fuel gèle"));
		case (0) : ecrireNL(uneChaine("L'eau gèlee"));
					break;
		default : ecrireNL(uneChaine("Aucun des liquides ne gèlent à cette température"));
	}
}
