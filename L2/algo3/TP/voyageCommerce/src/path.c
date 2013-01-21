/**
 * \file path.c
 * \brief Fonctions des trajets.
 * \author Antoine de Roquemaurel
 * \date 11/01/2013 03:12:13
 *
 * Implémentations des fonctions se rapportant à un trajet.  
 */

#include "path.h"
#include "util.h"

Path path_new(Tour pTour, int pBegin, int pEnd) {
    int i;
    Path newPath;
    newPath.nbTowns = pEnd-pBegin;
    for(i = 0 ; i < newPath.nbTowns ; ++i) {
        newPath.towns[i] = pTour.towns[pBegin+i];
    }
    
    return(newPath);
}

void path_addNearNeighbor(Tour* pTour, Path* pPathsList, int* pNbPathsList) {
    int i, buffId=0;
    bool endOfPath = false;
    Path buffPath=pPathsList[0];
    Distance buffDistance;
    double buffDistBegin, buffDistEnd;
    buffDistance.distance = distance_calculDistance(pTour->towns[pTour->nbTowns-1], pPathsList[0].towns[0]);
    
    for(i=0; i < *pNbPathsList ; ++i) {
        buffDistBegin = distance_calculDistance(pTour->towns[pTour->nbTowns-1], pPathsList[i].towns[0]);
        buffDistEnd = distance_calculDistance(pTour->towns[pTour->nbTowns-1], pPathsList[i].towns[pPathsList[i].nbTowns-1]);
        
        /* On gère les cas pour lesquels les trajets le 
         * plus proches sont soit à l'extrémité du début, soit de la fin
         */
        if(buffDistBegin < buffDistance.distance) { 
            buffDistance = distance_new(pTour->towns[pTour->nbTowns-1], pPathsList[i].towns[0]);
            buffPath = pPathsList[i];
            endOfPath = false; 
            buffId=i;
        } else if (buffDistEnd < buffDistance.distance) { 
            buffDistance = distance_new(pTour->towns[pTour->nbTowns-1], pPathsList[i].towns[pPathsList->nbTowns-1]);
            buffPath=pPathsList[i];
            buffId=i;
            endOfPath = true;
        }
    } 
    
    /* S'il faut retourner le trajet, on renverse l'array, 
     * puis on ajoute le trajet à la suite de la tournée
     */
    if(endOfPath) {
        util_reverseArray(buffPath.towns, 0, buffPath.nbTowns-1);
    }
    tour_addSeveralTowns(pTour, buffPath.towns, buffPath.nbTowns);
    
    util_deleteArrayValue(pPathsList, *pNbPathsList, buffId); //Maintenant le trajet à été placé
    *pNbPathsList = *pNbPathsList-1; 
}

void path_display(const Path pPath) {
    int i;
    for(i = 0 ; i < pPath.nbTowns ; ++i) {
        town_display(pPath.towns[i]);
        printf(" ");
    }
    printf("\n");
}