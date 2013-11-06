#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <unistd.h>
#include <signal.h>

typedef void (*PtrFct)(int);

void fonctionSignal(int);

jmp_buf ptRep;

int main(int argc, char** argv)
{
	int ret, nbChances = 2;
	char* reponse;
	PtrFct fctExec;

	fctExec = signal(SIGALRM, fonctionSignal);

	if (fctExec == SIG_ERR) {
		perror("Et là... c'est le drame !");
		exit(1);
	}

	ret = setjmp(ptRep);

	if (!(nbChances)) {
		printf("You fail! Mais à bientôt pour de nouvelles aventures !\n");
		return 1337;
	}
	printf("Quelle est la réponse à la question sur la vie l'univers et le reste ? (Tu as 10 sec et encore %d chances...)\n", nbChances - 1);
	alarm(10);
	--nbChances;

	scanf("%s", &reponse);
	alarm(0);
	printf("Merci et à bientôt pour de nouvelles aventures !\n");

	return 1337;
}

void fonctionSignal(int sig) {
	sigrelse(sig);
	longjmp(ptRep, 42);
}
