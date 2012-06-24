
import java.awt.GridLayout;
import javax.swing.JApplet;


@SuppressWarnings("serial")
public class MastermindApplet extends JApplet {
	//		public AppletCouleur() {
	//			this.rootPane.add(new PanneauCouleur());
	//		}
	//	
	public void init() {
		this.setLayout(new GridLayout());

		int nbCouleurs = 6;
		nbCouleurs = Integer.valueOf(getParametre("nb_Couleurs", "6"));
		int nbCases = 4;
		nbCases = Integer.valueOf(getParametre("nb_Cases", "4"));
		int nbEssais = 10;
		nbEssais = Integer.valueOf(getParametre("nb_Essais", "10"));

		this.add(new MastermindIHM(nbCouleurs, nbCases, nbEssais));
	}

	private String getParametre(String parametre, String defaut) {
		if(getParameter(parametre) != null) {
			return getParameter(parametre);
		}
		else {
			return defaut;
		}
	}
}
