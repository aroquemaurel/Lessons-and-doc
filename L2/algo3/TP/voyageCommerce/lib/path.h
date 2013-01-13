/**
 * \file path.h
 * \brief Fonctions des trajets.
 * \author Antoine de Roquemaurel
 * \date 11/01/2013 03:12:00
 *
 * Entêtes des fonctions se rapportant à un trajet.  
 */

#ifndef __TRAJET
#define __TRAJET

 /// Taille maximale du tableau de ville
#define N 1024

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "tour.h"
/**
 * \struct Path path.h
 * \brief Objet d'un trajet
 *
 * Informations concernant un trajet.
 * 
 * @see Town
 */
typedef struct {
    /// Tableau de ville. Les villes sont triés dans l'ordre du trajet
	Town towns[N];
    /// Nombre de ville du trajet
	int nbTowns;
} Path;

/**
 * Créer un nouveau trajet
 * @param pTour La tournée dans laquelle on doit prendre le trajet
 * @param pBegin Le début du trajet
 * @param pEnd La fin du trajet
 * @return Le nouveau trajet
 * 
 * @see Tour
 */
Path path_new(Tour pTour, int pBegin, int pEnd);

/**
 * Ajoute le trajet le plus proche à la suite de pTour
 * @param pTour Le tour à completer
 * @param pPathsList La liste des trajets possibles
 * @param pNbPathsList Le nombre de trajets possibles
 * 
 * @see Tour
 */
void path_addNearNeighbor(Tour* pTour, Path* pPathsList, int* pNbPathsList);

/**
 * Afficher un trajet
 * @param pPath Le trajet à afficher
 */
void path_display(const Path pPath);
#endif

