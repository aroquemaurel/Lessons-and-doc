import java.awt.Color;

public class Couleur {
	public static Color INVISIBLE = new Color(255, 255, 255, 0);
	public static Color VIDE      = new Color(255, 255, 255);
	public static Color ROUGE     = new Color(255, 0,   0);
	public static Color VERT      = new Color(0,   255, 0);
	public static Color BLEU      = new Color(0,   0,   255);
	public static Color CYAN      = new Color(0,   255, 255);
	public static Color JAUNE     = new Color(255, 255, 0);
	public static Color MAGENTA   = new Color(255, 0,   255);
	public static Color MACHIN    = new Color(127, 0,   127);
	public static Color TRUC      = new Color(127, 127, 0);
	public static Color BIDULE    = new Color(0,   127, 127);
	public static Color CHOSE     = new Color(255, 127, 0);
	
	public static Color fromInt(int c) {
		switch(c) {
			case 1:
				return ROUGE;
			case 2:
				return VERT;
			case 3:
				return BLEU;
			case 4:
				return CYAN;
			case 5:
				return JAUNE;
			case 6:
				return MAGENTA;
			case 7:
				return MACHIN;
			case 8:
				return TRUC;
			case 9:
				return BIDULE;
			case 10:
				return CHOSE;
			default:
				return VIDE;
		}
	}
	
	public static int toInt(Color c) {
		if(c.equals(ROUGE)) {
			return 1;
		}
		else if(c.equals(VERT)) {
			return 2;
		}
		else if(c.equals(BLEU)) {
			return 3;
		}
		else if(c.equals(CYAN)) {
			return 4;
		}
		else if(c.equals(JAUNE)) {
			return 5;
		}
		else if(c.equals(MAGENTA)) {
			return 6;
		}
		else if(c.equals(MACHIN)) {
			return 7;
		}
		else if(c.equals(TRUC)) {
			return 8;
		}
		else if(c.equals(BIDULE)) {
			return 9;
		}
		else if(c.equals(CHOSE)) {
			return 10;
		}
		else {
			return 0;
		}
	}
}
