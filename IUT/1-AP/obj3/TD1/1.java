class Perroquet extends Oiseaux {
	private String nom;
	private int age;
	
	public Perroquet(String p_nom, int p_age){
		this.nom = p_nom;
		this.age = p_age;
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

	public int getAge(){
		return this.age
	}

	public void setAge(int p_nouvelAge){
		if(p_nouvelAge > 0){
			this.age = p_nouvelAge;
		}
	}
}

