class HyperMarche {
	private Tableau <Article> stock;

	public void editerStock (){
		for (int i = 0; i < stock.longuer(); ++i) {
			out.println(stock.getIeme(i).getDesignation());
		}
	}
}


