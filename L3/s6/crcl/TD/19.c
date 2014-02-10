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
