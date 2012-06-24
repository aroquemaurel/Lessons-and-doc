import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JPanel;

enum Etats {
	ATTENTE_CLIC_DEPART,
	ATTENTE_CLIC_ARRIVEE
}

@SuppressWarnings("serial")
public class Panneau extends JPanel {
	private static final int TAILLE_GRILLE = 2;
	private static final ImageIcon PION = new ImageIcon("image.jpg");
	private static final ImageIcon VIDE = new ImageIcon();

	private int _xPion;
	private int _yPion;

	private JButton[][] _boutons;

	public Panneau() {
		GestionnaireBoutons listener = new GestionnaireBoutons();
		_xPion = _yPion = 0;

		setLayout(new GridLayout(TAILLE_GRILLE, TAILLE_GRILLE));

		_boutons = new JButton[TAILLE_GRILLE][TAILLE_GRILLE];
		for(int x=0; x < TAILLE_GRILLE; ++x) {
			for(int y=0; y < TAILLE_GRILLE; ++y) {
				_boutons[x][y] = new JButton();
				_boutons[x][y].setPreferredSize(new Dimension(64, 64));
				_boutons[x][y].addActionListener(listener);
				add(_boutons[x][y]);
			}
		}
		_boutons[_xPion][_yPion].setIcon(PION);
	}

	public boolean estCaseVide(int x, int y) {
		return !(x == _xPion && y == _yPion);
	}

	public void deplacerJeton(int x, int y) {
		// Supprimer l'ancien jeton
		_boutons[_xPion][_yPion].setIcon(VIDE);
		// changer les coordonnees
		_xPion = x;
		_yPion = y;
		// Placer le nouveau bouton
		_boutons[_xPion][_yPion].setIcon(PION);
	}
	
	private int getX(Object obj) {
		int retour = -1;
		for(int x=0; x < TAILLE_GRILLE; ++x) {
			for(int y=0; y < TAILLE_GRILLE; ++y) {
				if(obj == _boutons[x][y]) {
					retour = x;
				}
			}
		}
		return retour;
	}
	
	private int getY(Object obj) {
		int retour = -1;
		for(int x=0; x < TAILLE_GRILLE; ++x) {
			for(int y=0; y < TAILLE_GRILLE; ++y) {
				if(obj == _boutons[x][y]) {
					retour = y;
				}
			}
		}
		return retour;
	}

	class GestionnaireBoutons implements ActionListener {
		private Etats _etat;

		public GestionnaireBoutons() {
			_etat = Etats.ATTENTE_CLIC_DEPART;
		}

		@Override
		public void actionPerformed(ActionEvent event) {
			Object source = event.getSource();
			
			switch(_etat) {
				case ATTENTE_CLIC_DEPART:
					if(!estCaseVide(getX(source), getY(source))) {
						_etat = Etats.ATTENTE_CLIC_ARRIVEE;
					}
					break;
				case ATTENTE_CLIC_ARRIVEE:
					deplacerJeton(getX(source), getY(source));
					_etat = Etats.ATTENTE_CLIC_DEPART;
					break;
			}
			
		}
	}
}
