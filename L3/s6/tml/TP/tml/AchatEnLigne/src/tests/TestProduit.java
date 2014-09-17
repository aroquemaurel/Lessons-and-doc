package tests;

import static org.junit.Assert.assertEquals;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import achats.Produit;

public class TestProduit {
	private Produit _produit;
	
	@Before
	public void setUp() throws Exception {
		_produit = new Produit("nom", 13.37);
	}
	
	@After
	public void tearDown() throws Exception {
		_produit = null;
	}
	
	@Test
	public void testInitName() {
		assertEquals("nom", _produit.getName());
	}
	
	@Test
	public void testInitPrice() {
		assertEquals(13.37, _produit.getPrice(), 0);
	}
	
	@Test
	public void testSetPrice() {
		_produit.setPrice(42.0);
		assertEquals(42.0, _produit.getPrice(), 0);
	}
	
	@Test
	public void testSetName() {
		_produit.setName("Nouveau nom");
		assertEquals("Nouveau nom", _produit.getName());
	}

}
