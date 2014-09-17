package achats;

import java.util.HashMap;
import java.util.Map;

public class Panier {
	private Map<Produit, Integer> _list;
	private double _totalPrice;
	
	public Panier() {
		_list = new HashMap<Produit, Integer>();
		_totalPrice = 0;
	}

	public int getNbProducts() {
		return _list.size();
	}

	public double getTotalPrice() {
		return _totalPrice;
	}

	public void add(Produit produit) {
		_list.put(produit, 1);
		_totalPrice += produit.getPrice();
	}
}
