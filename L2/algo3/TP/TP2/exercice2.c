
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
	int i = 0;
	int j = 0;

	for(i = 'a' ; i <= 'z' ; ++i) {
		for(j = 0; j < i-96-1 ; ++j) {
			printf("\t");
		}
		printf("%c\n", i);
	}

	printf("\n\t------\n\n");

	for(i = 'a'; i <= 'z' ; ++i) {
		for(j = 'a' ; j <= 'z' ; j++) {
			printf("%c%c ", i, j);
		}
		printf("\n");
	}

	printf("\n\t------\n\n");

	for(i = 1 ; i <= 10 ; ++i) {
		for(j = 1 ; j <= 10 ; ++j) {
			if(j*i < 100) {
				printf(" ");
			}
			if(j*i < 10) {
				printf(" ");
			}
			printf(" %d ", (j)*i);
		}
		printf("\n");
	}

	return 0;
}
