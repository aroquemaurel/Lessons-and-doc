void affNomFich(char* nomRep) {
	DIR* rep;
	struct dirent* elt;
	struct stat infos;
	char designation[512];

	rep = opendir(nomRep);
	
	if(rep == NULL) {
		perror(nomRep);
		return;
	}
	strcpy(designation, nomRep);
	strcat(designation, "/");
	while((elt = readdir(rep)) != NULL) {
		if(strcmp(elt->d_name, ".") && strcmp(elt->d_name, "..")) {
			strcat(designation, elt->d_name);
			if(stat(designation, &infos) == 0) {
				if(S_ISDIR(infos.st_mode)) {
					affNomFich(designation);
				} else {
					printf("%s\n", designation);
				}
				strcpy(designation, nomRep);
				strcat(designation, "/");
			} else {
				perror(designation);
			}
		}
	}
}
