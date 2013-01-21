/**
 * \file town.h
 * \brief Fonctions des villes.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 22:35:19
 *
 * Entêtes des fonctions se rapportant à une ville. 
 *
 */

#ifndef __TOWN
#define __TOWN
#include <stdio.h>
#include <stdlib.h>

/**
 * \struct Town town.h
 * \brief Objet des ville
 *
 * Structure représentant une ville
 */
typedef struct {
    /// Abscisse de la ville
	float x; 
    /// Ordonnée de la ville
	float y; 
    /// Id de la ville
	int id; 
} Town;

/**
 * Création d'une nouvelle ville
 *
 * @param pId Id de la ville
 * @param pX Abscisse
 * @param pY Ordonnée
 */
Town town_new(const int pId, const float pX, const float pY);

/**
 * Affiche une ville
 * @param pTown La ville à afficher
 */
void town_display(const Town pTown);
#endif

