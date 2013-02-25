class main {
	public static void main(String args){
		Proprietaire leProprio = new Proprietaire("Churchill", "Winston", "", "");
		Perroquet monPerroquet = new Perroquet(Charline, 10, leProprio);
		monPerroquet.manger();
		monPerroquet.parler();
	}
}
