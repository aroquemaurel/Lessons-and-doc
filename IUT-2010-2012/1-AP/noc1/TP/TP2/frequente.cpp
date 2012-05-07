//------------------------------------------
//TP : frequente
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int main ()
{
	Chaine x;
	char caractereActuel ;
	int iMax  = 0 ;
	int iCompteur = 0 ;
	int iRang = 0 ;
	
	
	ecrire (uneChaine("entrer une chaine de caractere : "));
	lire (x);

	for (int i = 0 ; i < longueur (x) ; i++)
	{
		caractereActuel = ieme(x, i) ;
		iCompteur = 0 ;

		for (int j = i ; j < longueur(x) ; j++) {
			if (ieme(x, j) == caractereActuel)  {
				iCompteur ++ ;
			}
		}
		
		if (iCompteur > iMax) {
			iMax = iCompteur ;
			iRang = i ;
		}
	}

	ecrire(uneChaine("Le caractere le plus récurrent est : ")) ;
	ecrireNL(ieme(x, iRang)) ;
	ecrire(uneChaine("Il apparait ")) ;
	ecrire(iMax) ;
	ecrireNL(uneChaine(" fois.")) ;
	

}
