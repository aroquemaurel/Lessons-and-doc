public class Application {
	public static void main(String [] args){
		Frame fenetre = new Frame();
		fenetre.setTitle("Jeu du morpion");
		fenetre.setLayout(new GridLayout(1, 1));
		fenetre.add(new VueMorpion());
		fenetre.setValeurCase(true);
		fenetre.pack();
		fenetre.setSize(50,70);
	}
}
