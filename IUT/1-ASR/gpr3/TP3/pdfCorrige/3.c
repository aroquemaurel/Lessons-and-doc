#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <setjmp.h>

#define TIMEOUT1 1
typedef void(* PtrFct)(int);

void timeout(int sig);
jmp_buf ptRep; /* doit etre declare en variable globale */

int main (int argc, char** argv) {
	PtrFct retFct;
	int ret;
	int nbEssai=0;
	unsigned duree=10; /* delai d'attente 10 sec */
	char mess[257];

	retFct = signal(SIGALRM, timeout);
	if (retFct == SIG_ERR) { 
		perror("echec signal"); 
		exit(1); 
	}
	ret = setjmp(ptRep);
	if (ret == TIMEOUT1 ) {
	   if (nbEssai > 2 ) { 
		   printf("echec saisie!!!\n");
		   exit(2); 
	   }
   }
	nbEssai++;
	printf("entrer votre message:\n");
	alarm(duree);
	fgets(mess,256,stdin);
	alarm(0);
	printf("saisie OK !!!\n");
}
void timeout(int sig) {
	switch (sig) {
		case SIGALRM : printf("n° du signal recu = %d\n", sig );
			sigrelse(SIGALRM);        /* demasquer le signal SIGALRM */
			longjmp(ptRep,TIMEOUT1);
		default :     
			printf("\n Erreur système !!!!\n");
			exit(3);
	}
}

