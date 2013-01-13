/**
 * \file tour.h
 * \brief Fonctions des tournées.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 22:04:13
 *
 * Entêtes des fonctions se rapportant à une tournée.  *
 */

#ifndef __TOUR
#define __TOUR

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "town.h"
#include "instance.h"
#include "distance.h"
/**
 * \struct Tour tour.h
 * \brief Objet d'une tournée
 * \see Town, Distance
 * 
 * Informations concernant une tournée. 
 */
typedef struct {
    /// Tableau de ville. Les villes sont triés dans l'ordre de la tournée
	Town towns[256];
    /// Nombre de ville de la tournée
	int nbTowns;
    /// Longueur de la tournée
	double length;
    /// Matrice de distances
    Distance* distances;
}Tour;

/**
 * Créer une nouvelle tournée initialisée avec les données d'une instance
 *
 * @param pInstance Instance servant à initialisée la tournée
 * @return la nouvelle tournée
 * 
 * @see Instance
 */
Tour tour_new(Instance pInstance);

/**
 * Génère la permutation de ville suivante d'une tournée
 * @param pPermutation La tournée pour laquelle la permutation doit être générée
 * @return Vrai si une permutation à été généré faux s'il ne reste plus de permutation.
 */
bool tour_nextPermutation(Tour* pPermutation);

/**
 * Calcul la longueur d'une tournée
 * @param pTour La tournée pourlaquelle on veut calculer la longueur
 */
void tour_calculLength(Tour* pTour);

/**
 * Affiche une tournée
 * 
 * @param pTour La tournée à afficher
 */
void tour_display(const Tour pTour);

/**
 * Génère une tournée aléatoire
 * @param pInstance L'instance pour laquelle générer un random walk
 * @return La tournée aléatoire
 * 
 * @see Instance
 */
Tour tour_randomWalk(const Instance pInstance);

/**
 * Fait une 2opt 
 * @param pTour Le tour pourlaquelle on veut faire une 2opt
 * @param pFirst L'id du début du premier trajet
 * @param pSecond L'id du début du second trajet
 */
void tour_2opt(Tour* pTour, int pFirst, int pSecond);

/**
 * Ajoute une ville à la fin de la tournée pTour
 * @param pTour La tournée à compléter
 * @param pTown La ville à ajouter
 * 
 * @see Town
 */
void tour_addTown(Tour* pTour, Town pTown);

/**
 * Ajoute un tableau de ville à la fin de la tournée pTour
 * @param pTour La tournée à compléter
 * @param pTowns Le tableau de villes à ajouter
 * @param pNbTowns Le nombre de villes à ajouter
 * 
 * @see Town
 */
void tour_addSeveralTowns(Tour* pTour, Town* pTowns, const int pNbTowns);

/**
 * Remplace la pire tournée d'un tableau de tournée par la tournée pTour
 * @param pTours Le tableau de tournées
 * @param pSize La taille du tableau de tournées
 * @param pTour Le tour à ajouter
 */
void tour_replaceTheWorstTour(Tour* pTours, const int pSize, Tour pTour);
#endif

