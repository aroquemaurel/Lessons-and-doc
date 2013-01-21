/**
 * \file main.c
 * \mainpage Le problème du voyageur de commerce - Projet d'algorithmique en langage C
 * \author L2 Antoine de Roquemaurel (G1.1)
 * \date 19/11/2012 10:42:29
 *
 *  Point d'entrée du programme. Aucune fonction ne doit être déclarée
 * Ce sont des fonctions simples, qui doivent être indépendantes du projet.
 *
 * \section Le problème
 * Étant donné n points (des "villes") et les distances les séparant, trouver un chemin de longueur totale qui passe exactement une fois par chaque point et 
 * reviennent au point de départ (une tournée).
 *
 * Ce problème peut servir tel quel a l'optimisation de trajectoires de machines-outils : par exemple,
 * pour minimiser le temps total que met une fraiseuse a commande numérique pour
 * percer n points dans une plaque de tôle ou pour percer les trous des composants d'un circuit
 * electronique comme dans le cas qui nous intéresse.
 *
 * Ce problème est plus compliqué qu'il n'y parait et on ne connait pas de méthode de résolution
 * permettant d'obtenir des solutions exactes en un temps raisonnable pour de grandes instances
 * (grand nombre de villes) du problème. Pour ces grandes instances, on devra donc souvent se
 * contenter de solutions approchés, car on se retrouve face à une explosion combinatoire :
 * le nombre de chemins possibles passant par 69 villes est déjà un nombre d’une longueur de
 * 100 chiffres. Pour comparaison, un nombre d'une longueur de 80 chiffres permettrait déjà de
 * représenter le nombre d'atomes dans tout l'univers connu.
 *
 * Le problème du "voyageur de commerce" a été étudié depuis lontemps et on dispose d’une
 * grande variété d'algorithmes donnant le plus souvent des solutions approchés mais calculables
 * en un temps raisonnable.
 * 
 * \section Les algorithmes implémentéé
 * Ce problème sera implémenté via différents algorithmes : 
 * - Brute force
 * - Recherche locale aléatoire
 * - Recherche locale systématique
 * - Algorithme génétique
 */ 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "parsing.h"
#include "errors.h"
#include "bruteForce.h"
#include "localSearch.h"
#include "genetic.h"

/**
 * Fonction d'entrée du programme
 * @param argc Nombre d'arguments du programme
 * @param argv Tableau contenant la liste des arguments du programme
 * @return Code d'erreur du programme
 */
int main (int argc, char** argv) {
    int i=0;
	char* fileName;	
	FILE* file = NULL;
	Instance instance;
	Errors errors = errors_new();
	Algo algos[3];
	Tour tour;
    srand(time(NULL));

	gVerboseMode = parsing_parseVerboseMode(argv, argc);  
	fileName = parsing_parseFileName(argv, argc, &errors); 
	parsing_algoType(argv, argc, &errors, algos); //On récupère les algorithmes a effectués demandés

	file = fopen(fileName, "r");
	if(file == NULL) {
		errors_setFileNotFound(&errors, fileName);
	}
    
	if(errors.nbErrors == 0) { 	// on peut travailler
        instance = instance_new(file);
        if(gVerboseMode) {
            instance_display(instance);
        }
        /* On calcul les solutions avec les différents algorithmes demandés */
        /* Et on affiche le type d'algorithme avec de la couleur afin de bien repérer les 
         * différents parties du programme*/
        while(algos[i].type != END) {
           switch(algos[i].type) {
                case BRUTEFORCE:
                  printf("\033[%d;%dm === BRUTE FORCE === \033[0m\n",30,33);
                    tour = bruteForce_bestPath(instance);
                    break;
                case LOCALSEARCH_RANDOM:
                    printf("\033[%d;%dm === RECHERCHE LOCALE ALÉATOIRE === \033[0m\n",30,33);
                    tour = localSearch_randomBestPath(instance, algos[i].firstParameter); 
                    break;
                case LOCALSEARCH_SYSTEMATIC:
                    printf("\033[%d;%dm === RECHERCHE LOCALE SYSTÉMATIQUE === \033[0m\n",30,33);
                    tour = localSearch_systematicBestPath(instance, algos[i].firstParameter);
                    break;
                case GENETIC:
                    printf("\033[%d;%dm === GÉNÉTIQUE === \033[0m\n",30,33);
                    tour = genetic_getBestPath(instance, 200,algos[i].firstParameter,algos[i].secondParameter);
                    break;
           }
            printf("Meilleure tournée \n");
            tour_display(tour);
            ++i;
            printf("\n\n");
        }
	} else {
		errors_displayErrorsMessage(errors);	
		return EXIT_FAILURE;
	}

	if(file != NULL) {
		fclose(file);
	}

	return EXIT_SUCCESS;
}
