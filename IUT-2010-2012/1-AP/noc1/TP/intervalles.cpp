//------------------------------------------
//TP : Intervalles
//------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

// Enregistrement d'un intervalle

struct Intervalle
{
	int inf;
	int sup;
};


// Procédure chargée de la saisie d'un intervalle

void saisirIntervalle (Intervalle &i)
{
	int iBuffer ;

	ecrire (uneChaine("Borne inf ?"));
	lire(iBuffer) ;
	i.inf = iBuffer;
	ecrire (uneChaine("Borne sup ?"));
	lire(iBuffer) ;
	i.sup = iBuffer;
}


// Procédure chargée d'afficher un intervalle 

void afficherIntervalle (const Intervalle intervalle1)
{
	ecrire (uneChaine("["));
	ecrire (intervalle1.inf);
	ecrire (uneChaine(","));
	ecrire (intervalle1.sup);
	ecrire (uneChaine("]"));
}

// Fonction intersection renvoyant l'intersection de deux intervalles

Intervalle intersection (Intervalle intervalle1, Intervalle intervalle2)
{
	Intervalle inter = {0,0} ; 

	if (intervalle1.sup < intervalle2.inf) {
		ecrire(uneChaine("Ensemble vide")) ;
	} else {
		if(intervalle1.inf > intervalle2.sup) {
			ecrire(uneChaine("Ensemble vide"));
		} else {
			inter.inf = intervalle2.inf ;
			inter.sup = intervalle1.sup ;
		}
	}


	return inter ;

}

// Programme

int main (void)
{
	Intervalle i1, i2 ;
	
	saisirIntervalle(i1) ;
	saisirIntervalle(i2) ;

	afficherIntervalle(i1) ;
	afficherIntervalle(i2) ;

	afficherIntervalle(intersection(i1,i2)) ;

	
	return 0;
}
