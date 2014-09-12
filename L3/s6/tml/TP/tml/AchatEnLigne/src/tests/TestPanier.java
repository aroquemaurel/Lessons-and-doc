package tests;

import static org.junit.Assert.assertEquals;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import achats.Panier;
import achats.Produit;

public class TestPanier {
	private Panier _panier;
	@Before
	public void setUp() throws Exception {
		_panier = new Panier();
	}
	
	@After
	public void tearDown() throws Exception {
		_panier = null;
	}
	
	@Test
	public void testInitNbProduits() {
		assertEquals(0, _panier.getNbProducts());
	}
	
	@Test
	public void testInitTotalPrice() {
		assertEquals(0.0, _panier.getTotalPrice(), 0);
	}
	
	@Test
	public void testAddProduct1() {
		_panier.add(new Produit("Nom", 1));
		assertEquals(1, _panier.getNbProducts());
	}

	@Test
	public void testAddProduct2() {
		_panier.add(new Produit("Nom", 1));
		assertEquals(1, _panier.getTotalPrice(), 0);
	}
	
	@Test
	public void testAddProduct3() {
		_panier.add(new Produit("Nom1", 1));
		_panier.add(new Produit("Nom2", 2));
		_panier.add(new Produit("Nom3", 3));
		_panier.add(new Produit("Nom4", 4));
		
		assertEquals(10, _panier.getTotalPrice(), 0);
	}
	
	@Test
	public void testAddProduct4() {
		_panier.add(new Produit("Nom1", 1));
		_panier.add(new Produit("Nom1", 1));
		_panier.add(new Produit("Nom3", 3));
		_panier.add(new Produit("Nom3", 3));
		
		assertEquals(8, _panier.getTotalPrice(), 0);
	}
	
	@Test
	public void testAddProduct5() {
		_panier.add(new Produit("Nom1", 1));
		_panier.add(new Produit("Nom1", 1));
		_panier.add(new Produit("Nom3", 3));
		_panier.add(new Produit("Nom3", 3));
		
		assertEquals(4, _panier.getNbProducts());
	}
}
