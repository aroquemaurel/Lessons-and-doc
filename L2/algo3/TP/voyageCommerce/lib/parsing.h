/**
 * \file parsing.h
 * \brief Fonctions de parsing des arguments.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 17:17:24
 *
 * Entêtes des fonctions permettant de parser les arguments, et ainsi d'appeler les différents 
 * algorithmes demandés, d'utiliser le mode verbeux et de spécifier le fichier.
 *
 */
#ifndef __PARSING
#define __PARSING

#include <stdbool.h>
#include "util.h"
#include "errors.h"

/**
 * \enum AlgoType parsing.h
 * \brief Enumération des types d'algorithmes
 *
 * Les différents types d'algorithmes qui peuvent être appellés. 
 */
typedef enum { 
    /// L'algorithme de brute force
	BRUTEFORCE, 
    /// L'algorithme de recherche locale aléatoire            
	LOCALSEARCH_RANDOM, 
    /// L'algorithme de recherche locale systématique            
	LOCALSEARCH_SYSTEMATIC, 
    /// L'algorithme génétique            
	GENETIC, 
    /// Correspond au marqueur de fin des algorithmes            
    END
} AlgoType;

/**
 * \struct Algo parsing.h
 * \brief Enumération d'un algorithme
 *
 * Énumération d'un algorithme, contient le type de l'algorithme avec les eventuels paramètres
 * 
 * @see AlgoType
 */
typedef struct {
    /// Le type de l'algorithme
    AlgoType type;
    /// Premier paramètre de l'algorithme
    int firstParameter;
    /// Second paramètre
    double secondParameter;
} Algo;

/**
 * Cherche si le mode verbeux à été spécifié ou non. 
 * 
 * @param pTab Le tableau contenant les arguments
 * @param pSize Le nombre des arguments
 * @return Vrai si mode verbeux, Faux sinon
 */
bool parsing_parseVerboseMode(char** pTab, const int pSize);

/**
 * Cherche le nom du fichier de l'Instance
 * 
 * @param pTab Le tableau contenant les arguments
 * @param pSize Le nombre des arguments
 * @param pErrors L'objet des erreurs, il est modifié si des erreurs interviennent
 * @return Le nom du fichier
 * @see Errors, Instance
 */
char* parsing_parseFileName(char** pTab, const int pSize, Errors* pErrors);

/**
 * 
 * @param pTab Le tableau contenant les arguments
 * @param pSize Le nombre des arguments
 * @param pErrors L'objet des erreurs, il est modifié si des erreurs interviennent
 * @param algos Tableau d'algorithmes, ceci au cas ou l'utilisateur entre plusieurs algorithmes. 
 *      La fin du tableau est marqué par END
 * @see Algo, Errors
 */
void parsing_algoType(char** pTab, const int pSize, Errors* pErrors, Algo* algos);
#endif

