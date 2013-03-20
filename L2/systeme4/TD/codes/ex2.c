#include <stdio.h>

int main(void) {
	FILE* f;
	float tab[100];
	int i, n;

	f = fopen("fich1.data", "rb");
	n = fread(tab, sizeof(float), 100, f);
	for( i=0 ; i < n ; ++i ) {
		printf("%f\n", tab[i]);
	}
	fclose(f);
	return 0;
}

/*  Autre possibilité */
int main(void) {
	FILE* f;
	float tab[100];
	int i, n;

	f = fopen("fich1.data", "rb");
	while((fread(&tab[i], sizeof(float), n, f) != 0)) {
		++i;
		n = i;
	}
	for( i=0 ; i < n ; ++i ) {
		printf("%f\n", tab[i]);
	}
	fclose(f);
	return 0;
}
