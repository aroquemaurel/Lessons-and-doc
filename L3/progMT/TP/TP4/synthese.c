#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

#define NB_PILOTES 5
#define DUREE 20

int tube[2];

void progresser(int*, int*);
bool estArrive(int,int);
void pilote(int);
void controle(void);
void finDelai(int);

typedef struct {
	int num;
	int x;
	int y;
} Position;
Position position;


int main(int argc, char** argv) {
	int i;

	pipe(tube);
	
	for(i = 0 ; i < NB_PILOTES ; ++i) {
		switch(fork()) {
			case -1:
				fprintf(stderr, "Erreur dans la création du fork");
				exit(1);
				break;
			case 0:
				pilote(i);
				exit(0);
				break;
		}
	}

	// père == contrôle

	return EXIT_SUCCESS;
}

void pilote(int num) {
	close(tube[0]);
	position.num = num;
	signal(SIGALRM, finDelai);
	alarm(DUREE);
	
	while(!estArrive(position.x, position.y)) {
		progresser(&position.x, &position.y);
	}
	close(tube[1]);
}

void controle(void) {

}

void finDelai(int num) {
	signal(SIGALRM, finDelai);
	write(tube[1], &position, sizeof(position));
	alarm(DUREE);
}
