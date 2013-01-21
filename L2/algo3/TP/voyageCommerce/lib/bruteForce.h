/**
 * \file bruteForce.h
 * \brief Fonctions de brute force.
 * \author Antoine de Roquemaurel
 * \date 27/12/2012 17:58:36
 *
 *  Entêtes des fonctions servant à la force brute.
 * Ces fonctions ne sont appelés que depuis le main
 *
 */

#ifndef __BRUTEFORCE
#define __BRUTEFORCE

#include "instance.h"
#include "tour.h"
#include "util.h"

/**
 * Permet d'obtenir le meilleur chemin d'une instance via la force brute. 
 * Il est conseillé de ne pas essayer avec des instances de plus de 8 villes.
 * 
 * @param pInstance L'instance pour laquelle on doit calculer le plus court chemin
 * @return La meilleur tournée.
 * 
 * @see Instance
 */
Tour bruteForce_bestPath(Instance pInstance);

#endif

