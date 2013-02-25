#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

typedef void ( *PtrFct) (int);

void traiterSIGUSR1(int sig);
int main (int argc, char** argv) {
	PtrFct retFct ;
	retFct=signal( SIGUSR1, traiterSIGUSR1 );

	if (retFct == SIG_ERR) { 
		perror("echec signal"); 
		exit(1); 
	}

	while (42) {
		sleep(5);
	}
}
void traiterSIGUSR1(int sig) {
	switch ( sig ) {
		case SIGUSR1 : printf("PID= %d\n", getpid() );
			printf("n° du signal recu = %d\n", sig );
			break;
		default :    printf("\n Erreur système !!!!\n");
	}
	exit(2);
}

