package mastermind;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

enum Etats {
	ATTENTE_CLIC_COULEUR,
	ATTENTE_CLIC_SAISIE
}

@SuppressWarnings("serial")
public class MastermindIHM extends JPanel {
	private Mastermind   _mastermind;
	private JButton[]    _palette;
	private JTextField[] _combinaisonOrdinateur;
	
	private JButton[][]  _combinaisonJoueur;
	private JTextField[] _bp;
	private JTextField[] _mp;
	
	private JButton[]    _saisie;
	private JButton      _valider;
	
	private int          _nbEssais;
	private JLabel       _lbNbEssais;
	private JPanel       _pnCenter;
	
	public MastermindIHM(int nbCouleurs, int nbCases, int nbEssais) {
		GestionnaireEvenements listener = new GestionnaireEvenements();
		
		_mastermind = new Mastermind(nbCouleurs, nbCases);
		_mastermind.genererCombinaison();
		
		_nbEssais = nbEssais;
		
		setLayout(new BorderLayout());
		
		// CENTER
		_pnCenter = new JPanel();
		_pnCenter.setLayout(new GridLayout(_nbEssais, _mastermind.getTaille()+1));
		add(_pnCenter, BorderLayout.CENTER);
		
		_combinaisonJoueur = new JButton[_nbEssais][_mastermind.getTaille()];
		_bp = new JTextField[_nbEssais];
		_mp = new JTextField[_nbEssais];
		for(int x=0; x<nbEssais; ++x) {
			int rangCourant = nbEssais-x-1;
			
			for(int y=0; y< _mastermind.getTaille(); ++y) {
				_combinaisonJoueur[rangCourant][y] = new JButton();
				_combinaisonJoueur[rangCourant][y].setMaximumSize(new Dimension(32, 32));
				_combinaisonJoueur[rangCourant][y].setBackground(Couleur.VIDE);
				_pnCenter.add(_combinaisonJoueur[rangCourant][y]);
			}
			JPanel panelBpMp = new JPanel();
			_pnCenter.add(panelBpMp);
			panelBpMp.setLayout(new GridLayout(2, 2));
			panelBpMp.add(new JLabel("Bien Placé"));
			panelBpMp.add(new JLabel("Mal Placé"));
			_bp[rangCourant] = new JTextField();
			_bp[rangCourant].setEditable(false);
			panelBpMp.add(_bp[rangCourant]);
			_mp[rangCourant] = new JTextField();
			_mp[rangCourant].setEditable(false);
			panelBpMp.add(_mp[rangCourant]);
		}
		
		// NORTH
		JPanel pnSouth = new JPanel();
		add(pnSouth, BorderLayout.NORTH);
		
		pnSouth.setLayout(new FlowLayout());
		JLabel lbCouleurs = new JLabel("Couleurs");
		pnSouth.add(lbCouleurs);
		_palette = new JButton[_mastermind.getNbCouleurs()];
		for(int i=0; i<_palette.length; ++i) {
			_palette[i] = new JButton();
			_palette[i].setPreferredSize(new Dimension(32, 32));
			_palette[i].setBackground(Couleur.fromInt(i+1));
			_palette[i].addActionListener(listener);
			pnSouth.add(_palette[i]);
		}
		
		// NORTH
		JPanel pnNorth = new JPanel();
		add(pnNorth, BorderLayout.SOUTH);
		_saisie = new JButton[_mastermind.getTaille()];
		for(int i=0; i<_saisie.length; ++i) {
			_saisie[i] = new JButton();
			_saisie[i].setPreferredSize(new Dimension(32, 32));
			_saisie[i].setBackground(Couleur.fromInt(0));
			_saisie[i].addActionListener(listener);
			pnNorth.add(_saisie[i]);
		}
		_valider = new JButton("Valider");
		_valider.addActionListener(listener);
		pnNorth.add(_valider);
		
		_lbNbEssais = new JLabel();
		actualiserNbEssais();
		pnNorth.add(_lbNbEssais);
	}
	
	private boolean estCouleur(Object o) {
		boolean retour = false;
		for(int i=0; i<_palette.length; ++i) {
			if(o == _palette[i]) {
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
	
	class GestionnaireEvenements implements ActionListener {
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
						try {
							//_pnCenter.add(new TryAgain(_mastermind, combinaison));
							_bp[_nbEssais-1].setText(new Integer(_mastermind.nbChiffresBienPlaces(combinaison)).toString());
							_mp[_nbEssais-1].setText(new Integer(_mastermind.nbChiffresMalPlaces(combinaison)).toString());
							
							for(int i=0; i<_mastermind.getTaille(); ++i) {
								_combinaisonJoueur[_nbEssais-1][i].setBackground(_saisie[i].getBackground());
							}
						
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
