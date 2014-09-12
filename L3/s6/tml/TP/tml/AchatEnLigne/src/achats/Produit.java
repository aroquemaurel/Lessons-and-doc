package achats;

public class Produit {
	private String _name;
	private double _price;
	
	public Produit(String string, double d) {
		_name = string;
		_price = d;
	}

	public String getName() {
		return _name;
	}

	public double getPrice() {
		return _price;
	}

	public void setPrice(double d) {
		_price = d;
	}

	public void setName(String string) {
		_name = string;
	}
}
