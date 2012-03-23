#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
	printf("Ici le processus fils 1 de PID %d !\n", getpid());
	printf("La chaine passée en paramètre est : %s\n", argv[1]);
	exit(0);

	return 0;
}
