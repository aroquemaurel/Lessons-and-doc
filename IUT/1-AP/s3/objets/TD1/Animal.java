class Animal {
	private String nom;
	private Int age;

	public Animal(String p_nom, Int p_age){
		this.nom = p_nom;
		this.age = p_age;
	}

	public void dormir(){
	}

	public void manger(){
	}

	public String getNom(){
		return this.nom;
	}
	
	public Int getAge(){
		return this.age;
	}

	public void setAge(Int a){
		this.age = a;
	}

}
