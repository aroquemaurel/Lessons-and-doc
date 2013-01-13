/**
 * \file localSearch.h
 * \brief Fonctions de recherche locale
 * \author Antoine de Roquemaurel
 * \date 27/12/2012 18:00:18
 *
 * Entêtes des fonctions ayant rapport avec les algorithmes de recherches locales. 
 *
 */


#ifndef __LOCALSEARCH
#define	__LOCALSEARCH

#include <time.h>
#include <stdlib.h>
#include "tour.h"

/**
 * Effectue une recherche locale aléatoire
 * @param pInstance L'instance pour laquelle on veut rechercher le plus court chemin
 * @param pTryNb Le nombre d'essais à effectuer
 * @return La meilleure tournée
 * 
 * @see Instance
 */
Tour localSearch_randomBestPath(Instance pInstance, int pTryNb);

/**
 * Effectue une recherche locale systématique
 * @param pInstance L'instance pour laquelle on veut rechercher le plus court chemin
 * @param pTryNb Le nombre d'essais à effectuer
 * @return La meilleure tournée
 * 
 * @see Instance
 */
Tour localSearch_systematicBestPath(Instance pInstance, int pTryNb);
#endif	
