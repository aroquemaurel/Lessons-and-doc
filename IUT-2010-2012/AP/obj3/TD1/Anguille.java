class Anguille extends Ovipare, AnimalMarin, AnimalEauDouce {
	public Anguille(String p_nom, Int p_age){
		super(p_nom, p_age);
	}

	public void pondre(){
		this.allerDansMerDesSargasses();
		super.pondre();
	}

	private void allerDansMerDesSargasses() {
	}
}

