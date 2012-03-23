/***********************************************
*  ASR => Gpr3                                 *
************************************************
*  Login : drn0073a                            *
*          smm0569a                            *
************************************************
*  Groupe: B                                   *
*                                              *
************************************************
*  Nom-prénom : de ROQUEMAUREL Antoine         *
*  Nom-prénom : SOUM Mathieu                   *
*                                              *
*                                              *
************************************************
*  TP n°: 3                                    *
************************************************
*  Nom du fichier : signal1-fifo.c             *
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>

typedef void (*PtrFct)(int);

void showSignal(int);

int main(void) {
	PtrFct fctExec;
	int erreur;
	int descFIFO;
	int* pid;

	pid = malloc(sizeof(int));
	*pid = getpid();

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

		erreur = mkfifo("data.FIFO", 0600);

		descFIFO = open("data.FIFO", O_WRONLY);

		write(descFIFO, pid, sizeof(int));

		close(descFIFO);
	}
	return 0;
}

void showSignal(int sig) {
	printf("Bye!\n");
	exit(0);
}


