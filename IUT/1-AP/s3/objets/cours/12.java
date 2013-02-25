abstract class StructureSequentielle<T>{
	//T est le type des éléments de la structure séquentielle
	
	// se positionner sur le premier élément de la structure séquentielle
	abstract public void allerAuPremier();

	// se positionner sur l'élément suivant
	abstract public void allerAuSuivant();

	// la fin de la structure séquentielle est-elle atteinte? 
	abstract public boolean epuise();

	// test si l'élément courant de la structure séquentielle 
	// coincide avec x  
	abstract public boolean trouve();;


	//recherche séquentielle d'un élément x 
	//dans la structure séquentielle
	public boolean existeElement(T x){
		this.allerAuPremier();
		while(!this.epuise() && !this.trouve(x)){
			this.allerAuSuivant();
			return (!this.epuise());
		}
	}
}


class TableauSequentiel <T> extends structureSequentielle <T> {
	private Tableau <T> elements;
	private int indice;

	//constructeur
	public TableauSequentiel<T>(int n){
		this.elements = new Tableau<T>(n);
		this.indice = 1;
	}

	//Aller au premier élément du tableau
	public void allerAuPremier() {
		this.indice = 1;
	}
	
	//Aller au suivant du tableau séquentiel
	public void allerAuSuivant () {
		this.indice = this.indice + 1;
	}

	//fin du tableau séquentiel ? 
	public boolean epuise() {
		return (this.indice > this.elements.longueur();
	}

	//L'élément courant du tableau séquentiel est-il égal à x
	public boolean trouve(T x){
		return (this.elements.getIème(this.indice) == x);
	}
}

// Même écriture que tableSéquentielle<T> pour le TAD ListeSequentielle<T>, FichierSequentiel<T>, ...
