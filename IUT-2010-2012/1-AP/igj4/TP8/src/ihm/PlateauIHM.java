package ihm;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import stratego.CampInvalideException;
import stratego.CaseNonVideException;
import stratego.CouleurPieceInvalideException;
import stratego.InterfaceStratego;
import stratego.NomPieceInvalideException;
import stratego.PositionInvalideException;
import stratego.Stratego;

enum Etats {
	ATTENTE_SELECTION_POSITIONNEMENT,
	ATTENTE_PLACEMENT_POSITIONNEMENT,
	ATTENTE_SELECTION_JEU,
	ATTENTE_DEPLACEMENT_JEU,
	PARTIE_FINIE;
}

class TypesPieces {
	public static final int ESPION = 1;
	public static final int ECLAIREUR = 2;
	public static final int DEMINEUR = 3;
	public static final int SERGENT = 4;
	public static final int LIEUTENANT = 5;
	public static final int CAPITAINE = 6;
	public static final int COMMANDANT = 7;
	public static final int COLONEL = 8;
	public static final int GENERAL = 9;
	public static final int MARECHAL = 10;
	public static final int BOMBE = 11;
	public static final int DRAPEAU = 0;
	
	public static String toStr(int i) {
		switch (i) {
			case 1:
				return "espion";
			case 2:
				return "eclaireur";
			case 3:
				return "demineur";
			case 4:
				return "sergent";
			case 5:
				return "lieutenant";
			case 6:
				return "capitaine";
			case 7:
				return "commandant";
			case 8:
				return "colonel";
			case 9:
				return "general";
			case 10:
				return "marechal";
			case 11:
				return "bombe";
			default:
				return "drapeau";
		}
	}
}

class Joueur {
	public static final String BLEU = "bleu";
	public static final String ROUGE = "rouge";
}

@SuppressWarnings("serial")
public final class PlateauIHM extends JPanel {
	private JPanel		_pnCentre;
	private CaseIHM[][]	_cases;
	private JTextArea	_zoneMessages;
	
	private String		_joueurCourant;

	private InterfaceStratego _modele;

	private static final int DIM_PLATEAU = 10;

	private int			_xPieceActive;
	private int			_yPieceActive;
	
	// Positionnement
	private JPanel		_pnPositionnement;
	private int[][]		_piecesRestantes;
	private JButton[]	_boutonsPositionnement;
	private int			_boutonPressee;
	
	private static final int NB_ESPION = 1;
	private static final int NB_ECLAIREUR = 8;
	private static final int NB_DEMINEUR = 5;
	private static final int NB_SERGENT = 4;
	private static final int NB_LIEUTENANT = 4;
	private static final int NB_CAPITAINE = 4;
	private static final int NB_COMMANDANT = 3;
	private static final int NB_COLONEL = 2;
	private static final int NB_GENERAL = 1;
	private static final int NB_MARECHAL = 1;
	private static final int NB_BOMBE = 6;
	private static final int NB_DRAPEAU = 1;
	

	public PlateauIHM() {
		// Modele
		_modele = new Stratego();
		//*/
		
		EcouteurEvenements listener = new EcouteurEvenements();

		_xPieceActive = -1;
		_yPieceActive = -1;

		// Swing
		setLayout(new BorderLayout());

		// CENTER
		_pnCentre = new JPanel();
		_pnCentre.setLayout(new GridLayout(DIM_PLATEAU,
				DIM_PLATEAU));
		add(_pnCentre, BorderLayout.CENTER);

		_cases =  new CaseIHM[DIM_PLATEAU][DIM_PLATEAU];
		for(int i=0; i<DIM_PLATEAU ; ++i) {
			for(int j=0; j<DIM_PLATEAU ; ++j) {
				_cases[i][j] = new CaseIHM(i, j);
				_cases[i][j].addActionListener(listener);
				_pnCentre.add(_cases[i][j]);
			}
		}

		// SOUTH
		JPanel pnMessage = new JPanel();
		add(pnMessage, BorderLayout.SOUTH);

		_zoneMessages = new JTextArea(4, 40);
		_zoneMessages.setEditable(false);
		_zoneMessages.setSelectionEnd(_zoneMessages.getText().length());
		pnMessage.add(new JScrollPane(_zoneMessages));
		//*/
		
		// POSITIONENMENT
		_boutonPressee = -1;
		
		_pnPositionnement = new JPanel();
		add(_pnPositionnement, BorderLayout.WEST);
		_pnPositionnement.setLayout(new GridLayout(10, 4));
		
		_piecesRestantes = new int[2][12];
		for(int i=0; i<2; ++i) {
			_piecesRestantes[i][TypesPieces.ESPION]=  NB_ESPION;
			_piecesRestantes[i][TypesPieces.ECLAIREUR]=  NB_ECLAIREUR;
			_piecesRestantes[i][TypesPieces.DEMINEUR]=  NB_DEMINEUR;
			_piecesRestantes[i][TypesPieces.SERGENT]=  NB_SERGENT;
			_piecesRestantes[i][TypesPieces.LIEUTENANT]=  NB_LIEUTENANT;
			_piecesRestantes[i][TypesPieces.CAPITAINE]=  NB_CAPITAINE;
			_piecesRestantes[i][TypesPieces.COMMANDANT]=  NB_COMMANDANT;
			_piecesRestantes[i][TypesPieces.COLONEL]=  NB_COLONEL;
			_piecesRestantes[i][TypesPieces.GENERAL]=  NB_GENERAL;
			_piecesRestantes[i][TypesPieces.MARECHAL]=  NB_MARECHAL;
			_piecesRestantes[i][TypesPieces.DRAPEAU]=  NB_DRAPEAU;
			_piecesRestantes[i][TypesPieces.BOMBE]=  NB_BOMBE;
		}
		
		_boutonsPositionnement = new JButton[40];
		for(int i=0; i<40; ++i) {
			_boutonsPositionnement[i] = new JButton();
			_boutonsPositionnement[i].addActionListener(listener);
			_boutonsPositionnement[i].setPreferredSize(new Dimension(30, 30));
			_pnPositionnement.add(_boutonsPositionnement[i]);
		}
		//*/
		_joueurCourant = Joueur.BLEU;
		joueurSuivant();
//		_modele.remplirPlateau();
		
		rafraichir();
	}
	
	public void afficher(String pMessage) {
		_zoneMessages.append(pMessage);
		_zoneMessages.append("\n");
	}
	
	public boolean estCase(Object o) {
		for(CaseIHM[] row : _cases) {
			for(CaseIHM c : row) {
				if(o == c) {
					return true;
				}
			}
		}
		return false;
	}
	
	public int getX(Object o) {
		for(int x=0; x<_cases.length; ++x) {
			for(int y=0; y<_cases[x].length; ++y) {
				if(_cases[x][y] == o) {
					return x;
				}
			}
		}
		return -1;
	}
	
	public int getY(Object o) {
		for(int x=0; x<_cases.length; ++x) {
			for(int y=0; y<_cases[x].length; ++y) {
				if(_cases[x][y] == o) {
					return y;
				}
			}
		}
		return -1;
	}

	/**
	 * rafraichit l'affichage du plateau graphique a partir du plateau non graphique
	 * associé au modele
	 */
	private void rafraichir() {
		try {
			if(nbPiecesRestantAPositionner() != 0) {
				for(int i=0; i<40; ++i) {
					int piece = pieceALaPosition(i);
//					if(i != -1) {
					if(i<nbPiecesRestantAPositionner()) {
						if(i == _boutonPressee) {
							_boutonsPositionnement[i].setIcon(new PieceIHM(TypesPieces.toStr(piece), _joueurCourant, "actif"));
						}
						else {
							_boutonsPositionnement[i].setIcon(new PieceIHM(TypesPieces.toStr(piece), _joueurCourant, ""));
						}
						_boutonsPositionnement[i].setVisible(true);
					}
					else {
						_boutonsPositionnement[i].setIcon(new ImageIcon());
						_boutonsPositionnement[i].setVisible(false);	
					}
				}
			}
			else {
				_pnPositionnement.setVisible(false);
			}
			// pour chaque case du plateau de la partie
			for (int i=0 ; i<DIM_PLATEAU ; i++) {
				for (int j=0 ; j<DIM_PLATEAU ; j++) {
					CaseIHM c = _cases[i][j];

					String nom = _modele.getNomPiece(i,j);
					// nom == null => case vide
					if (nom != null) {
						String couleur = _modele.getCouleurPiece(i,j);

						if (_modele.estPieceVisible(i, j)
								|| _modele.estJoueurBleuGagnant()
								|| _modele.estJoueurBleuGagnant()) {
							if(i == _xPieceActive && j == _yPieceActive) {
								c.setIcon(new PieceIHM(nom, couleur, "actif"));
							}
							else {
								c.setIcon(new PieceIHM(nom, couleur, ""));
							}
							c.setToolTipText(nom);
						} else {
							c.setIcon(new PieceIHM(nom, couleur));
							c.setToolTipText(null);
						}
					}
					else if(estLac(i, j)) {
						_cases[i][j].setIcon(new ImageIcon("./images/lac.gif"));
					}
					else {
						c.setIcon(null) ;
					} 
				} // rof
			} // rof
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println(e);
		}
	}
	
	private boolean estLac(int x,
						   int y) {
		return (x == 4 || x == 5) && (y == 2 || y == 3 || y == 6 || y == 7);
	}
	
	private void joueurSuivant() {
		_joueurCourant = (_joueurCourant.equals(Joueur.ROUGE))
				? Joueur.BLEU 
				: Joueur.ROUGE;
		afficher("Au tour du joueur " + _joueurCourant + " de jouer");
	}

	private int nbPiecesRestantAPositionner() {
		int[] pieces = piecesJoueurCourant();
		int retour = 0;
		for(int i=0; i<12; ++i) {
			retour += pieces[i];
		}
		return retour;
	}
	
	private int pieceALaPosition(int pos) {
		int[] pieces = piecesJoueurCourant();
				
		int reste = 0;
		
		for(int i=0; i<12; ++i) {
			if(pos < (reste + pieces[i])) {
				return i;
			}
			else {
				reste += pieces[i];
			}
		}
		return -1;
	}
	
	private int[] piecesJoueurCourant() {
		return (_joueurCourant.equals(Joueur.BLEU))
				? _piecesRestantes[0]
				: _piecesRestantes[1];
	}
	
	private int noBouton(Object source) {
		int noBouton = -1;
		for(int i=0; i<_boutonsPositionnement.length; ++i) {
			if(_boutonsPositionnement[i].equals(source)) {
				noBouton = i;
				break;
			}
		}
		return noBouton;
	}
	
	private class EcouteurEvenements implements ActionListener {
		private Etats _etat;
		private int _pieceSelectionee;
		
		public EcouteurEvenements() {
			_pieceSelectionee = -1;
			_etat = Etats.ATTENTE_SELECTION_POSITIONNEMENT;

		}
		
		
		@Override
		public void actionPerformed(ActionEvent evenement) {
			switch (_etat) {
				case ATTENTE_SELECTION_POSITIONNEMENT:
					if(selectionPositionnementValide(evenement)) {
						selectionnerPourPositionner(evenement);
						_etat = Etats.ATTENTE_PLACEMENT_POSITIONNEMENT;
					}
					break;
				case ATTENTE_PLACEMENT_POSITIONNEMENT:
					if(recliquerSurPieceEnStock(evenement)) {
						annulerSelectionPlacement(evenement);
						_etat = Etats.ATTENTE_SELECTION_POSITIONNEMENT;
					}
					else {
						try {
							positionner(evenement);
							joueurSuivant();
							if(nbPiecesRestantAPositionner() == 0) {
								afficher("Commençons a jouer !");
								_etat = Etats.ATTENTE_SELECTION_JEU;
							}
							else {
								_etat = Etats.ATTENTE_SELECTION_POSITIONNEMENT;
							}
						}
						catch (Exception e) {
							afficher("choisissez une position valide !");
						}
					}
					break;
				case ATTENTE_SELECTION_JEU:
					if(selectionValide(evenement)) {
						selectionner(evenement);
						_etat = Etats.ATTENTE_DEPLACEMENT_JEU;
					}
					break;
				case ATTENTE_DEPLACEMENT_JEU:
					if(recliquerSurPiece(evenement)) {
						annulerSelectionJeu(evenement);
						_etat = Etats.ATTENTE_SELECTION_JEU;
					}
					deplacer(evenement);
					if(_modele.estJoueurBleuGagnant() || _modele.estJoueurRougeGagnant()) {
						_etat = Etats.PARTIE_FINIE;
					}
					else {
						_etat = Etats.ATTENTE_SELECTION_JEU;
						joueurSuivant();
					}
					break;
			}
			if(_etat == Etats.PARTIE_FINIE) {
				String gagnant = (_modele.estJoueurBleuGagnant()) ? "bleu" : "rouge";
				String message = "le joueur " + gagnant + " a gagné !";
				afficher(message);
				JOptionPane.showMessageDialog(null, message, "Gagné", JOptionPane.INFORMATION_MESSAGE);
				
			}
			rafraichir();
		}

		// ACTIONS
		private void selectionner(ActionEvent evenement) {			
			// Sauvegarde des coordonnées
			_xPieceActive = getX(evenement.getSource());
			_yPieceActive = getY(evenement.getSource());
		}
		
		private void annulerSelectionJeu(ActionEvent evenement) {
			_xPieceActive = -1;
			_yPieceActive = -1;
		}
		
		private void deplacer(ActionEvent evenement) {
			int xDest = getX(evenement.getSource());
			int yDest = getY(evenement.getSource());
			
			try {
				_modele.jouer(_xPieceActive, _yPieceActive, xDest, yDest);
			} catch (Exception e) {
				afficher("Erreur : " + e.getMessage());
			}
		}

		private void annulerSelectionPlacement(ActionEvent evenement) {
			_boutonPressee = -1;
			_pieceSelectionee = -1;
		}

		private void selectionnerPourPositionner(ActionEvent evenement) {
			int typePiece = pieceALaPosition(noBouton(evenement.getSource()));
			_boutonPressee = noBouton(evenement.getSource());
			_pieceSelectionee = typePiece;
		}
		
		private void positionner(ActionEvent evenement) throws Exception {
			int xDest = getX(evenement.getSource());
			int yDest = getY(evenement.getSource());
			_modele.positionnerPiece(TypesPieces.toStr(_pieceSelectionee), _joueurCourant, xDest, yDest);
			// moinsmoinsser !!!!
			piecesJoueurCourant()[_pieceSelectionee]--;
			_boutonPressee = -1;
		}
		
		// CONDITIONS
		private boolean selectionValide(ActionEvent evenement) {
			if(!estCase(evenement.getSource())) {
				return false;
			}
			
			int xSource = getX(evenement.getSource());
			int ySource = getY(evenement.getSource());
						
			if(estLac(xSource, ySource)) {
				return false;
			}
			
			String lowerCouleurPiece = _modele.getCouleurPiece(xSource, ySource).toLowerCase();
			
			
//			if(!lowerCouleurPiece.equals(_joueurCourant)) {
//				return false;
//			}
			
			return true;
		}

		private boolean recliquerSurPiece(ActionEvent evenement) {
			if(!estCase(evenement.getSource())) {
				return false;
			}
			
			int xSource = getX(evenement.getSource());
			int ySource = getY(evenement.getSource());
			
			return (xSource == _xPieceActive && ySource == _yPieceActive);
		}

		private boolean selectionPositionnementValide(ActionEvent evenement) {
			return estCasePositionnement(evenement.getSource());
		}

		private boolean recliquerSurPieceEnStock(ActionEvent evenement) {
			if(estCasePositionnement(evenement.getSource())) {
				return _boutonPressee == noBouton(evenement.getSource());
			}
			return false;
		}

	}

	public boolean estCasePositionnement(Object source) {
		boolean retour = false;
		for(int i=0; i<_boutonsPositionnement.length; ++i) {
			retour |= _boutonsPositionnement[i].equals(source);
		}
		return retour;
	}
}
