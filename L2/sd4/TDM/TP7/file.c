#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "file.h"

File creerFile() {
	File f;
	f = (File) malloc(sizeof(FileInterne));
	assert(f != NULL);
	f->nb = 0;
	f->tete = 0;

	return f;
}

File enfile(File pFile, Element pElement) {
	assert(!fileEstPleine(pFile));
	pFile->tab[(pFile->nb+pFile->tete)%N] = pElement;
	++pFile->nb;
	return pFile;
}

int fileEstPleine(File pFile) {
	return (pFile->nb == N);
}

int fileEstVide(File pFile) {
	return (pFile->nb == 0);
}

File defiler(File pFile) {
	if(!fileEstVide(pFile)) {
		pFile->nb--;
		pFile->tete = (pFile->tete+1)%N;
	}

	return pFile;
}

int appartient(File f, Element x) {
	int i;
	for( i=0 ; i < f->nb ; ++i ) {
		if(x == f->tab[(i+f->tete)%N])
			return 1;
	}

	return 0;
	
}

Element premier(File pFile) {
	return (pFile->tab[pFile->tete]);
}

Element dernier(File pFile) {
	return (pFile->tab[(pFile->tete+pFile->nb-1)%N]);

}
