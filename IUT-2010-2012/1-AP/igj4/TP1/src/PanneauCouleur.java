import java.awt.* ;
import java.awt.event.* ;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;

/**
 * Cette classe permet de construire un <b>panneau</b> compose de trois
 * etiquettes et de trois champs de texte
 *
 * @author Christine JULIEN
 * @version  1.1.6
 * @see java.awt.Label
 * @see java.awt.Panel
 * @see java.awt.Canvas
 * @see java.awt.GridLayout
 * @see java.awt.TextField
 * @see java.awt.event.FocusAdapter
 * @see java.awt.event.FocusEvent
 */

@SuppressWarnings("serial")
public class PanneauCouleur extends JPanel {
	/**
	 * trois champs de texte associes au panneau
	 */
	private JTextField t1, t2, t3 ;

	/**
	 * canevas contenant une couleur correspondant e la combinaison
	 * des nuances RVB du panneau de contrele
	 */
	private Canvas couleurRVB ;

	/**
	 * construit un PanneauCouleur 
	 */
	public PanneauCouleur () {
		// selectionner le gestionnaire de mise en page du panneau courant :
		// grille d'1 ligne et de 2 colonnes
		this.setLayout (new GridLayout (1, 2)) ;
		// creer un canevas de couleur de fond noire 
		this.couleurRVB = new Canvas () ;
		this.couleurRVB.setBackground (Color.black) ;
		// associer le canevas au panneau courant
		// courant 
		this.add (this.couleurRVB) ;
		// creer un panneau de contrele de couleur puis selectionner 
		// son gestionnaire de mise en page : grille de 3 lignes et 3 colonnes
		JPanel panneauControle = new JPanel () ;
		panneauControle.setLayout (new GridLayout (3,2,10,10)) ;
		// creer et ajouter dans le panneau de contrele de couleur
		// l'etiquette de libelle "rouge" aligne e droite et un champ de texte
		// initialise e "0"
		panneauControle.add (new Label ("rouge", Label.RIGHT)) ;
		this.t1 = new JTextField ("0") ;
		panneauControle.add (this.t1) ;
		// creer et ajouter dans le panneau de contrele de couleur
		// l'etiquette de libelle "vert" aligne e droite et un champ de texte
		// initialise e "0"
		panneauControle.add (new Label ("vert", Label.RIGHT)) ;
		this.t2 = new JTextField ("0") ;
		panneauControle.add (this.t2) ;
		// creer et ajouter dans le panneau de controle de couleur
		// l'etiquette de libelle "bleu" aligne a droite et un champ de texte
		// initialise a "0"
		panneauControle.add (new Label ("bleu", Label.RIGHT)) ;
		this.t3 = new JTextField ("0") ;
		panneauControle.add (this.t3) ;
		// associer le panneau de controle de couleur au PanneauCouleur
		this.add (panneauControle) ;
		// associer un gestionnaire de focus e chaque
		// champ de texte pour etre e l'ecoute d'un changement de contenu
		GestionnaireCouleur listener = new GestionnaireCouleur();
		this.t1.addCaretListener(listener);
		this.t2.addCaretListener(listener);
		this.t3.addCaretListener(listener);
	}

	private class GestionnaireCouleur implements CaretListener {

		@Override
		public void caretUpdate(CaretEvent e) {
			Color c;
			// convertir le contenu du premier champ de texte
			// en un entier pour obtenir la nuance rouge
			int v1, v2, v3;

			try {
				v1 = Integer.parseInt (PanneauCouleur.this.t1.getText()) ;
			}
			catch (java.lang.NumberFormatException e1) {
				v1 = 0;
			}
			// convertir le contenu du deuxieme champ de texte
			// en un entier pour obtenir la nuance verte
			try {
				v2 = Integer.parseInt (PanneauCouleur.this.t2.getText()) ;
			}
			catch (java.lang.NumberFormatException e2) {
				v2 = 0;
			}
			// convertir le contenu du troisieme champ de texte
			// en un entier pour obtenir la nuance bleue
			try {
				v3 = Integer.parseInt (PanneauCouleur.this.t3.getText()) ;
			}
			catch (java.lang.NumberFormatException e3) {
				v3 = 0;
			}
			// creer une couleur a partir des 3 nuances obtenues
			c = new Color (v1, v2, v3) ;
			// changer la couleur de fond du canevas couleurRVB
			// a partir de la nouvelle couleur obtenue
			PanneauCouleur.this.couleurRVB.setBackground (c) ;
		}

	}

	/** 
	 * Classe interne qui est e l'ecoute des changements de focus
	 * sur les champs de texte t1, t2 et t3
	 */
	@SuppressWarnings("unused")
	private class GestionnairePanneau extends FocusAdapter {
		/**
		 * si on perd le focus sur un champ de texte alors 
		 * recalculer la nouvelle valeur RVB de la couleur
		 * en fonction des trois nuances RVB et afficher cette
		 * couleur dans le canevas couleurRVB
		 * @param e evenement de focus
		 */
		public void focusLost (FocusEvent e) {
			Color c;
			// convertir le contenu du premier champ de texte
			// en un entier pour obtenir la nuance rouge
			int v1 = Integer.parseInt (PanneauCouleur.this.t1.getText()) ;
			// convertir le contenu du deuxieme champ de texte
			// en un entier pour obtenir la nuance verte
			int v2 = Integer.parseInt (PanneauCouleur.this.t2.getText()) ;
			// convertir le contenu du troisieme champ de texte
			// en un entier pour obtenir la nuance bleue
			int v3 = Integer.parseInt (PanneauCouleur.this.t3.getText()) ;
			// creer une couleur e partir des 3 nuances obtenues
			c = new Color (v1, v2, v3) ;
			// changer la couleur de fond du canevas couleurRVB
			// e partir de la nouvelle couleur obtenue
			PanneauCouleur.this.couleurRVB.setBackground (c) ;
		}
	}
}

