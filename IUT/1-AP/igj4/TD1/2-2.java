/**
 * Controleur du bouton effacer 
 * Inclut dans la classe VueMorpion	
 */
private class ControleurBtEffacer implements ActionListener {
	@Override
	public void actionPerformed(actionEvenet e) {
		VueMorpion.effacerBtGrille();
		VueMorpion.modele.initialiser();	
		VueMorpion.etq2.setText("Joueur 1");
	}
}

