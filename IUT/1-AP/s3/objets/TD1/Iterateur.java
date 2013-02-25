interface Iterateur <T> {
	// Constructeur : prend en compte les éléments présents dans la collection
	Iterateur<T> (Collection <T> c);

	// Se positionne sur le premier élément de la collection
	void premier();

	//passe à l'élément suivant de la collection
	void suivant ();

	//retourne l'élément courant de la collection
	T valeur ();

	// TRUE lorsque tous les élément de la collection ont été visités
	boolean termine();
}
