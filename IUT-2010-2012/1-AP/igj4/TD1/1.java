/**
 * Enumeration des différents types de cases
 */
public enum TypeCase {
	VIDE, 
	JOUEUR1, 
	JOUEUR2
}

/**
 * Classe gérant les actions du jeu indépendamment de l'interface
 *			MODELE
 */
public class ModeleMorpion {
	private TypeCase plateau[][];
	
	public ModeleMorpion(){
		this.plateau = new TypeCase[3][3];
		this.initialiser();
	}

	public boolean casesAlignees(final int p_premiereCase, final int p_secondeCase) 
		throws Exception {
	}

	public TypeCase getValeurCase(final int x, final int y) throws Exception {
		return (this.plateau[i][j]);
	}

	public void initialiser(){
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				this.plateau[i][j] = TypeCase.VIDE;
			}
		}
	}

	public void setValeurCase(final int i, final int j, TypeCase p_type){
		this.plateau[i][j] = p_type;
	}


	@Override
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

}
