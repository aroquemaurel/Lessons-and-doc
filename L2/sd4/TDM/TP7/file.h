#include "element.h"
#define N 1000 
struct eltFile {
	Element tab[N];
	int nb;
	int tete; // Buffer en rond
} FileInterne;

typedef struct eltFile* File ;

File creerFile();
File enfile(File pFile, Element pElement);
File defiler(File pFile);
int appartient(File f, Element x);
Element premier(File pFile);
Element dernier(File pFile);
int fileEstPleine(File pFile);
int fileEstVide(File pFile);
