/**
 * \file genetic.h
 * \brief Fonctions d'algorithmes génétiques.
 * \author Antoine de Roquemaurel
 * \date 27/12/2012 18:00:30
 *
 * Entêtes des fonctions pouvant être utiles dans tout le projet. 
 * Ces fonctions ne sont appelés que depuis le main
 *
 */


#ifndef __GENETIC
#define	__GENETIC
#include "tour.h"
#include "path.h"
#include "util.h"

/**
 * Retourne la tournée après un croisemenet DPX entre pParent1 et pParent2
 * @param pParent1 La première tournée parent
 * @param pParent2 La seconde tournée parent
 * @return La fille créée à l'aide d'un croisement DPX
 * 
 * @see Tour
 */
Tour genetic_DPX(Tour pParent1, Tour pParent2);

/**
 * Fais muter la tournée pTour
 * @param pTour La tournée à faire muter
 * @param pProba La probabilité que la tournée pTour mute
 * @return Vrai si la tournée à muter faux sinon.
 */
bool genetic_mutation(Tour* pTour, float pProba);
/**
 * Retourne la meilleure tournée à l'aide d'un algorithme génétique
 * @param pInstance L'instance pour laquelle on veut calculer le plus court chemin
 * @param pNbTour Le nombre d'individus, ou tournée, que l'on veut initialiser
 * @param pNbGeneration Le nombre de génération que l'on veut faire avant de s'arrêter
 * @param pProba La probabilité que la fille mute
 * @return La meilleure tournée
 * 
 * @see Instance
 */
Tour genetic_getBestPath(Instance pInstance, const int pNbTour, const int pNbGeneration, const float pProba);
#endif	

