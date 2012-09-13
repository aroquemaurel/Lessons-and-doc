/* matrices.h 
	entête des fonctions de matrices.cpp concernant le calcul de matrices*/

const int TAILLE = 100;
typedef int Carre[TAILLE][TAILLE];

/* la matrice medgig, permettant de générer un carré magique */
const int MEDGIG[6][6] =  {2,3,0,2,0,2,
							1,0,3,1,3,1,
							3,1,1,2,2,0,
							0,2,0,3,3,1,
							3,2,2,0,0,2,
							0,1,3,1,1,3};

// returne vrai si le nombre i est impair
bool estImpair(const int i);

/* affiche une matrice carrée d'ordre n d'entier désignée par carré 
lève l'exception "ORDRE INCORRECT" si n ne vérifie pas 0 <= n <= TAILLE */
void ecrireCarre (const Carre carre, const int n)
	throw (std::string);

/* lit une matrice carré d'ordre n d'entiers désignée par carré à partir 
de valeurs saisies au clavier
lève l'exception "ORDRE INCORRECT" si n ne vérifie pas 0 <= n <= TAILLE */
void lireCarre (Carre &carre, const int n)
	throw (std::string);

/* Initialise une matrice carré d'entier d'ordre n à zéro
	lève l'exception "ORDRE INCORRECT" si n ne vérifie pas 0 <= n <= TAILLE */
void initialiserCarre (Carre &carre, const int n)
throw (std::string);

