#include <stdio.h>
int main(void) {
	f = fopen("fich2.txt","wt");
	fputc('z', f);
	fput('\n', f);
	fprintf(f, "Entier %d\n Floatant %f\n", 12, 3.14);
	fprintf("Chaine\n", f);
	fclose(f);
}
