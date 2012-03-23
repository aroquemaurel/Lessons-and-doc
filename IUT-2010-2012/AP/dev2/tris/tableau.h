#include <iostream>
const int LG_MAX = 300;

typedef int Tableau[LG_MAX];

// ecrit les n premiers elements du tableau t
// necessite 1 <= n <= LG_MAX
void ecrireTableau (const Tableau t, const int n); 

// remplit les n premiers elements du tableau t avec des valeurs aleatoires
// necessite 1 <= n <= LG_MAX
void remplirTableau (Tableau t, const int n);
