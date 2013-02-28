/***********************************************
*  ASR => Gpr3                                 *
************************************************
*  Login : drn0073a                            *
*                                              *
************************************************
*  Groupe: B                                   *
*                                              *
************************************************
*  Nom-prénom : de Roquemaurel Antoine         *
*  Nom-prénom : Soum Mathieu                   *
*                                              *
************************************************
*  TP n°: 4                                    *
************************************************
*  Nom du fichier : thread1.c                  *
************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

typedef void* (* Ptr)(void *);

void* traitementThread1(void* );
void* traitementThread2(void* );

int main(int argc, char *argv[]) {
	int erreur;
	int nombre = 42;
	char chaine[100] = "Je suis un thread";

	void* rapport;

	pthread_t idThread1;
	pthread_t idThread2;
	erreur = pthread_create(&idThread1, NULL, traitementThread1, (void *) &nombre);
	if (erreur) {
		perror("echec pthread_create -- thread 1");
		exit(1);
	}

	erreur = pthread_create(&idThread2, NULL, traitementThread2, (void *) chaine);
	if (erreur) {
		perror("\techec pthread_create -- thread 2");
		exit(2);
	}


	erreur = pthread_join(idThread1, &rapport);
	if (erreur) {
		perror("echec pthread_join");
		exit(3);
	}
	printf("fin du thread 1\nTID %u\nValeur de retour : <%d>\n\n",
			(int) idThread1,
			*(int*)rapport);

	erreur = pthread_join(idThread2, &rapport);
	if (erreur) {
		perror("\techec pthread_join");
		exit(3);
	}
	printf("\tfin du thread 2\n\tTID %u\n\tValeur de retour : <%s>\n\n",
			(int) idThread2,
			(char*)rapport);

	return EXIT_SUCCESS;
}

void* traitementThread1(void* p_nombre) {
	printf("Hello je suis le thread 1 et mon TID est %u! Mon param est <%d>\n\n",
			(int) pthread_self(),
			*( (int*) p_nombre) );
	*(int* )p_nombre *= 2;

	pthread_exit((void*) p_nombre);
}

void* traitementThread2(void* p_chaine) {
	printf("\tHello je suis le thread 2 et mon TID est %u! Mon param est <%s>\n\n",
			(int) pthread_self(),
			(char*) p_chaine );

	static char r_msg[100] = "Message du Thread 2 : ";
	strcat(r_msg, p_chaine);

	pthread_exit((void*) r_msg);
}

/***********************************************
*  ASR => Gpr3                                 *
************************************************
*  Login : drn0073a                            *
*                                              *
************************************************
*  Groupe: B                                   *
*                                              *
************************************************
*  Nom-prénom : de Roquemaurel Antoine         *
*  Nom-prénom : Soum Mathieu                   *
*                                              *
************************************************
*  TP n°: 4                                    *
************************************************
*  Nom du fichier : thread1.trace              *
************************************************/

[10:14:13]drn0073a@r-info-opal-l03:~/Gpr3/TP4$ ./thread1 
	Hello je suis le thread 2 et mon TID est 3077884816! Mon param est <Je suis un thread>

Hello je suis le thread 1 et mon TID est 3086277520! Mon param est <42>

fin du thread 1
TID 3086277520
Valeur de retour : <84>

	fin du thread 2
	TID 3077884816
	Valeur de retour : <Message du Thread 2 : Je suis un thread>

[10:14:24]drn0073a@r-info-opal-l03:~/Gpr3/TP4$ 