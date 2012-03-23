class Perroquet extends Oiseaux {
	private String nom;
	private Int age;
	
	public Perroquet(String p_nom){
		this.nom = p_nom;
		this.age = 0;
	}

	public void dormir() {
	}

	public void manger(){

	}

	public void parler () {
	}

	public String getNom(){
		return this.nom;
	}

	public Int getAge(){
		return this.age
	}

	public void setAge(Int p_nouvelAge){
		if(p_nouvelAge > 0){
			this.age = p_nouvelAge;
		}
	}
}

