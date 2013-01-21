/**
 * \file instance.h
 * \brief Fonctions sur les instances.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 22:03:34
 *
 * Toutes les entêtes des fonctions se rapportant à une instance.
 *
 */
#ifndef __INSTANCE
#define __INSTANCE

#include <stdbool.h>
#include <string.h>


#include "town.h"
#include "distance.h"

/// Taille maximale des tableaux
#define N 1024

/**
 * \struct Instance instance.h
 * \brief Objet des instances
 * \see Town 
 * \see Distance
 * 
 * Une instance contient toutes les villes ( Town ) classés par ID, les calculs des algorithmes utilisent une instance
 * afin d'en retourner la meilleur tournée.
 */
typedef struct {
    /// Tableau des villes( Town ) classés par ID
	Town towns[N]; 
    /// Tableau linéaire contenant toutes les distances entre les villes. 
	Distance* distances; 
    /// Nombre de ville de l' Instance
	int nbTowns;
    /// Nom de l' Instance
	char* name; 
} Instance;

/**
 * Affiche une Instance
 * 
 * @param pInstance l' Instance à afficher
 */
void instance_display(const Instance pInstance);

/**
 * Créer une nouvelle Instance à partir d'un fichier
 * 
 * @param pFile Le pointeur sur fichier contenant les informations de l'instance
 * 
 * @return la nouvelle Instance
 */
Instance instance_new(FILE* pFile);

/**
 * Ajoute une nouvelle ville dans une Instance
 * 
 * @param pInstance L'instance à modifier
 * @param pTown La ville à ajouter
 * 
 * @see Town
 */
void instance_push(Instance* pInstance, const Town pTown);

/**
 * Initialise la matrice des distances 
 * @param pInstance L'instance à modifier
 * @see Distance
 */
void instance_initializeDistancesMatrix(Instance* pInstance);


/**********************************/
/**
 * Affiche la matrice des distances sous forme linéaire
 * @param pInstance L'instance à afficher
 * @see Distance
 */
void instance_displayLinearVector(const Instance pInstance);

/**
 * Affiche la matrice des distances sous forme de matrice symétrique
 * @param pInstance L'instance à afficher
 * @see Distance
 */
void instance_displayMatrix(const Instance pInstance);
#endif

