public class DocumentCompose {
	private ArrayList <Position> composants;

	public DocumentSimple getComposant (Position p_position){
		DocumentSimple docSimple = null;
		int index = this.composants.indexOf(p_position);
		if(index != -1){
			docSimple = this.composants.get(index);
		}
		return docSimple;
	}

}
