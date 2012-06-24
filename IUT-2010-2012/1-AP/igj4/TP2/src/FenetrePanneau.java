import java.awt.FlowLayout;

import javax.swing.JFrame;


@SuppressWarnings("serial")
public class FenetrePanneau extends JFrame {
	public FenetrePanneau() {
		setTitle("Piooon !");
		setLayout(new FlowLayout());
		setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		add(new Panneau());
		pack();
		setVisible(true);
	}
}
