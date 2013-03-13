#ifndef __SERVICE_LIAISON
#define __SERVICE_LIAISON
#define TAILLE_MAX 82 
#include "couche_liaison.h"
#include "physique.h"
trame_t initialiser_trame(void);
/*  Primitive pour transférer une unité de données */
/*  Equivalent dans le monde OSI : L_UNIT_DATA.req */
void emettre_sur_liaison(char* adr_src, char* adr_dest, char* msg, int lg_msg);

/*  Primitive pour récupérer une unité de données */
/*  Equivalent dans le monde OSI : L_UNIT_DATA.ind */
/*  Valeur de retour : taille du message */
int recevoir_de_liaison(char* adr_src, char* adr_dest, char* msg);

/*  Primitive de demande d'établissement d'une connexion */
/*  Equivalent dans le monde OSI : L_CONNECT.req et L_CONNECT.conf */
/*  Valeur de retour : réponse à la demande de connexion
 *  (1 acceptation, 0 refus) */
int etablir_connexion_liaison(char* adr_src, char* adr_dest);

/*  Primitive pour notifier d’une demande de connexion */
/*  Equivalent dans le monde OSI : L_CONNECT.ind */
void recevoir_demande_connexion_liaison(char* adr_src, char* adr_dest);

/*  Primitive de réponse à la demande de connexion */
/*  Equivalent dans le monde OSI : L_CONNECT.resp */
void repondre_demande_connexion_liaison(int reponse);

/*  Primitive pour transférer une unité de données au sein d'une connexion */
/*  Equivalent dans le monde OSI : L_TX_DATA.req */
void emettre_sur_liaison_connectee(char* msg, int lg_msg);

/*  Primitive pour récupérer une unité de données au sein d'une connexion */
/*  Equivalent dans le monde OSI : L_TX_DATA.ind */
/*  Valeur de retour : taille du message */
int recevoir_de_liaison_connectee(char* msg);

/*  Primitive pour mettre fin à une connexion */
/*  Equivalent dans le monde OSI : L_DISCONNECT.req */
void terminer_connexion_liaison();

/*  Primitive de notification d'une fermeture de connexion */
/*  Equivalent dans le monde OSI : L_DISCONNECT.ind */
void recevoir_terminaison_connexion_liaison();

#endif
