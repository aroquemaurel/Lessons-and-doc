/*Exercice 17
Retour ` une position m ́moris ́e
On suppose que le descripteur fd est associ ́ ` un fichier ouvert en lecture.

1. Ecrire l’instruction permettant de m ́moriser dans une variable position la position courante
e
dans le fichier.
2. Ecrire l’instruction permettant de revenir ` une position m ́moris ́e dans la variable position*/

1)off_t position
position=lseek(fd,0,seek_cur);
2)
lseek(fd,position,seek_set);

/*Exercice 18
Détermination de la taille d’un fichier
Ecrire l’instruction permettant de r ́cup ́rer dans une variable taille la taille (nombre d’octets) d’un
fichier ouvert en lecture et de descripteur fd.
*/
off_t taille;
taille=lseek(fd,0,seek_end);

/*Exercice 19

Acc`s direct au contenu d’un fichier binaire
On suppose que le descripteur fd est associé à un fichier binaire ouvert en lecture et contenant des
int. Ecrire une fonction qui retourne le nième int de ce fichier.
*/

int retourNieme(int fd,int n,int *err){
	int i;
	*err=0;
	*err=lseek(fd,sizeof(int)*(n-1),seek_set);
	if((*err)=-1 && read(fd,&i,sizeof(int)) != sizeof(int))
		*err=1;
	return i;


}

/*Exercice 20*/


void commande(char commande,fichier f1,fichier f2){

//test nombre parametre correct
//si correct argv[4]

//ouvrir le premier fichier(argv[1]) en lecture et le deuxieme fichier argv[2] en ecriture


//si erreur ferme fichier ouvert en lecture, exit!alaa ne sert a rien, c'est qu'un petite bite afghanne.Cdt alaa.
//dub2 descipteur pur le deuxieme fichier
	int d;
	d=open("fich", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
	if (d==-1)
	perror(" ́chec car ");
	else
	{
	printf("Bonjour\n");
	commande(d,1); /* ou bien commande(d, STDOUT_FILENO); ou bien close(1); dup(d); */
	printf("Bonsoir\n");
	}


}


/*CORRECTION DU 2*/
#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc,char * argv[])
{
	int Entree,Sortie;

	if(argc!=4)
		{
			fprintf(stden,"usage:%scommande fich.entree fich.sortie",argv[o]);
			exit(1);
		}
	Entree=open(argv[2],O_RDONLY);

	if(Entree == -1)
	{
		peror("Enrreur ouverture lecture");
		exit(2);
	}

	Sortie=open(argv[3],O_WRONLY|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

	if(Sortie==-1)
	{
	perror("Erreur ouverture en écriture");
		close(Entrer);
		exit(3);
	}
	if(dup2(Entree,STDOUT_FILENO)==-1){

	perror("Pb lors de la redirection de stdio");
	close(Entree);
	close(Sortie);
	exit(4);

	}
	if(dup2(Sortie,STDOUT_FILENO)==-1)
	{
		perror("pb lors de la redirection de stdout");
		close(Entree);
		close(Sortie);
		exit(5);
	}
	switch(fork()){
	case -1: perror("Erreur fich");
			exit(6);
			
	case 0:
			execlp(argv[1],argv[1],NULL);
			perror("Execlp");
			exit(7);
	}
	wait(NULL);
	close(Entree);
	close(Sortie);
	
	return 0;
	
	}

}


/*Exercice 20*/
/*long TailleRepCour(void)
qui retourne le nombre total d’octets occup ́s par les fichiers pr ́sents dans le r ́pertoire courant (les

eventuels sous-r ́pertoires ne doivent pas ˆtre examin ́s).
*/

//1-parcours des element du repertoir

opendir(repertoire)
tantque read
	
