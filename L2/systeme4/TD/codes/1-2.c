#define _POSIF_C_SOURCE 1

#include <stdio.h>

int main(int argc, char** argv, char** envp) {
	int i;
	printf("Argument :\n");
	for(i=1; i < argc ; ++i) {
		printf("argv[%d]=%s\n", i, argv[i]);
	}
	i=0;
	while(envp[i] != NULL) {
		printf("%s\n", envp[i++]);
	}

	return 0;
}
