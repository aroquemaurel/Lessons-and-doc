public class Exo1 extends JFrame {
	public Exo1() {
		super("Exercice 1");
		setDefaultOperation(JFrame.EXIT_ON_CLOSE);
		Container content = getContentPane();
		content.setBackground(Color.BLUE);

		setSize(400,600);
		setVisible(true);
	}
	public static void main(String[] args) {
		new Exo1();
	}
}
