#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig);
int main(int argc, char** argv) {
	int i;
	signal(SIGINT, handler);
	for(;;);

	return EXIT_SUCCESS;
}

void handler(int sig) {
	static int cpt = 0;
	++cpt;
	if(cpt < 10) {
		signal(SIGINT, handler);
	} else {
		exit(0);
	}
}
