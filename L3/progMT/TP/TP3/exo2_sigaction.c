#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handlerFather(int sig);
void handlerChild(int sig);

int main(int argc, char** argv) {
	int i = 0 ;
	int pid;
	struct sigaction action;
	action.sa_handler = handlerFather;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);

	switch(pid = fork()) {
		case -1:
			return EXIT_FAILURE;
		case 0:
			for(i=0 ; i < 20 ; ++i) { // on affiche 20 fois les messages, puis on s'arrête
				action.sa_handler = handlerChild;
				sigaction(SIGUSR1, &action, NULL);
				kill(getppid(), SIGUSR1);
				sigsuspend(&(action.sa_mask));
			}
			exit(0);
	}

	for(i=0 ; i < 20 ; ++i) {
		sigaction(SIGUSR1, &action, NULL);
		sigsuspend(&(action.sa_mask));
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
