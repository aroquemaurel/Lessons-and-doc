#include <stdlib.h>
#include <assert.h>

#include "element.h"
#include "listeDoublementChaine.h"

typedef Element (*ptrFctMap)(Element);
int estVide(LDC l) {
	return (l->premier == NULL);
}
/*
 * Fonction interne
 */
void trouverPlace(LDC l, Element e, Cell** prec, Cell** suiv) {
}

LDC creer(void) {
	LDC newLdc;
	newLdc = (LDC) malloc(sizeof(LDCInterne));
	newLdc->premier = NULL;
	newLdc->dernier = NULL;

	return newLdc;
}

LDC ajouter(LDC liste, Element pElement) {
	Cell* courant;
	Cell* avant;
	Cell* apres;
	courant = (Cell*) malloc(sizeof(Cell));
	assert(courant != NULL);
	courant->val = pElement;
	trouverPlace(liste, pElement, &avant, &apres);
	courant->prec = avant;
	courant->suiv = apres;

	if(avant == NULL) { //début de liste
		liste->premier = courant;
	} else {
		liste->premier->suiv = courant;
	}

	if(apres == NULL) { //fin de liste
		liste->dernier = courant;
	} else {
		liste->dernier->prec = courant;
	}

	return liste;
}


void affichageCroisant(LDC liste) {
	Cell* courant = liste->premier;
	while(courant != NULL) {
		afficherElement(courant->val);	
		courant = courant->suiv;
	}
}

void affichageDecroissant(LDC liste) {
	Cell* courant = liste->dernier;
	while(courant != NULL) {
		afficherElement(courant->val);	
		courant = courant->prec;
	}
}

LDC supprimer(LDC liste, Element pElement) {
	Cell* courant;
	Cell* ajeter;

	courant = liste->premier;
	while(courant != NULL) {
  if(compare(pElement, courant->val) == 0) {
			// On a trouvé
			if(courant->prec != NULL) {
				courant->prec->suiv = courant->suiv;
			} else {
				liste->premier = courant->suiv;
			}

			if(courant->suiv != NULL) {
				courant->suiv->prec = courant->prec;
			} else {
				liste->dernier = courant->prec;
			}

			ajeter = courant;
			courant = courant->suiv;
			free(ajeter);
		} else {
			courant = courant->suiv;
		}
	}
	return liste;
}

LDC map(ptrFctMap fct, LDC liste) {  
	Cell* courant ;
	courant = liste->premier;
	LDC listeResultat = creer();
	while (courant != NULL) { // TODO utiliser itérateur
		listeResultat = ajouter(listeResultat, fct(courant->val)) ;
		courant = courant->suiv;
	}

	return liste;
}
