#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void traitFils1();
void traitFils2();

int main(int argv, char** argc) {
	pid_t idProc ;
	int rapport, numSignal, statut;


	/* processus pere */
	/* creation du fils1 */
	idProc = fork();
	switch (idProc) {
	   case -1 : 
		   perror("echec fork");
		   exit(1); 
	   case 0 :/*  appel du traitement fils1 */ 
		   traitFils1(); 
		   exit(1); 
	}

	/* creation du fils2 */
	idProc = fork() ;
	switch (idProc)
	{
	   case -1 : 
		   perror("echec fork");
		   exit(1); 
	   case 0 : /* appel du traitement du fils2 */
		   traitFils2(); 
		   exit(1) ; 
	}

	/* suite du processus pere */
	/* attente de la terminaison des fils */
	idProc = wait( &rapport ) ;
	while (idProc != -1) {
	   printf("\nTerminaison du fils de PID= %d\n", idProc);
	   numSignal = rapport & 0x7F ;
	   switch (numSignal) {
			case 0 : 
				statut = (rapport >>8)& 0xFF ;
				printf("Fin normale, statut= %d\n", statut); 
			break ;
			default : 
				printf("Fin anormale, numSignal= %d\n", numSignal);
	   }
	   idProc = wait(&rapport) ;
	}
}
/* fin du processus pere */
/* traitement du fils1 */
void traitFils1() {
	printf("\n***fils1 --> PID= %d\n", getpid());
	exit(3);
}
/* traitement du fils2 */
void traitFils2() {
	int v=10, int* ptr = NULL;
	printf("\n***fils2 --> PID= %d\n", getpid());

	*ptr = 42;
}

