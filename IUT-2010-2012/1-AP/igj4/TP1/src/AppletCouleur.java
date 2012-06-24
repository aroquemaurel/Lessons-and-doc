import java.awt.GridLayout;

import javax.swing.JApplet;


@SuppressWarnings("serial")
public class AppletCouleur extends JApplet {
//	public AppletCouleur() {
//		this.rootPane.add(new PanneauCouleur());
//	}
//	
	public void init() {
		this.setLayout(new GridLayout());
		this.add(new PanneauCouleur());
	}
}
