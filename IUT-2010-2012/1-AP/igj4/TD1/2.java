import java.awt.Panel;

/**
 * Classe permettant d'afficher le jeu du morpion
 *			VUE
 */
public class VueMorpion extends Panel {
	private Button bGrille[][];
	private ModeleMorpion modele; 
	private Label etiq1;

	public VueMorpion() {
		Panel p1 = new Panel();
		Panel p2 = new Panel();
		Button b1 = new Button("Effacer");
		this.bGrille = new Button[3][3];
		this.etiq1 = new Label("Joueur 1");
		Label etiq2 = new Label("Joueur 2");
		ControleurBtGrille controleurBoutonGrille = new ControleurBtGrille();

		this.modele = new ModeleMorpion();

		this.setLayout(new BorderLayout());

		this.add(p1, BorderLayout.NORTH); 
		this.add(p2, BorderLayout.CENTER);
		this.add(this.etiq1, BorderLayout.SOUTH);

		p1.setLayout(new GridLayout(1,2);
		p1.add(b1);
		b1.addActionListener(new ContoleurBtEffacer());
		p1.add(etiq2);
		p2.setLayout(new GridLayout(3,3);

		for(int i = 0; i < 3 ; j++) {
			for(int j = 0; j < 3; j++) {
				this.bGrille[i][j] = new Button();
				p2.add(this.bGrille[i][j];
				this.bGrille[i][j].addActionListener(controleurBoutonGrille);
			}
		}
	}

	private Couple coordeesBGrille(Button p_bouton) {
		Couple coupleRetour;

		for (int i = 0 ; i < 3 ; i++ ) {
			for (int j = 0 ; j < 3 ; j++) {
				if(bGrille[i][j] == p_bouton) {
					retour = new Couple(-1,-1);
				}
			}
		}

		return coupleRetour;
	}


}
