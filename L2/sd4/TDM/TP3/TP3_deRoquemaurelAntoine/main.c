#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"

int resolutionHanoi_recursif(Plateau pPlateau, const int pNbAnneaux, const int pEmplacementDepart, 
							 const int pEmplacementArrive, const int pEmplacementIntermediaire);
int resolutionHanoi_iteratif(Plateau pPlateau, const int pNbAnneaux, const bool pAfficherEtapes);
void decalerPetitAnneau(Plateau pPlateau, const int pNbAnneaux, int* pPositionAnneau);
int main(int argc, char** argv) {
	int numEtape;
	int nbAnneaux = 8;
	Plateau plateau;
	plateau = plateau_initialiser(nbAnneaux);

	numEtape = resolutionHanoi_iteratif(plateau, nbAnneaux, false);
	printf("Le problème avec %d anneaux à été résolu en %d étapes avec la solution itérative.\n", nbAnneaux, numEtape);
	numEtape = resolutionHanoi_recursif(plateau, nbAnneaux, 0, 2, 0);
	printf("Le problème avec %d anneaux à été résolu en %d étapes avec la solution récursive.\n", nbAnneaux, numEtape);
	return EXIT_SUCCESS;
}

int resolutionHanoi_recursif(Plateau pPlateau, const int pNbAnneaux, const int pEmplacementDepart, const int pEmplacementArrive, const int pEmplacementIntermediaire) {
	static int numEtap=0;
	if(pNbAnneaux != 0) {
		resolutionHanoi_recursif(pPlateau, pNbAnneaux-1, pEmplacementDepart, pEmplacementIntermediaire, pEmplacementArrive);
		plateau_deplacerAnneau(pPlateau,pEmplacementDepart,pEmplacementArrive);
		++numEtap;	
		resolutionHanoi_recursif(pPlateau, pNbAnneaux-1, pEmplacementIntermediaire, pEmplacementArrive, pEmplacementDepart);
	}

	return numEtap;
}

int resolutionHanoi_iteratif(Plateau pPlateau, const int pNbAnneaux, const bool pAfficherEtapes) {
	bool estDeplace = false;
	int positionPetitAnneau= 0;
	int i, j;
	int numEtap = 0;

	if(pAfficherEtapes) {
		printf("== Etat initialal == \n");
		plateau_afficher(pPlateau);
	}
	 while(!pile_vide(pPlateau[0]) || !pile_vide(pPlateau[1])) {
		estDeplace = false;
		decalerPetitAnneau(pPlateau,pNbAnneaux,&positionPetitAnneau);
		++numEtap;	
		if(pAfficherEtapes) {
			printf("\n==  Etape numéro %d ==\n", numEtap);
			plateau_afficher(pPlateau);
		}

		// si on peut déplacer un autre disque que le petit alors le déplacer ou l'on peut
		for(i=0; i < 3 && !estDeplace; ++i) {
			if(i != positionPetitAnneau) { // on essaye pas de déplacer le petit anneau
				for(j=0 ; j < 3 ; ++j) {
					if(j != i && plateau_deplacementEstPossible(pPlateau,i,j)) { 
						plateau_deplacerAnneau(pPlateau, i, j);
						estDeplace = true;
						++numEtap;	
						if(pAfficherEtapes) {
							// Afficher le plateau
							printf("\n==  Etape numéro %d ==\n", numEtap);
							plateau_afficher(pPlateau);
						}
						break;
					}
				}
			}
		}
	}

	 return (numEtap);
}
void decalerPetitAnneau(Plateau pPlateau, const int pNbAnneaux, int* pPositionAnneau) {
	if(pNbAnneaux % 2 == 0) { // Pair
		// déplacer le petit disque dans le sens antitrigo
		if(*pPositionAnneau != 2) {
			plateau_deplacerAnneau(pPlateau, *pPositionAnneau, *pPositionAnneau+1);
			++*pPositionAnneau;
		} else {
			plateau_deplacerAnneau(pPlateau,2, 0);
			*pPositionAnneau= 0;
		}
	} else { // Impair
		// déplacer le petit disque dans le sens antitrigo
		if(*pPositionAnneau!= 0) {
			plateau_deplacerAnneau(pPlateau,*pPositionAnneau, *pPositionAnneau-1);
			--*pPositionAnneau;
		} else {
			plateau_deplacerAnneau(pPlateau,0, 2);
			*pPositionAnneau= 2;
		}
	}
}

