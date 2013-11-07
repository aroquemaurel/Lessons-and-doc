#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig, siginfo_t *si, void *unused);
int main(int argc, char** argv) {
	struct sigaction action;
	action.sa_handler = handler;
	action.sa_flags = 0;
	
	sigaction(SIGINT, &action, NULL);
	for(;;);

	return EXIT_SUCCESS;
}

void handler(int sig, siginfo_t *si, void *unused) {
	static int cpt = 0;
	++cpt;
	if(cpt >= 10) {
		exit(0);
	} 
}
