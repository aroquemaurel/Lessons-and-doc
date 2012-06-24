package ihm;

import java.awt.Dimension;

import javax.swing.JButton;

@SuppressWarnings("serial")
public final class CaseIHM extends JButton {
	private int _colonne;
	private int _ligne;
	
	public CaseIHM(int x, int y) {
		_ligne = x;
		_colonne = y;
		setPreferredSize(new Dimension(39, 55));
	}

	public int getColonne() {
		return _colonne;
	}

	public int getLigne() {
		return _ligne;
	}
	
	public PieceIHM getPiece() {
		return null;
	}
}
