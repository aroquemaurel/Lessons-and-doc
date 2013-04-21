/*************************************
 * UPS - L2 Informatique - Réseaux   *
 *                                   *
 * recepteur.c : programme principal *
 ************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "physique.h" /* Initialisation "physique" */
#include "service_liaison.h" /* emettre_sur_liaison, etc. */

/*
 * Parametres du programme :
 *   aucun en version simple (mode local)
 *   port_local, machine_destination, port_destination en version distribuee
 */
int main(int argc, char* argv[])
{
    char donnees[TAILLE_MAX]; /* Taille max des donnees : A DEFINIR */
	char addest[6] = {'A','A','A','A','A','\0'};
	char adsource[6] = {'A','A','A','A','A','\0'};
 
    int i, lg_donnees;
    int cpt=0;
    int continuer = 1;
    FILE* fich;
            
    /* Pour la version distribuee */ 
    // initialisation(0.f, 0.f, (short) atoi(argv[1]), argv[2], (short) atoi(argv[3]));
    
    /* Pour la version simple */
    initialisation_simple(0.0, 0.0, 1);

    /* Ouverture du fichier en ecriture */
    fich = fopen("out.txt", "w");
    if (fich == NULL) {
        printf("Fichier out.txt impossible a creer\n");
        return 1;
    }
	printf("[couche appli] Attente d'une demande de connexion\n");
	recevoir_demande_connexion_liaison(adsource,addest);
	printf("[couche appli] Connexion établie\n");

    /* Tant qu'on n'a pas fini de recevoir */
    while (continuer) {
        /* On reinitialise le tableau donnees */
        for (i = 0; i < TAILLE_MAX; i++)
            donnees[i] = '\0';
		lg_donnees = recevoir_de_liaison_connectee(donnees);
        /* On regarde si c'est le dernier message */

		/*  si on reçoit une demande de fermeture, on quitte la boucle */
        if (lg_donnees==1 && donnees[0]=='\a') { 
            /* Fermeture fichier et arret de la boucle */
            printf("[couche appli] Fin de reception.\n");
            continuer = 0;
            fclose(fich);
        } else {
            printf("[couche appli] Reception numero %d\n\n",cpt);
            
            /* Ecriture des donnees dans le fichier */
            fwrite(donnees, 1, lg_donnees, fich);           
            fflush(fich);
            cpt++;
        }
    }
	recevoir_terminaison_connexion_liaison();
	printf("[couche appli] Fin de transmission\n");
    return 0;
}

