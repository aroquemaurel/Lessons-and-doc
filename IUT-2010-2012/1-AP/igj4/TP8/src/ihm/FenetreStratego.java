package ihm;

import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.JFrame;

@SuppressWarnings("serial")
/**
 * Affiche un PlateauIHM dans un JFrame
 * @author vnc0102a
 *
 */
public class FenetreStratego extends JFrame {
	private PlateauIHM _widget;
	
	public FenetreStratego() {

		setTitle("Strategoooo !");
		setPreferredSize(new Dimension(600, 675));
		setLayout(new FlowLayout());
		setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

		_widget = new PlateauIHM(); 
		add(_widget);
		pack();
		setVisible(true);
//		setResizable(false);
	}
	
	public static void main(String[] args) {
		new FenetreStratego();
	}
}
