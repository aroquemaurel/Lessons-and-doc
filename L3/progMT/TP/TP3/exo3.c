#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_CLIENTS 5
int tubeOuvriers[4][2]; // les tubes des ouvriers

void client1(const int num);
void ouvrier(const int num);
int main(int argc, char** argv) {
	int i;
	for(i = 0 ; i < 4 ; ++i) {
		switch(fork()) {
			case -1:
				perror("Erreur dans la création du fils");
				exit(1);
			case 0:
				ouvrier(i);// On attend le boulot
				exit(0); // Si tous les clients ont finis == tube et tant qu'il y a des ecrivains ?
		}
	}
	for(i = 0 ; i < NB_CLIENTS ; ++i) {
		switch(fork()) {
			case -1:
				perror("Erreur dans la création du fils");
				exit(1);
			case 0:
				client1(i);
				exit(0);
		}
	}

	return EXIT_SUCCESS;
}

// On suppose que le travail des ouvriers est d'incrémenter une variable.
// et de la faire passer au suivant.
void ouvrier(const int num) {
	int commande;

	close(tubeOuvriers[num][1]);
	while(read(tubeOuvriers[num][0], commande, sizeof(int)) != 0);
	close(tubeOuvriers[num][0]);

	// Lecteur dans tube ouvrier[1]
	switch(num) {
		case 0:
			printf("On lance la commande %d", commande);		
			break;
		case 1:
			// boulot ouvrier 1
			printf("OUVRIER 1%d",commande);
			++commande;
			break;
		case 2:
			printf("OURIER2 %d",commande);
			// boulot ouvrier 2
			++commande;
			break;
		case 3:
			printf("OUVRIER 3%d",commande);
			// boulot ouvrier 3
			++commande;
			break;
	}

	close(tubeOuvriers[num][0]);
	if(num != 3) {
		write(tubeOuvriers[num][1], commande, sizeof(int));
	} else {
		printf("On a finis la commande ! ");
			// On envoie sigusr1 au client
	}
	close(tubeOuvriers[num][1]);
}

void client1(const int num) {
	close(tubeOuvriers[0][0]);

	// On écrit dans le tube à destination de l'ouvrier 0 
	write(tubeOuvriers[0][1], num, sizeof(int));
	close(tubeOuvriers[0][1]);
	sleep(); // On attend que les ouvriers nous signale la fin du travail
	// On fait ce qu'on à a faire
//	printf("Le client %d a eu sa commande", num);
}

void client2(const int num) {

}
