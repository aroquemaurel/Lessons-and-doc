#ifndef __PROTOCOLE_H__
#define __PROTOCOLE_H__

#define RECEPTION 0

/* Initialisation simple avec un taux de perte,
 *                               taux d'erreur,
 *                               sens de communication (si reception=1
 *                                  cote reception sinon cote emission)
 */
void initialisation_simple(float proba_perte, float proba_erreur, int reception);

/* Initialisation avec un taux de perte,
 *                        taux d'erreur et
 *                        des parametres reseau
 */
void initialisation(float proba_perte, float proba_erreur, unsigned short port_local, char* destination, unsigned short port_destination);

/* Attends un evenement et retourne
 *     soit 0 si un paquet recu est disponible
 *     ou un numero de timer si un timeout a ete genere
 */
int attendre();

/* Recoit une trame -
 *    taille doit etre sizeof(trame_t) ou trame_t est votre type trame
 */
void de_canal(void *trame, int taille);

/* Envoie une trame -
 *    taille doit etre sizeof(trame_t) ou trame_t est votre type trame
 */
void vers_canal(void *trame, int taille);

/* Demarre le timer numero n (0 < n < 100) qui s'arrete apres ms millisecondes
 * (ms doit etre un multiple de 100)
 */
void depart_compteur(int n, int ms);

/* Arrete le timer numero n
 */
void arreter_compteur(int n);


#endif
