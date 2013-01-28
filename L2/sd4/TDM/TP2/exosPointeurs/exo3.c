#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int x = 2008;
	int* p = x;
	int* r = x;

	*r += 1;
	printf("%d %d %d", x, *p, *r);

	return 0;
}
