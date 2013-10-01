int afficher(char* fich) {
	int f;
	int nbChars;
	char buff[256];

	if(f = open(fich, O_RDONLY) == -1) {
		perror("Pas bon");
	}

	while(nbChars = (read(f, buff, 256))) {
		write(1, buff, nbChars);
	}
	close(f);
}
