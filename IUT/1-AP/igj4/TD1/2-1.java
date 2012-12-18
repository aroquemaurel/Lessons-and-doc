/**
 * Controleur du bouton de la grille
 * Inclut dans la classe VueMorpion	
 */
private class ControleurBtGrille implements ActionListener {
	@Override 
	public void actionPerformed (ActionEvent e) {
		Button bouton = (Button) e.getSource();
		Couple coordonnees VueMorpion.coordeesBGrille(bouton);
		int i = coordonnees.getPremier();
		int j = coordonnees.getSecond();
		char numeroJoueur = VueMorpion.numeroJoueur();

		if(VueModele.modele.getValeurCase(i, j) == TypeCase.VIDE) {
			if (numeroJoueur == '1'){
				b.setLabel("X");
				VueMorpion.modele.setValeurCase(i, j, TypeCase.Joueur1);
				VueMorpion.etiq2.setText("Joueur 2");
				VueMorpion.etiq1.setText("Le joueur "+numeroJoueur+" à gagné");
			}
		}
	}
}
