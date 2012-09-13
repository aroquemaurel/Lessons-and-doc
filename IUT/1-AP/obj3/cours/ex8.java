class HyperMarché
{
	private Tableau <Article> stock;

	public void editerStock(){
		for(int i = 0; i < stock.longueur; i++){
			out.println(stock.getIeme(i).getDesignation());
		}
	}

		// autres méthodes
}
