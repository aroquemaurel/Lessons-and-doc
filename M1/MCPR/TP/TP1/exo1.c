/*  TP1 -- Exo1 -- variante 1 et 2 */

/* Écrire un programme dans lequel deux processus Unix parents (un processus et son fils) font des
opérations en parallèle sur un compteur. L’un incrémente ce compteur de la valeur 1 un certain
nombre de fois tandis que l’autre le décrémente de 1 le même nombre de fois. À la fin de
l’exécution, chacun affiche la valeur du compteur.
On écrira une fonction pour représenter le traitement de chacun de ces processus qu’on utilisera
pour créer ces processus dans le programme principal. Ce programme sera paramétré par le
nombre d’incrémentations/décrémentations à réaliser.
*/
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* 
 * Les variables ne sont pas partagées, un processus va juqsu'à 30 l'autre -30
 * Aucun changement si variable globale plutôt que locale
 * */
int cpt = 0;

void treatmentIncrement(const int nbIncrement);
void treatmentDecrement(const int nbDecrement);

int main(int argc, char** argv) {
	if(argc <= 1) {
		perror("Argumetns errors");
		exit(1);
	}
	switch(fork()) {
		case 0:
			treatmentIncrement(atoi(argv[1]));
			break;
		default:
			treatmentDecrement(atoi(argv[1]));
			break;
	}
}

void treatmentIncrement(const int nbIncrement) {
	for(int i = 0 ; i < nbIncrement; ++i) {
		printf("\tIncrement: %d\n",++cpt);
	}

}

void treatmentDecrement(const int nbDecrement) {
	for(int i = 0 ; i < nbDecrement; ++i) {
		printf("Decrement: %d\n",--cpt);
	}

}
