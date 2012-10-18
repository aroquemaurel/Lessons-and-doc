/*
 *	 Exo1 : D´etermine l’´etendue(valeur max-valeur min, le nombre de valeurs dans I=[2,5], la 
 *	 somme des racines carr´ees de n r´eels 
 *	 Données : int n, ﬂoat val (x1, · · · , xn) 
 *	 Résultats : ﬂoat etendue, int nb val I, ﬂoat som rac 
 *
 *	 Antoine de Roquemaurel -- Groupe 1.1
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
	int i = 0;
	int numberValues = 0;
	int nbValuesInI = 0;
	float value = 0;
	double valueMin = 0;
	double valueMax = 0;
	double etendue = 0;
	double sqrtSumValues = 0;

	printf("Veuillez entrer le nombre de valeurs rééelles positives ");
	scanf("%d", &numberValues);

	for(; i < numberValues; ++i) {
		printf("Taper valeur numéro %d ", i);
		scanf(" %1f", &value);

		if(i == 0) {
			valueMin = value;
			valueMax = value;
		} else if (value < valueMin) {
			valueMin = value;
		} else if(value > valueMax) {
			valueMax = value;
		}

		if(value >= 2 && value <= 5) {
			++nbValuesInI;
		}
		sqrtSumValues += sqrt(value);
	}
	etendue = valueMax - valueMin;

	printf("\n\nL'étendue des valeurs est %f, le nombre de valeurs dans I est %d, la somme des racines carrées est %f", etendue, nbValuesInI, sqrtSumValues);
	return 0;
}
