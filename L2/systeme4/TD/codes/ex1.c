#include <stdio.h>

int main(void) {
	FILE* f;
	char c1,c2,ch[81];
	int n;
	f = fopen("fich.txt", "r+");
	c1 = fgetc(f);
	c2 = fgetc(f);
	fcanf(f, "%d", &n);
	fclose(f);

	fprintf("%c%c %s %d\n", c1, c2, ch, &n);

	return 0;
}
