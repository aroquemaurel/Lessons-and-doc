/**
 * Classe permettant d'afficher le jeu du morpion
 */
public class VueMorpion extends Panel {
	private EtatControleur {JOUEUR1, JOUEUR2} etat;

	private ModeleMorpion modele;

	public VueMorpion(){
		Controleur controleur;
		btEffacer.addActionListener(controleur);
	}

	private class Controleur implements ActionListener {
		private EtatControleur etat;

		public Controleur(){
			this.etat = EtatControleur.JOUEUR1;
		}

		public void actionPerformed(ActionEvenet e){
			Button bouton = (Button) e.getSource();

			if(bouton.getLabel().equals("effacer")) {
				VueMorpion.etiq2.setText("Joueur 1");
				VueMorpion.effacerBtGrille();
				VueMorpion.modele.initialiser();
				VueMorpion.etiq1.setText("");
				this.etat = EtatControleur.JOUEUR1;
			} else {
				Couple couple = VueMorpion.coordBtGrille(bouton);
				int i = couple.getPremier();
				int j = couple.getSecond();

				if(VueMorpion.modele.getValeurCase(i, j) == TypeCase.VIDE) {
					switch(this.etat){
						case JOUEUR1 :
							bouton.setLabel("X");
							ModeleVue.modele.setValeurCase(i, j, TypeCase.JOUEUR1);
							if(ModeleVue.modele.caseAlignees(i, j) {
								ModeleVue.etiq1.setText("Le joueur 1 à gagné");
							} else {
								ModeleVue.etiq1.setText("Joueur 2");
							}
							this.etat = EtatControleur.JOUEUR2;
							break;
						case JOUEUR2 :
							bouton.setLabel("O");
							ModeleVue.modele.setValeurCase(i, j, TypeCase.JOUEUR2);
							if(ModeleVue.modele.caseAlignees(i, j) {
								ModeleVue.etiq1.setText("Le joueur 2 à gagné");
							} else {
								ModeleVue.etiq1.setText("Joueur 1");
							}
							this.etat = EtatControleur.JOUEUR1;
							break;
					}
				}
			}
		}
	}
}
