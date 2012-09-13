/* carreMagique.h 
	entête des fonctions de carreMagique.cpp concernant le calcul d'un carré magique*/


// returne vrai si la matrice carré d'ordre n est magique
// nécessite 0 <= n < TAILLE
bool estCarreMagique (const Carre carre, const int n)
	throw (std::string);

// retourne la somme de la première diagonale de la matrice carré d'ordre n	
// nécessite 0 <= n < TAILLE
int sommeDiagonale1 (const Carre carre, const int n)
	throw (std::string);

// retourne la somme de la seconde diagonale de la matrice carré d'ordre n	
// nécessite 0 <= n < TAILLE
int sommeDiagonale2 (const Carre carre, const int n)
	throw (std::string);

// retourne la somme de la colonne j de la matrice carré d'ordre n	
// nécessite 0 <= n < TAILLE
// nécessite 0 <= j < TAILLE	
int sommeColonne(const Carre carre, const int n, const int j)
	throw (std::string);

// retourne la somme de la ligne i de la matrice carré d'ordre n	
// nécessite 0 <= n < TAILLE
// nécessite 0 <= i < TAILLE	
int sommeLigne(const Carre carre, const int n, const int i)
	throw (std::string);

// construit le carré magique d'ordre n
// nécessite 0 <= n < TAILLE
void construireCarreMagique(Carre &carre, const int n)
	throw (std::string);
// construit le carré magique d'ordre 6
void construireCarreMagique6(Carre &carre);

