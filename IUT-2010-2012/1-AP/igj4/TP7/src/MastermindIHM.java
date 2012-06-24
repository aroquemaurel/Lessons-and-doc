import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serializable;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

enum Etats {
	ATTENTE_CLIC_COULEUR,
	ATTENTE_CLIC_SAISIE
}

@SuppressWarnings("serial")
public class MastermindIHM extends JPanel implements Serializable {
	
	private Mastermind _mastermind;
	private JButton[]   _couleurs;
	private JButton[]   _saisie;
	private JButton    _valider;
	private int        _nbEssais;
	private JLabel     _lbNbEssais;
	private JPanel     _pnCenter;
	
	private GestionnaireEvenements _listener;
	
	public MastermindIHM(int nbCouleurs, int nbCases, int nbEssais) {
		_listener = new GestionnaireEvenements();
		
		_mastermind = new Mastermind(nbCouleurs, nbCases);
		_mastermind.genererCombinaison();
		
		_nbEssais = 10;
		
		setLayout(new BorderLayout());
		
		// CENTER
		_pnCenter = new JPanel();
		_pnCenter.setLayout(new BoxLayout(_pnCenter, BoxLayout.Y_AXIS));
		add(_pnCenter, BorderLayout.NORTH);
		
		// SOUTH
		JPanel pnSouth = new JPanel();
		add(pnSouth, BorderLayout.SOUTH);
		
		pnSouth.setLayout(new FlowLayout());
		JLabel lbCouleurs = new JLabel("Couleurs");
		pnSouth.add(lbCouleurs);
		_couleurs = new JButton[_mastermind.getNbCouleurs()];
		for(int i=0; i<_couleurs.length; ++i) {
			_couleurs[i] = new JButton();
			_couleurs[i].setPreferredSize(new Dimension(32, 32));
			_couleurs[i].setBackground(Couleur.fromInt(i+1));
			_couleurs[i].addActionListener(_listener);
			pnSouth.add(_couleurs[i]);
		}
		
		// NORTH
		JPanel pnNorth = new JPanel();
		add(pnNorth, BorderLayout.CENTER);
		_saisie = new JButton[_mastermind.getTaille()];
		for(int i=0; i<_saisie.length; ++i) {
			_saisie[i] = new JButton();
			_saisie[i].setPreferredSize(new Dimension(32, 32));
			_saisie[i].setBackground(Couleur.fromInt(0));
			_saisie[i].addActionListener(_listener);
			pnNorth.add(_saisie[i]);
		}
		_valider = new JButton("Valider");
		_valider.addActionListener(_listener);
		pnNorth.add(_valider);
		
		_lbNbEssais = new JLabel();
		actualiserNbEssais();
		pnNorth.add(_lbNbEssais);
	}
	
	private boolean estCouleur(Object o) {
		boolean retour = false;
		for(int i=0; i<_couleurs.length; ++i) {
			if(o == _couleurs[i]) {
				retour = true;
			}
		}
		return retour;
	}
	
	private boolean estSaisie(Object o) {
		boolean retour = false;
		for(int i=0; i<_saisie.length; ++i) {
			if(o == _saisie[i]) {
				retour = true;
			}
		}
		return retour;
	}
	
	private boolean estValidation(Object o) {
		return o == _valider;
	}
	
	private void actualiserNbEssais() {
		_lbNbEssais.setText(new Integer(_nbEssais).toString());
	}
	
	class GestionnaireEvenements implements ActionListener, Serializable {
		private Etats _etat;
		private Color _couleurDragAndDrop;
		
		public GestionnaireEvenements(){
			_etat = Etats.ATTENTE_CLIC_COULEUR;
			_couleurDragAndDrop = new Color(0, 0, 0, 0);
		}
		
		@Override
		public void actionPerformed(ActionEvent e) {
			Object source = e.getSource();
			
			switch(_etat) {
				case ATTENTE_CLIC_COULEUR:
					if(estCouleur(source)) {
						_couleurDragAndDrop = ((JButton)source).getBackground();
						_etat = Etats.ATTENTE_CLIC_SAISIE;
					}
					else if(estValidation(source)) {
						int[] combinaison = new int[_saisie.length];
						for(int i=0; i<combinaison.length; ++i) {
							combinaison[i] = Couleur.toInt(_saisie[i].getBackground());
							if(combinaison[i] == 0) {
								return;
							}
						}
						_pnCenter.add(new TryAgain(_mastermind, combinaison));
						
						try {
							if(_mastermind.nbChiffresBienPlaces(combinaison) == _mastermind.getTaille()) {
								// GAGNÉ
								JOptionPane.showMessageDialog(null, "Vous avez gagné !");
								System.exit(0);
							}
						}
						catch(Exception ee) {
							JOptionPane.showMessageDialog(null, ee.getMessage(), "Erreur", JOptionPane.ERROR_MESSAGE);
						}

						--_nbEssais;
						actualiserNbEssais();
						
						if(_nbEssais == 0) {
							// PERDU
							JOptionPane.showMessageDialog(null, "Vous avez perdu !");
							System.exit(0);
						}
					}
					break;
				case ATTENTE_CLIC_SAISIE:
					if(estSaisie(source)) {
						((JButton)source).setBackground(_couleurDragAndDrop);
						_etat = Etats.ATTENTE_CLIC_COULEUR;
					}
					break;
			}
		}
		
	}
}
