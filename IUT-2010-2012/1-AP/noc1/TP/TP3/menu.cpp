//------------------------------------------
//TP : Menu
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int iMenu ;     //Choix du menu

int main ()
{
	ecrire (uneChaine("Voici la liste du menu : \n- Choix 1 : Se suicider\n- Choix 2 : Sauter par la fenetre\n- Choix 3 : Se tirer une balle\n- Choix 4 : rester en vie"));
	ecrire (uneChaine("Saisir un choix en entrant le numero du choix : "));
		lire (iMenu);
	ecrire(uneChaine("\n"));
	while (iMenu < 1 || iMenu > 4) 
	{
		ecrireNL(uneChaine("Erreure - Saisir un choix en entrant le numero du choix compris entre 1 et 4 : "));
		lire (iMenu);
	} 

	switch (iMenu)
	{	
		case (1): 
			ecrireNL(uneChaine("Vous avez choisi de vous suicider"));
		break;
		case (2):
			 ecrireNL(uneChaine("Vous avez choisi de sauter par la fenetre"));
		break;
		case (3): 
				ecrireNL(uneChaine("Vous avez choisi de vous tirer une balle"));
		break;
		case (4): 
			ecrireNL(uneChaine("Vous avez choisi de rester en vie"));
		break;
	}
}
