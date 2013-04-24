/************************************
 * UPS - L2 Informatique - Réseaux  *
 *                                  *
 * emetteur.c : programme principal *
 ***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "service_liaison.h" /* emettre_sur_liaison, etc. */
#include "physique.h" /* Initialisation "physique" */

/*
 * Parametres du programme :
 *   aucun en version simple (mode local)
 *   port_local, machine_destination, port_destination en version distribuee
 */
int main(int argc, char* argv[])
{
	char addest[6] = {'A','A','A','A','A','\0'};
	char adsource[6] = {'B','B','B','B','B','\0'};
    char donnees[TAILLE_MAX]; /* Taille max des donnees : A DEFINIR */ 
    FILE*	fich;
    int	lg, cpt = 0;
    
    /* Pour la version distribuee */ 
    //initialisation(0.f, 0.f, (short) atoi(argv[1]), argv[2], (short) atoi(argv[3]));
    
    /* Pour la version simple */
    initialisation_simple(0.4, 0.7, 0);
    
    /* Ouverture du fichier en lecture */
//    fich = fopen("in.txt", "r");
    fich = fopen("soleil.jpg", "r");
    if (fich == NULL) {
        printf("Fichier in.txt non present\n");
        return 1;
    }
	printf("[couche appli] Envoie demande de connexion\n");
	if(!etablir_connexion_liaison(adsource,addest)) {
		printf("Connexion refusée");
		return 1;	
	}
	printf("[couche appli] Début de transmission\n");

    /* Tant qu'on n'a pas fini de lire le fichier */
    while (!feof(fich)) {
        /* Lecture du fichier */
        /* on lit au maximum TAILLE_MAX */
        lg = fread(donnees, 1, TAILLE_MAX, fich);
        
        /* Si on a lu au moins 1 caractere */
        if ( lg > 0 ) {
            printf("\n[couche appli] Envoi numero %d\n",cpt);
			emettre_sur_liaison_connectee(donnees,lg);

            cpt++;          
        }
	}
	/* On envoie un message de fin */
	donnees[0] = '\a'; 

	emettre_sur_liaison_connectee(donnees,1);
	/*  TODO Gestion si trame perdue */
	printf("[couche appli] Envoi fin de transmision\n"); 
	terminer_connexion_liaison();
	printf("[couche appli] Fin de transmission.\n");
	fclose(fich);
	return 0;
}

