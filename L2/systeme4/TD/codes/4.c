#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define N 5 
int main(int argc, char** argv) {
	pid_t pid;
	// TODO
	switch() {
		case -1:
			perror("fork");
			exit(1);
		default: //père
	}
	return 0;
}
