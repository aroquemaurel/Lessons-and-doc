#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int pid;

	switch(pid=fork()) {
		case -1:
			exit(1);
			break;
		case 0: //fils
			printf("Exécuté par le fils -- Père: %d\nFils: %d\n", getppid(), getpid());
			break;
		default: //père
			printf("Exécuté par le père -- père: %d\n", getpid());
		
	}
}
