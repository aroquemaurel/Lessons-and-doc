#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char** argv) {
	int pidAKill;

	pidAKill = atoi(argv[1]);
	kill(pidAKill, SIGUSR1);

	return 0;
}

