#include <stdlib.h>
#define N 100

void read (int nb, int* tab) ;
void calculerMinMax(int nb, int* t, int *pmin, int *vmin, int *pmax, int *vmax);
void read (int nb, int* tab) ;

int main (int argc, char** argv) {
	int pmin, vmin, pmax, vmax;
	int tab[N];
	read(10, tab);
	calculerMinMax(10, tab, &pmin, &vmin, &pmax, &vmax);
	printf(...);
}
// un tableau est un pointeur sur le premier élément
// peut aussi être écrit int tab[N]
void read (int nb, int* tab) {
	int i;
	for(i=0; i < nb ; ++i) {
		scanf('%d', tab+i);
	}
}

void calculerMinMax(int nb, int *tab, int *pmin, int *vmin, int *pmax, int *vmax) {
	*pmin = 0;
	*pmax = 0;
	*vmin = t[pmin];
	*vmax = t[pmax];

	for(; --nb = b > 0;) {
		if(tab[nb] < *vmin) {
			*vmin = tab[nb];
			*pmin = nb;
		}
		if(tab[nb] > *vmax) {
			*vmax = tab[nb];
			*pmax = nb;
		}
	}
}
