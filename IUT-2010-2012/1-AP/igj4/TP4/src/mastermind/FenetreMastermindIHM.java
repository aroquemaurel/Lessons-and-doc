package mastermind;

import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.JFrame;

@SuppressWarnings("serial")
public class FenetreMastermindIHM extends JFrame {
	public FenetreMastermindIHM() {
		setTitle("MaaasteeerMiiind !");
		setPreferredSize(new Dimension(500, 600));
		setLayout(new FlowLayout());
		setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		
		add(new MastermindIHM(6, 2, 10));
		pack();
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new FenetreMastermindIHM();
	}
}
