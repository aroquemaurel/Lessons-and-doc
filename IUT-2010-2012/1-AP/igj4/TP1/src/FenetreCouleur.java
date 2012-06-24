import java.awt.FlowLayout;
import javax.swing.JFrame;

/**
 * Cette classe permet de construire une <b>fenetre</b> composee d'un    
 * PanneauCouleur.
 * 
 *
 * @author Christine JULIEN
 * @version  1.1.6
 * @see java.awt.Frame
 * @see java.awt.Canvas
 * @see java.awt.FlowLayout
 * @see java.awt.event.WindowAdapter
 * @see java.awt.event.WindowEvent
 * @see PanneauCouleur 
 */

@SuppressWarnings("serial")
public class FenetreCouleur extends JFrame {
	/**
	 * Construit une FenetreCouleur contenant un PanneauCouleur
	 */
	public FenetreCouleur () {
		// associer un titre a la FenetreCouleur
		this.setTitle ("Conversions RVB") ;
		// selectionner le gestionnaire de mise en page de la FenetreCouleur
		this.setLayout (new FlowLayout()) ;
		// creer un PanneauCouleur et l'ajouter a la FenetreCouleur 
		this.add (new PanneauCouleur ()) ;
		// associer une taille a la FenetreCouleur
		this.setSize (250, 120) ;
		// associer un gestionnaire de fenetre a la FenetreCouleur 
		// a l'ecoute d'un evenement se produisant sur la fenetre
		setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		// afficher la Fen�treCouleur
		this.pack () ;
		this.setVisible (true) ; 
	}
}

