#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handlerFather(int sig);
void handlerChild(int sig);

int main(int argc, char** argv) {
	int pid;
	int i;
	switch(pid = fork()) {
		case -1:
			return EXIT_FAILURE;
		case 0:
			for(i=0 ; i < 20 ; ++i) { // on affiche 20 fois les messages, puis on s'arrête
				signal(SIGUSR1, handlerChild);
				kill(getppid(), SIGUSR1);
				pause(); // On attend le père
			}
			exit(0);
	}

	for(i=0 ; i < 20 ; ++i) {
		signal(SIGUSR1, handlerFather);
		pause(); // On attend le fils
		kill(pid, SIGUSR1);
	}

	return EXIT_SUCCESS;
}

void handlerFather(int sig) {
	printf("je suis le père\n");
}

void handlerChild(int sig) {
	printf("je suis le fils\n");
}
