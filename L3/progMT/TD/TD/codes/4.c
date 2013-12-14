#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv) {
	int fdPipe[2];
	char chaine[256];
	int i;
	int buffSize = 0;
	if(pipe(fdPipe) == -1) {
		perror("erreur");exit(EXIT_FAILURE);
	}
	switch(fork()) {
		case -1:
			perror("erreur");exit(EXIT_FAILURE);
		case 0:
			close(fdPipe[1]); // close write
			while(read(fdPipe[0], chaine+buffSize, 8) > 0) {
				buffSize += 64;
			}
			close(fdPipe[0]);
			printf("[fils]%s ", chaine);
			exit(0);
		default:
			// scanf
			close(fdPipe[0]); // close read

			scanf("%s", chaine);
			while(buffSize < strlen(chaine)) {
				write(fdPipe[1], chaine+buffSize, 64);
				buffSize += 64;
			}
			close(fdPipe[1]);

	}
	return EXIT_SUCCESS;
}
