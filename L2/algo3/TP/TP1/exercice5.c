#include <stdio.h>

int main(int argc, char *argv[]) {
	int a = 10;
	/* a sera tjrs différent de 0, sa valeur sera incrémentée jusqu'à atteindre la limite d'un int (2147483647) 
	 * a atteindra 0 et le programme s'arrêtera une fois la limite atteinte
	 */

	while(a != 0) { 
		a = a*a;
		printf("%d\n", a); 
	}
	return 0;
}
