/**
 * \file town.c
 * \brief Fonctions des villes.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 22:35:14
 *
 * implémentation des fonctions se rapportant à une ville. 
 *
 */

#include "town.h"
Town town_new(const int pId, const float pX, const float pY) {
    Town newTown;
	newTown.id = pId;
	newTown.x = pX;
	newTown.y = pY;
    
    return newTown;
}

void town_display(const Town pTown) {
    printf("Ville n°%d(%.2f %.2f)", pTown.id, pTown.x, pTown.y);
}