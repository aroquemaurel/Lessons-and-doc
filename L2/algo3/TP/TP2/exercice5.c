#include <stdio.h>

int main(int argc, char** argv) {
	int i = 0;
	int u;

	printf("Taper u1: ");
	scanf("%d", &u);

	do {
		printf("%d ", u);
		++i;

		if(u == 1) {
			break;
		}

		if(u % 2 == 0) {
			u /= 2;
		} else {
			u = 3 * u + 1;
		}
	} while(u >= 1) ;

	printf("\nElle à pour longueur %d", i);

	return 0;
}
