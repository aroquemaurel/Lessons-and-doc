#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int x = 2008;
	int* p = x;

	*p *= 10;
	printf("%d %d", x, *p);
	return 0;
}
