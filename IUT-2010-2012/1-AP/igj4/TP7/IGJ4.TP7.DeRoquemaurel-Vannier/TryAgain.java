import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class TryAgain extends JPanel {
	public TryAgain(Mastermind m, int[] combinaison) {
		setLayout(new FlowLayout());
		
		for(int i=0; i<combinaison.length; ++i) {
			JButton couleur = new JButton();
			couleur.setBackground(Couleur.fromInt(combinaison[i]));
			add(couleur);
		}
		try {
			JLabel lbBien = new JLabel("Bien placé : " + m.nbChiffresBienPlaces(combinaison));
			add(lbBien);
			JLabel lbMal = new JLabel("Mal placé : " + m.nbChiffresMalPlaces(combinaison));
			add(lbMal);
		}
		catch(Exception e) {
			JOptionPane.showMessageDialog(null, e.getMessage(), "Erreur", JOptionPane.ERROR_MESSAGE);
		}
	}
}
