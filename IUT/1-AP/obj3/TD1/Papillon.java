class Papillon extends Animal{
	private Stade evolution;

	public Papillon(){
		this.evolution = new Chenille();
	}
	public void evoluer(){
		this.setEvolution(this.evolution.evoluer());
	}
	private void setEvolution(Stade p_stade){
		this.evolution = p_stade;
	}
	public Stade getEvolution(){
		return (this.evolution);
	}
}
