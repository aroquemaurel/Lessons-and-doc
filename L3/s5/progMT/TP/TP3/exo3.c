#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define NB_CLIENTS1 2
#define NB_CLIENTS2 3
int tubeOuvriers[4][2]; // les tubes des ouvriers

void client(const int num);
void client1(const int num);
void client2(const int num);
void ouvrier(const int num);
void handlerClient1(int pSignal);
void launchClients1();
void launchClients2();
void launchOuvriers();

int sigusr1ok = 0;

typedef struct {
	pid_t pidClient;
	int numCommande;
	int numModifier;
} Commande;

int main(int argc, char** argv) {
	int i;
	for(i=0 ; i < 4 ; ++i) {
	  if(pipe(tubeOuvriers[i]) == -1) {
			perror("Erreur dans la création du tube");
			exit(2);
		}
	}

	launchOuvriers();
	launchClients1();
	launchClients2();

	// Le père ferme tous les tubes
	for(i=0 ; i < 4 ; ++i) {
		close(tubeOuvriers[i][0]);
		close(tubeOuvriers[i][1]);
	}

	while(wait(NULL) > 0);

	return EXIT_SUCCESS;
}

// On suppose que le travail des ouvriers est d'incrémenter une variable.
// et de la faire passer au suivant.
void ouvrier(const int num) {
	Commande commande;
	int i;

	for(i=0 ; i < 4 ; ++i) {
		if(i != num) {
			close(tubeOuvriers[i][0]);
			if(i != num+1) {
				close(tubeOuvriers[i][1]);
			} 
		}
	}
	close(tubeOuvriers[num][1]);
	while(read(tubeOuvriers[num][0], &commande, sizeof(Commande)) > 0) {
		// Lecteur dans tube ouvrier[1]
		switch(num) {
			case 0:
				printf("OUVRIER 0: On lance la commande %d\n", commande.numCommande);		
				break;
			case 1:
				// boulot ouvrier 1
				++commande.numModifier;
				printf("OUVRIER 1: commande %d: %d\n",commande.numCommande, commande.numModifier);
				break;
			case 2:
				// boulot ouvrier 2
				++commande.numModifier;
				printf("OUVRIER 2: commande %d: %d\n",commande.numCommande, commande.numModifier);
				break;
			case 3:
				// boulot ouvrier 3
				++commande.numModifier;
				printf("OUVRIER 3: commande %d: %d\n",commande.numCommande, commande.numModifier);
				break;
		}

		if(num != 3) {
			write(tubeOuvriers[num+1][1], &commande, sizeof(Commande));
		} else {
			printf("On a finis la commande %d ! \n", commande.numCommande);
			// On envoie sigusr1 au client
			kill(commande.pidClient, SIGUSR1);
		}
	}
	close(tubeOuvriers[num+1][1]);
	close(tubeOuvriers[num][0]);
}

// Client générique. Réutilisé par client1 et client2
void client(const int num) {
	Commande commande;
	int i;
	signal(SIGUSR1, handlerClient1);

	commande.pidClient = getpid();
	commande.numCommande = num;
	commande.numModifier = 5+num; // numéro modifié par les ouvriers, sert de tests

	for(i=1 ; i < 4 ; ++i) {
		close(tubeOuvriers[i][0]);
		close(tubeOuvriers[i][1]);
	}


	// On écrit dans le tube à destination de l'ouvrier 0 
	close(tubeOuvriers[0][0]);
	write(tubeOuvriers[0][1], &commande, sizeof(Commande));
	close(tubeOuvriers[0][1]);
}

void client1(const int num) {
	client(num);
	if(!sigusr1ok) { // dans le cas de client1, on pause
		pause();
	}

	printf("\tClient1: Je peux faire autre chose maintenant!\n");
}

void client2(const int num) {
	client(num);
	printf("\tClient2: Je peux faire autre chose maintenant!\n");
}

void handlerClient1(int pSignal) {
	printf("\tClient : enfin ma commande!\n");
	sigusr1ok = 1;
	signal(SIGUSR1, handlerClient1);
}

void launchClients1() {
	int i;
	for(i = 0 ; i < NB_CLIENTS1 ; ++i) {
		switch(fork()) {
			case -1:
				perror("Erreur dans la création du fils");
				exit(1);
			case 0:
				client1(i); 

				if(!sigusr1ok) { // on ne se termine que si on a reçus la commande !
					pause();
				} 
				exit(0);
		}
	}

}

void launchClients2() {
	int i;
	for(i = 0 ; i < NB_CLIENTS2 ; ++i) {
		switch(fork()) {
			case -1:
				perror("Erreur dans la création du fils");
				exit(1);
			case 0:
				client2(i); 

				if(!sigusr1ok) { // on ne se termine que si on a reçus la commande !
					pause();
				} 
				exit(0);
		}
	}
}

void launchOuvriers() {
	int i;
	for(i = 0 ; i < 4 ; ++i) {
		switch(fork()) {
			case -1:
				perror("Erreur dans la création du fils");
				exit(1);
			case 0:
				ouvrier(i);
				exit(0); 
		}
	}
}
