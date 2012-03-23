#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
	pid_t idProc ;
	int err,rapport, numSignal, statut;
	char * tabParam[3]={"p2fils2", "123456", NULL};

	/* processus pere */
	/* creation du fils1 */
	idProc = fork();
	switch (idProc) {
	   case -1 : 
		   perror("echec fork");
		   exit(1);
	   case 0 : /* execution du traitement du fils1 */
			err=execl("./p2fils1", "p2fils1", "coucou", NULL);
			if (err == -1) { 
				perror("echec execl");
				exit(2);
			}
	}

	/* creation du fils2 */
	idProc = fork();
	switch (idProc) {
	case -1 : 
		perror("echec fork");
		exit(1); 
	case 0 : /* execution du traitement du fils2 */
		err=execvp("p2fils2", tabParam);
		if (err == -1) { 
			perror("echec execvp");
			exit(3);
		}
	}

	/* suite du processus pere */
	/* attente de la terminaison des fils */
	idProc = wait( &rapport );
	while ( idProc != -1 ) {
	   printf("\nTerminaison du fils de PID= %d\n", idProc);
	   numSignal = rapport & 0x7F ;
	   switch (numSignal) {
			case 0 :
				statut = ( rapport >> 8 ) & 0xFF ;
				printf("Fin normale, statut= %d\n", statut);
			break ;
			default :
				printf("Fin anormale, numSignal= %d\n", numSignal);
	   }
	   idProc = wait( &rapport ) ;
   }
}
/* fin du processus pere */
