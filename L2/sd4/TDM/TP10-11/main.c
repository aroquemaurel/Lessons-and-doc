#include <stdio.h>
#include "arn.h"

void* compare_int(void* premierOperande, void* secondeOperande);
void afficher_int(void* valeur, Couleur couleur);
char* affiche_noeud(void* valeur, Couleur couleur);
void ecrireDotEtapes(ARN t, char* repertoire);

void* compare_int(void* premierOperande, void* secondeOperande) {
	int op1 = (int)premierOperande;
	int op2 = (int)secondeOperande;
	int retour;

	if(op1 < op2) {
		retour = -1;
	} else if (op1 > op2) {
		retour = 1;
	} else {
		retour = 0;
	}

	return retour;
}


int main() {
	int i=0;
	char *repertoire = "arbreRougeNoir_dot"; // le repertoire ou seront entreposés les .dot et .png
	char commandeDot[256] = "./scriptDot.sh ";
	strcat(commandeDot, repertoire);
	strcat(commandeDot, "/fichier");

	ARN t = arn_creer();
	arn_inserer(t, (void*) 18, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_inserer(t, (void*) 98, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_inserer(t, (void*) 51, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_inserer(t, (void*) 70, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_inserer(t, (void*) 62, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_inserer(t, (void*) 42, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_supprimer(t, (void*) 98, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_supprimer(t, (void*) 51, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_inserer(t, (void*) 69, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_inserer(t, (void*) 132, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_supprimer(t, (void*) 18, compare_int);
	ecrireDotEtapes(t, repertoire);
	arn_inserer(t, (void*) 1, compare_int);
	ecrireDotEtapes(t, repertoire);

	system(commandeDot); // on lance un script shell qui génère tous les .png et un .gif
	return 0;
}


char* affiche_noeud(void* valeur, Couleur couleur) {
	static char ret[256];
	sprintf(ret,"%d", (int)valeur);
	return ret; 
}

void afficher_int(void* valeur, Couleur couleur) {
	printf("%s%d ", (couleur == ROUGE) ? "\033[01;31m" : "\033[0m", valeur);
}

void ecrireDotEtapes(ARN t, char* repertoire) {
	static int i = 1;
	char fileName[256];
	sprintf(fileName, "%s/fichier%d.dot", repertoire, i);
	FILE* fichier = fopen(fileName, "w+");
	if (fichier == NULL) {
		perror("Erreur d'ouverture du fichier");
	}
	arn_ecrireFichierDot(t, affiche_noeud, fichier);
	fclose(fichier);
	++i;
}
