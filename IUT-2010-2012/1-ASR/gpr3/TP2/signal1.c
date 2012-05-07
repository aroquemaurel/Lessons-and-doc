#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

typedef void (*PtrFct)(int);

void showSignal(int);

int main(int argc, char** argv) {
	PtrFct fctExec;

	system("echo Login : $USER");
	system("echo UID : $UID");
	system("date");
	printf("\n");

	while (1337) {
		fctExec = signal(SIGUSR1, showSignal);

		if (fctExec == SIG_ERR) {
			perror("Et là... c'est le drame !");
			exit(1);
		}
	}
	return 0;
}

void showSignal(int sig) {
	printf("Mon pid c'est %d et j'ai recu le signal %d !", getpid(), sig);
	exit(0);
}


