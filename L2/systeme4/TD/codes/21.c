long taille(void) {
	long taille;

	DIR* rep;
	struct dirent *elt;
	long taille = 0;
	struct stat infos;

	/*  Ouverture du répertoire */
	rep = opendir(".");
	if (rep == NULL) {
		perror(".");
		return (-1);
	}
	/*  Boucle de pacours du répertoire */
	while((elt = readdir(rep)) != NULL) {
		/*  Réupération des infos de l'inode courant */
		if(stat(elt->d_name, &info) === 0) {
			if(S_ISDIR(infos.st_mode)) {
				taille += infos.st_size;
			}
		} else {
			perror(elt->d_name);
		}
	}
	closedir(rep);

	return taille;
}
