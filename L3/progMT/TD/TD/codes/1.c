#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
	int i;
	int status;
		switch(fork()) {
			case -1:
				perror("Erreur fork");
				break;
			case 0:
				execlp("date", "date", NULL);
			default:
				wait(&status);
				execlp("ls", "ls", "-al", NULL);
	}
	return 0;
}
