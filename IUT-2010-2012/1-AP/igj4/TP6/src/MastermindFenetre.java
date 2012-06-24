import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;


public class MastermindFenetre extends JFrame {
	private static final long serialVersionUID = 1L;
	
	private int             _nbCouleurs;
	private JMenuItem[]     _couleurs;
	private static final int NB_COULEURS_MAX = 10;
	
	private int             _nbCombinaisons;
	private JMenuItem[]     _combinaisons;
	private static final int NB_COMBINAISONS_MAX = 10;
	
	private int             _nbEssais;
	private JMenuItem[]     _essais;
	private static final int NB_ESSAIS_MAX = 10;
	
	private JMenuItem       _sauvegarder;
	private JMenuItem       _restaurer;
	
	private MastermindIHM _widget; 
	
	public MastermindFenetre() {
		_nbCouleurs = 6;
		_nbCombinaisons = 4;
		_nbEssais = 10;
		
		setTitle("MaaasteeerMiiind !");
		setPreferredSize(new Dimension(500, 600));
		setLayout(new FlowLayout());
		setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		
		JMenuBar menu = new JMenuBar();
		setJMenuBar(menu);
		JMenu fichier = new JMenu("Fichier");
		menu.add(fichier);
		JMenuItem rejouer = new JMenuItem("Rejouer");
		rejouer.addActionListener(new GestRejouer());
		fichier.add(rejouer);
		GestPartie listenerPartie = new GestPartie();
		_sauvegarder = new JMenuItem("Sauvegarder");
		_sauvegarder.addActionListener(listenerPartie);
		fichier.add(_sauvegarder);
		_restaurer = new JMenuItem("Restaurer");
		_restaurer.addActionListener(listenerPartie);
		fichier.add(_restaurer);
		fichier.addSeparator();
		JMenuItem quitter = new JMenuItem("Quitter");
		quitter.addActionListener(new GestQuitter());
		fichier.add(quitter);
		
		
		
		JMenu options = new JMenu("Options");
		menu.add(options);
		JMenu couleurs = new JMenu("Couleurs");
		options.add(couleurs);
		_couleurs = new JMenuItem[NB_COULEURS_MAX];
		ChoixNbCouleurs listenerCouleurs = new ChoixNbCouleurs();
		for(int i=0; i<_couleurs.length; ++i) {
			_couleurs[i] = new JMenuItem(String.valueOf(i+1));
			_couleurs[i].addActionListener(listenerCouleurs);
			if(i+1 == _nbCouleurs) {
				_couleurs[i].setBackground(Couleur.fromInt(i+1));
			}
			couleurs.add(_couleurs[i]);
		}
		
		JMenu combinaison = new JMenu("Combinaisons");
		options.add(combinaison);
		_combinaisons = new JMenuItem[NB_COMBINAISONS_MAX];
		ChoixNbCombinaisons listenerCombinaisons = new ChoixNbCombinaisons();
		for(int i=0; i<_combinaisons.length; ++i) {
			_combinaisons[i] = new JMenuItem(String.valueOf(i+1));
			_combinaisons[i].addActionListener(listenerCombinaisons);
			if(i+1 == _nbCombinaisons) {
				_combinaisons[i].setBackground(Couleur.fromInt(i+1));
			}
			combinaison.add(_combinaisons[i]);
		}
		
		JMenu essais = new JMenu("Essais");
		options.add(essais);
		_essais = new JMenuItem[NB_ESSAIS_MAX];
		ChoixNbEssais listenerEssais = new ChoixNbEssais();
		for(int i=0; i<_essais.length; ++i) {
			_essais[i] = new JMenuItem(String.valueOf(i+1));
			_essais[i].addActionListener(listenerEssais);
			if(i+1 == _nbEssais) {
				_essais[i].setBackground(Couleur.fromInt(i+1));
			}
			essais.add(_essais[i]);
		}
		
		
		_widget = new MastermindIHM(_nbCouleurs, _nbCombinaisons, _nbEssais); 
		add(_widget);
		pack();
		setVisible(true);
		setResizable(false);
	}
	
	public static void main(String[] args) {
		new MastermindFenetre();
	}
	
	class GestQuitter implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent arg0) {
			System.exit(0);
		}
	}
	
	class GestRejouer implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent arg0) {
			remove(_widget);
			_widget = new MastermindIHM(_nbCouleurs, _nbCombinaisons, _nbEssais);
			add(_widget);
			setVisible(true);
			repaint();
		}
	}
	
	class GestPartie implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			int reponseDialogue = 0;
			try {
					if(e.getSource() == _sauvegarder) {
						reponseDialogue = JOptionPane.showConfirmDialog(null, "Voulez vous vraiment sauvegarder ?");
						if(reponseDialogue == JOptionPane.YES_OPTION) {
							//Sauvegarde
							ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("./partie.dat"));
							out.writeObject(_widget);
							out.close();
						}
					}
					else if(e.getSource() == _restaurer) {
						reponseDialogue = JOptionPane.showConfirmDialog(null, "Voulez vous vraiment restaurer ?");
						if(reponseDialogue == JOptionPane.YES_OPTION) {
							// restauration
							MastermindIHM ancien = _widget;
							ObjectInputStream in = new ObjectInputStream(new FileInputStream("./partie.dat"));
							_widget = (MastermindIHM) in.readObject();
							if(_widget != null) {
								remove(ancien);
								add(_widget);
								setVisible(true);
								repaint();
							}
							in.close();
						}
					}
				
			}
			catch(Exception ee) {
				System.out.println(ee);
			}
		}
	}
	
	class ChoixNbCouleurs implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			for(int i=0; i<NB_COULEURS_MAX; ++i) {
				if(e.getSource() == _couleurs[i]) {
					_couleurs[_nbCouleurs-1].setBackground(Couleur.INVISIBLE);
					_nbCouleurs = i+1;
					_couleurs[i].setBackground(Couleur.fromInt(i+1));
					
				}
			}
		}
	}
	
	class ChoixNbCombinaisons implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			for(int i=0; i<NB_COMBINAISONS_MAX; ++i) {
				if(e.getSource() == _combinaisons[i]) {
					_combinaisons[_nbCombinaisons-1].setBackground(Couleur.INVISIBLE);
					_nbCombinaisons = i+1;
					_combinaisons[i].setBackground(Couleur.fromInt(i+1));
					
				}
			}
		}
	}
	
	class ChoixNbEssais implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			for(int i=0; i<NB_ESSAIS_MAX; ++i) {
				if(e.getSource() == _essais[i]) {
					_essais[_nbEssais-1].setBackground(Couleur.INVISIBLE);
					_nbEssais = i+1;
					_essais[i].setBackground(Couleur.fromInt(i+1));
					
				}
			}
		}
	}
}
