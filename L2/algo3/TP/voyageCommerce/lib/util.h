/**
 * \file util.h
 * \brief Fonctions utiles.
 * \author Antoine de Roquemaurel
 * \date 19/11/2012 16:27:39
 *
 * Entêtes des fonctions pouvant être utiles dans tout le projet. 
 * Ce sont des fonctions simples, qui doivent être indépendantes du projet.
 *
 */

#ifndef __UTIL
#define __UTIL

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "tour.h"
#include "path.h"
/// Mode verbose
bool gVerboseMode;

/**
 * Cherche la première occurence d'une chaine de caractère dans un tableau de chaine caractère
 * @param pArray Le tableau de chaines de caractères dans lequel chercher
 * @param pSize La taille du tableau
 * @param pSearch La chaine de caractère à chercher
 * @return La position de la chaine dans le tableau ou -1 si elle n'a pas été trouvée
 */
int util_searchFirstOccurenceInArray(char** pArray, const int pSize, char* pSearch);

/**
 * Inverse les éléments d'un tableau pTag entre les cases pBegin et pEnd
 * @param pTab Tableau à inverser
 * @param pBegin Début de la section à inverser
 * @param pEnd Fin de la section à inverser
 */
void util_reverseArray(Town* pTab, const int pBegin, const int pEnd);

/**
 * Affiche le contenu d'un tableau d'entiers
 * @param pTab Le tableau à afficher
 * @param pSize La taille du tableau
 */
void util_displayArray(const int* pTab, const int pSize);

/**
 * Calcul la somme des éléments allant de pBegin à pEnd
 * @param pBegin Début de la somme
 * @param pEnd Fin de la somme
 * @return La somme des éléments
 */
int util_sum(const int pBegin, const int pEnd);

/**
 * Échange deux variables
 * @param a Première variable à échanger
 * @param b Seconde variable
 */
void util_swap(Town* a, Town* b);

/**
 * Calcul une valeur aléatoire entre pMin et pMax
 * @param pMin Minimum 
 * @param pMax Maximum
 * @return la valeur aléatoire
 */
int util_rand(const int pMin, const int pMax);

/**
 * Indique si un sous-tableau d'un tableau est présent dans un autre tableau
 * @param pChild Le tableau à chercher
 * @param pBegin Le début de la section à chercher
 * @param pEnd La fin de la section à chercher
 * @param pParent Le tableau dans lequel chercher
 * @param pRecursvite Pour simplifier vis-à-vis de la récursivité, doit toujours être à false
 *
 * @return Vrai si le sous-tableau à été trouvé faux sinon
 */
bool util_sousTabExist(Tour pChild, const int pBegin, const int pEnd, Tour pParent, bool pRecursvite);


/**
 * Supprime la valeur pDeleteIndice d'un tableau
 * @param pArray Le tableau
 * @param pSize La taille du tableau
 * @param pDeleteIndice L'indice à supprimer
 */
void util_deleteArrayValue(Path* pArray, int pSize, int pDeleteIndice);

#endif