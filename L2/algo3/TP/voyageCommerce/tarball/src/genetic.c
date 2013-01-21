/**
 * \file genetic.c
 * \brief Fonctions d'algorithmes génétiques.
 * \author Antoine de Roquemaurel
 * \date 27/12/2012 18:00:25
 *
 * Implémentation des fonctions servant aux algorithmes génétiques. 
 * Ces fonctions ne sont appelés que depuis le main
 *
 */

#include "genetic.h"

Tour genetic_DPX(Tour pParent1, Tour pParent2) {
    Tour newTour;  
    Path pathsList[512];
    int i=0;
    int first=0;
    int nbPaths=0;
    
    newTour.nbTowns=0;
    for(i=0; i <= pParent1.nbTowns ; ++i) { 
        if(!util_sousTabExist(pParent1, first, i, pParent2, true) || i == pParent1.nbTowns) {
            pathsList[nbPaths++] = path_new(pParent1, first, i);
            first = i;    
        }
    }
 
    tour_addSeveralTowns(&newTour, pathsList[0].towns, pathsList[0].nbTowns);
    util_deleteArrayValue(pathsList, nbPaths, 0);
    while(nbPaths != 0) {
        path_addNearNeighbor(&newTour,pathsList, &nbPaths);
    }
   
    return newTour;
}
bool genetic_mutation(Tour* pTour, float pProba) {
    int firstNb, secondNb;
    bool retMutation = false;
    
    if(rand() % 100 < pProba*100) {
        firstNb=util_rand(0, pTour->nbTowns-1);
        secondNb=util_rand(0, pTour->nbTowns-1);            
        tour_2opt(pTour, firstNb, secondNb);
        
        retMutation = true;
    }

    return retMutation;
}
Tour genetic_getBestPath(Instance pInstance, const int pNbTour, const int pNbGeneration, const float pProba) {
    Tour* population;
    Tour children;
    int i;
    int firstNb, secondNb;
    int nbMutation = 0;
    
    //Pour éviter les segmentation fault en cas de nombre passés en paramètre trop grands
    population = malloc((pNbGeneration+pNbTour)* sizeof(Tour)); 
    
    for(i=0 ; i < pNbTour ; ++i) {
        population[i] = tour_randomWalk(pInstance);
    }
    
    for(i=0 ; i < pNbGeneration ; ++i) {
        firstNb=util_rand(0, pNbTour-1);
        secondNb=util_rand(0, pNbTour-1);
        
        children = genetic_DPX(population[firstNb], population[secondNb]);
            if(genetic_mutation(&children, pProba)) {
                ++nbMutation;
            }
                    
        tour_replaceTheWorstTour(population, pNbGeneration, children);
    }
    
   tour_calculLength(&children);
   if(gVerboseMode) {
       printf("La fille à muté %d fois\n", nbMutation);
   }
    return children;
}