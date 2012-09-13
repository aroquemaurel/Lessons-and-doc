------------------------------------------
TP : Tableau_ex1
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

/********* ENREGISTREMENT DE TYPE DATE *********/
struct Date 
{
	int jour;
	int mois;
	int annee;
};

Chaine  mois[12] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet" , "Aout" , "Septembre" , "Octobre" , "Novembre" , "Decembre" };

/********* PROCEDURE DE SAISIE D'UNE DATE *********/
 void saisirDate (Date &date1)
{
	ecrire(uneChaine("Veuillez saisir un jour[1-31] "));
	lire (date1.jour);
	ecrire(uneChaine("Veuillez saisir un mois[1-12] "));
	lire (date1.mois);
	ecrire(uneChaine("Veuillez saisir une année[AAAA] "));
	lire (date1.annee);
}


/********* AFFICHAGE D'UNE DATE *********/
 void afficherDate (Date &date1)
{
	ecrire(date1.jour);
	ecrire(uneChaine(" ")) ;
	ecrire(mois[date1.mois-1]);
	ecrire(uneChaine(" ")) ;
	ecrireNL(date1.annee);
}


/********* PROGRAMME *********/
int main (void)
{
	Date date;

	saisirDate (date);
	afficherDate (date);
	
	return 0 ;
}

