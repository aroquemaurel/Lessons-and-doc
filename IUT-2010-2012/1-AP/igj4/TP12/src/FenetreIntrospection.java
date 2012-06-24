import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.JFrame;


public class FenetreIntrospection extends JFrame {
	private IntrospectionIHM _widget;
	
	public FenetreIntrospection() {

		setTitle("Introspeeeectioooon !");
		setPreferredSize(new Dimension(600, 675));
		setLayout(new FlowLayout());
		setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

		_widget = new IntrospectionIHM(); 
		add(_widget);
		pack();
		setVisible(true);
//		setResizable(false);
	}
	
	public static void main(String[] args) {
		new FenetreIntrospection();
	}
}
