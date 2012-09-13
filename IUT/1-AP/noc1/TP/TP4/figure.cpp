//------------------------------------------
//TP : figures
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int main ()
{
	int iNombre;
	int cpt=0;
	int cpt2 = 0;
	int u = iNombre;

	ecrire(uneChaine("Entrer le nombre d'étoile sur la premiere ligne : "));
	lire (iNombre);
	ecrire(uneChaine("\n"));
	
		for (int i = 0 ; i < iNombre ; i++) {
			for (int j = 0 ; j < i+1 ; j++) {
			ecrire(uneChaine("*")) ;		
			}
			ecrireNL() ;
		}
}

