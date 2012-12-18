public enum TypeCase {
	VIDE, 
	JOUEUR1, 
	JOUEUR2
}

public class ModeleMorpion {
	private TypeCase plateau[][];
	
	public ModeleMorpion(){
		this.plateau = new TypeCase[3][3];
		this.initialiser();
	}

	public boolean casesAlignees(final int p_premiereCase, final int p_secondeCase) throws Exception {
	}

	public String toString(){
		String retour = "";

		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				retour +=" ";
				switch(this.plateau[i][j]) {
					case VIDE:
						retour += " ";
						break;
					case JOUEUR1:
						retour += "X";
						break;
					case JOUEUR2:
						retour += "O";
						break;
				}
			}
			retour += "\n";
		}
	}
