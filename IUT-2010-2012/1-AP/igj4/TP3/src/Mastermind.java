import java.util.Random;
import java.util.Scanner;


public class Mastermind {
	private int[] _combinaison;
	private int _taille;
	private int _nbcouleurs;
	
	public Mastermind(int nbCouleurs, int tailleCombinaison) {
		_taille = tailleCombinaison;
		_nbcouleurs = nbCouleurs;
		_combinaison = new int[_taille];
	}
	
	public int getTaille() {
		return _taille;
	}

	public int getNbCouleurs() {
		return _nbcouleurs;
	}
	
	public void genererCombinaison() {
		Random r = new Random();
		for(int i=0; i<_taille; ++i) {
			_combinaison[i] = r.nextInt(_nbcouleurs);
		}
	}
	
	public int[] getCombinaison() {
		return _combinaison;
	}
	
	public int nbChiffresBienPlaces(int[] tabChiffres) throws Exception {
		if(tabChiffres.length != _taille) {
			throw new Exception("Mauvaise taille de la combinaison");
		}
		
		int retour = 0;
		for(int i=0; i<_taille; ++i) {
			if(tabChiffres[i] == _combinaison[i]) {
				++retour;
			}
		}
		return retour;
	}
	
	public int nbChiffresMalPlaces(int[] tabChiffres) throws Exception {
		if(tabChiffres.length != _taille) {
			throw new Exception("Mauvaise taille de la combinaison");
		}
		
		int retour=0;
		int[] nbCombi = new int[_nbcouleurs+1];
		int[] nbParam = new int[_nbcouleurs+1];
		
		for(int i=0; i<_taille; ++i) {
			if(tabChiffres[i] != _combinaison[i]) {
				++nbCombi[_combinaison[i]];
				++nbParam[tabChiffres[i]];
			}
		}
		
		for(int i=0; i<_nbcouleurs; ++i) {
			retour += Math.min(nbCombi[i], nbParam[i]);
		}
		return retour;
	}
	
	public static void main(String[] args) {
		try {
		Mastermind m = new Mastermind(6, 4);
		m.genererCombinaison();
		Scanner sc = new Scanner(System.in);
		int nbEssais=10;
		boolean gagné = false;
		
		while(nbEssais > 0 && !gagné) {
			System.out.println(nbEssais + " essais restants");
			
			int[] input = new int[m.getTaille()];
			
			for(int i=0; i<m.getTaille(); ++i) {
				input[i] = sc.nextInt();
			}

			System.out.println("Bien placés = " + m.nbChiffresBienPlaces(input));
			System.out.println(" Mal placés = " + m.nbChiffresMalPlaces(input));
			
			if(m.nbChiffresBienPlaces(input) == m.getTaille()) {
				gagné = true;
			}
			--nbEssais;
		}
		
		if(gagné) {
			System.out.print("Bravo !");
		}
		else {
			System.out.print("Try again !");
		}
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
}
