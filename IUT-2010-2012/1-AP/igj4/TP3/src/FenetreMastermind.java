import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JOptionPane;


@SuppressWarnings("serial")
public class FenetreMastermind extends JFrame {
	public FenetreMastermind() {
		setTitle("MaaasteeerMiiind !");
		setPreferredSize(new Dimension(500, 600));
		setLayout(new FlowLayout());
		setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		
		
		
		add(new PanneauMastermind(6, 2));
		pack();
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new FenetreMastermind();
	}
}
