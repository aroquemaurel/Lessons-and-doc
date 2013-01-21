/**
 * \file distance.h
 * \brief Fonctions des distances
 * \author Antoine de Roquemaurel
 * \date 01/12/2012 20:33:44
 *
 * Entêtes des fonctions se rapportant aux distances
 *
 */

#ifndef __DISTANCE
#define __DISTANCE

#include <math.h>
#include "town.h"
/**
 * \struct Distance distance.h
 * \brief Objet des distances
 *
 * Distance entre deux villes
 * @see Town
 */
typedef struct {
    /// Première ville
	Town firstTown;
    /// Seconde ville
	Town secondTown;
    /// Distance entre les deux villes
	double distance;
}Distance;

/**
 * Créer une nouvelle distance
 * 
 * @param pFirstTown Première ville
 * @param pSecondTown Seconde ville
 * @return Distance entre les deux villes
 * 
 * @see Town
 */
Distance distance_new(Town pFirstTown, Town pSecondTown);

/**
 * Calcul la distance entre deux villes
 * @param pTown1 Première ville
 * @param pTown2 Seconde ville
 * @return La distance
 * 
 * @see Town
 */
double distance_calculDistance(const Town pTown1, const Town pTown2);

/**
 * Calcul la distance entre deux villes
 * @param pDistances La matrice de distances
 * @param i La première ville
 * @param j La seconde ville
 * @return La distance
 * 
 * @see Town
 */
Distance distance_betweenTowns(Distance* pDistances, Town i, Town j) ;
#endif

