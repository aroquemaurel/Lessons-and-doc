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

}
