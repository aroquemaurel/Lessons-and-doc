#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat_exo1(char* ch1, char* ch2);
char* saisie_exo2();
void swap_exo3(char* ch1, char* ch2);
void trierFichier_exo4(FILE* pFile, FILE* pFileOuput);
void triTableau(char **p,int taille);
char* remplacementPremiereOccurence_exo6(char *chaine, char *souschaineARemplacer, char *souschaineDeRemplacement);
char* remplacementToutesOccurences_exo6(char *chaine, char *souschaineARemplacer, char *souschaineDeRemplacement);
void remplacementToutesOccurencesAvecMaj_exo6(char **chaine, char *souschaineARemplacer, char *souschaineDeRemplacement);
void manipulerJoursSemaine_exo7(void);
void exo8(void);
int main(int argc, char** argv) {
	char* str = "blabla"; 

/*  FILE* fileInput = fopen(argv[1], "r+");
	FILE* fileOutput = fopen(argv[2], "w+");

	if(fileInput != NULL) {	
		trierFichier_exo4(fileInput, fileOutput);
	} else {
		fprintf(stderr, "Erreur fichier");
		return EXIT_FAILURE;
	}
*/
	 str = remplacementPremiereOccurence_exo6("blabla", "bla", "to");
	 printf("%s ", str);
	 str = remplacementToutesOccurences_exo6("blabla", "bla", "to");
	 printf("%s ", str);
	 remplacementToutesOccurencesAvecMaj_exo6(&str, "bla", "to");
	 printf("%s", str);
	 printf("\n");
	 manipulerJoursSemaine_exo7();
	 exo8();
	return 0;
}

char* concat_exo1(char* ch1, char* ch2) {
	char* stringRet;		
	strcpy(stringRet, ch1);
	strcat(stringRet, ch2);

	return stringRet;
}

char* saisie_exo2() {
	char* retour;
	char buff;
	retour = (char*) malloc(sizeof(char));

	do{
		retour = realloc(retour, strlen(retour)+1*sizeof(char));
		scanf("%c", &buff);
		retour[strlen(retour)] = buff;
	} while(buff != 10);

	return retour;
}

void swap_exo3_dynamique(char* ch1, char* ch2) {
	char* buff;
	buff = malloc(sizeof(char));
	buff = ch1;
	ch1 = ch2;
	ch2 = buff;
}

void swap_exo3_static(char* ch1, char* ch2) {
	char buff[32];
	strcpy(buff, ch1);
	strcpy(ch1, ch2);
	strcpy(ch2, buff);
}

void trierFichier_exo4(FILE* pFile, FILE* pFileOuput) {
	char** mots;
	mots = (char**)malloc(sizeof(char*));
	int nbMots = 0;
	int i;

  while(!feof(pFile)) {
		mots = (char**)realloc(mots, nbMots*sizeof(char*)+1);
		mots[nbMots] = malloc(sizeof(char));
		fgets(mots[nbMots], 30, pFile);
		nbMots++;
	}

  triTableau(mots, nbMots);
  for(i = 0 ; i < nbMots ; ++i) {
	 // TODO Ouvrir newFile en ecriture
	  fputs(mots[i], pFileOuput);
  }
}

/*
 * Tri un tableau de chaine de caractère
 */
void triTableau(char **p,int taille) {
     int i,j;
 
     char* temp;
     for(i=0;i<taille;i++) {     
           for(j=i;j<taille;j++) {
                   if(strcmp(p[i],p[j])>0) {
                         temp=p[j];
                         p[j]=p[i];
                         p[i]=temp;
                   }   
           }
     }
}

char* remplacementPremiereOccurence_exo6(char *chaine, char *souschaineARemplacer, char *souschaineDeRemplacement)
{
	static char buffer[9096];
	char *p;
		 
	if(!(p = (char *)strstr(chaine, souschaineARemplacer))) 
		return chaine;
		   
	strncpy(buffer, chaine, p-chaine); 
	buffer[p-chaine] = '\0';
	   
	sprintf(buffer+(p-chaine), "%s%s", souschaineDeRemplacement, p+strlen(souschaineARemplacer));
			 
	return buffer;
}

char* remplacementToutesOccurences_exo6(char *chaine, char *souschaineARemplacer, char *souschaineDeRemplacement) {
	char* str1 = chaine; 
	char* str2; 

	do {
		str2 = str1;
		str1 = remplacementPremiereOccurence_exo6(str1, souschaineARemplacer, souschaineDeRemplacement);
	} while(strcmp(str1,str2) != 0 ); 
	
	return str1;
}

void remplacementToutesOccurencesAvecMaj_exo6(char **chaine, char *souschaineARemplacer, char *souschaineDeRemplacement) {
	char* str1 = *chaine; 
	char* str2; 

	do {
		str2 = *chaine;
		*chaine = remplacementPremiereOccurence_exo6(*chaine, souschaineARemplacer, souschaineDeRemplacement);
	} while(strcmp(*chaine,str2) != 0 ); 
	
}

void manipulerJoursSemaine_exo7(void) {
	char** jours;
	char* jours2[7]={"lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"};
	int i;
	jours = (char**)malloc(sizeof(char*)*7);
	for(i=0 ; i < 7 ; ++i) {
		jours[i] = (char*) malloc(sizeof(char));
	}
  strcpy(jours[0], "lundi");
    strcpy(jours[1], "mardi");
	strcpy(jours[2], "mercredi");
	strcpy(jours[3], "jeudi");
	strcpy(jours[4], "vendredi");
	strcpy(jours[5], "samedi");
	strcpy(jours[6], "dimanche");

	for(i = 0 ; i < 7 ; ++i) {
		printf("%s %s\n", jours[i], jours2[i]);
		jours[i][0] -= 32; // on met la première lettre en majuscule
		jours2[i] = remplacementPremiereOccurence_exo6(jours2[i], &jours2[i][0], &jours[i][0]); //on remplace la première lettre par sa correspondance en majuscule
		printf("%s %s\n", jours[i], jours2[i]);
		free(jours[i]); //on libère la mémoire allouée dynamiquement
	}
	free(jours);
}

struct S1 {
	int a;
	char *ch;
};

struct S2 {
	int a;
	char ch[40];
};


void exo8(void) {
	struct S1 v11, v12;
	struct S2 v21, v22;

	v11.a = 3;
	v11.ch = "Kangourou";
	v21.a = 5;
	strcpy(v21.ch, "Koala");

	/* En mémoire, les entiers vont être recopiés normalement, par valeur.
	 * pour les chaînes, ce sera les adresses qui seront recopiées étant donné que ce sont des pointeurs.
	 */
	v12 = v11;
	v22 = v21;

	// Non elle n'entraine pas celle de V21.
	v11.ch = "Renard";
//	v11.ch[0] = 'c'; entrainera une segmentation fault
	strcpy(v21.ch, "Lapin");
	v21.ch[0] = 'c';
}

// l'exercice 9 à été effectué lors de l'exercice 4. En effet, j'ai utilisé un vecteur de mot 
// afin de stocker les mots du dictionnaire, puis j'ai trié ce tableau que j'ai enfin écrit dans un nouveau fichierr. Cf trierFichier_exo4
