/**
 * \file errors.h
 * \brief Fonctions sur les erreurs.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 17:42:37
 *
 * Entêtes des fonctions concernant les erreurs du programme.  
 *
 */

#ifndef __ERRORS
#define __ERRORS

#include <stdio.h>
#include <stdlib.h>

/**
 * \struct Errors errors.h
 * \brief Objet des erreurs
 *
 * Toutes les chaines de caractères des erreurs. Si une variable vaut NULL, l'erreur n'est pas
 * présente, sinon elle sera affiché.
 * nbErrors est le nombre d'erreur, si celui-ci =0 alors le programme peut fonctionner correctement
 */
typedef struct {
    /// Nombre d'argument incorrect
    char* errorNbArguments; 
    /// Tag -f non trouvé
	char* errorTagFNotFound; 
    /// Fichier non trouvé
	char* errorFileNotFound; 
    /// Algorithme non spécifié
	char* errorNoAlgoSpecified; 
    /// Paramètre après -lsr manquant
    char* errorMissingParameterLsr; 
    /// Paramètre après -lsnr manquant
    char* errorMissingParameterLsnr; 
    /// Paramètre après -ga manquant
    char* errorMissingParameterGa; 
    /// Paramètre après -lsr non valide
    char* errorNoValidParameterLsr; 
    /// Paramètre après -lsnr non valide
    char* errorNoValidParameterLsnr; 
    /// Paramètre après -ga non valide
    char* errorNoValidParameterGa;
    ///Nombre d'erreurs
	int nbErrors; 
} Errors;

/**
 * Initialisation de l'objet
 * 
 * @return Une instance de Erreur initialisée
 */
Errors errors_new();

/**
 * Affiches toutes les erreurs de pErrors
 * 
 * @param pErrors L'objet pour lequelle on doit afficher les erreurs
 */
void errors_displayErrorsMessage(const Errors pErrors);

/**
 * Signale que le nombre d'argument est incorrect
 * 
 * @param pErrors L'objet des erreurs
 */
void errors_setNbArguments(Errors* pErrors);

/**
 * Signale que la balise -f n'a pas été trouvée
 * 
 * @param pErrors L'objet des erreurs
 */
void errors_setTagFNotFound(Errors* pErrors);

/**
 * Signale que le fichier fileName n'existe pas
 * 
 * @param pErrors L'objet des erreurs
 * @param fileName Le nom de fichier non trouvé
 */
void errors_setFileNotFound(Errors* pErrors, char* fileName);

/**
 * Signale qu'aucun algorithme n'a été spécifié
 *
 * @param pErrors L'objet des erreurs
 */
void errors_setNoAlgoSpecified(Errors* pErrors);

/**
 * Signale que les paramètres derrière -lsnr ne sont pas valides (non entier)
 *
 * @param pErrors L'objet des erreurs
 */
void errors_setNoValidParameterLsnr(Errors* pErrors);

/**
 * Signale que le paramètre derrière -lsr n'est pas valide (n'est pas un entier)
 *
 * @param pErrors L'objet des erreurs
 */
void errors_setNoValidParameterLsr(Errors* pErrors);

/**
 * Signale que le ou les paramètre après -ga ne sont pas valides (non entier ou décimal)
 * @param pErrors L'objet des erreurs
 */
void errors_setNoValidParameterGa(Errors* pErrors);

/**
 * Signale qu'aucun paramètre n'a été spécifié derrière -ga
 *
 * @param pErrors L'objet des erreurs
 */
void errors_setMissingParameterGa(Errors* pErrors);

/**
 * Signale qu'aucun paramètre n'a été spécifié derrière -lsnr
 *
 * @param pErrors L'objet des erreurs
 */
void errors_setMissingParameterLsnr(Errors* pErrors);

/**
 * Signale qu'aucun paramètre n'a été spécifié derrière -lsr
 *
 * @param pErrors L'objet des erreurs
 */
void errors_setMissingParameterLsr(Errors* pErrors);

#endif

