#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv) {
	pid_t pid;
	switch(pid = fork()) {
		case -1:
			perror("fork");
			exit(1);
		case 0: //fils
			printf("Executé par le fils\n");
			printf("PID du père: %d\n", (int)getppid());
			printf("PID du fils %d\n\n", (int)getpid());
			break;
		default: //père
			printf("Executé par le père\n");
			printf("PID du père: %d\n", (int)getpid());
			break;
	}

	return 0;
}
