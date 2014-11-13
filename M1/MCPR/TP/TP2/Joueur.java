// Joueur dans le jeu de ping pong avec synchronisation via un "moniteur" Table

public class Joueur implements Runnable {
	// Lee type de coup joue
	private int monType;
	// Le numero associe au joueur
	private int monNum;
	// Le "moniteur" gerant l'acces des joueurs a la table commune
	private MoniteurTable maTable;

	// Constructeur de la classe joueur
	public Joueur (int numJoueur, int typeJoueur, MoniteurTable uneTable) {
		monType = typeJoueur;
		monNum = numJoueur;
		maTable = uneTable;
		System.out.println("Joueur " + monNum + " (" + monType + ") : defini");
	}

	// Implantation de run => comportement du joueur
	public void run() {
		int i;
		for (i = 0; i < 10; i++) {
			// Demander l'acces a la table pour jouer quand il le faut 
			// A completer : appeler l'operation qui convient de la classe "moniteur"
			// maTable.le nom de l'operation();
			// On a l'acces a la table, on peut jouer (en prenant un peu de temps)
			for (int j = 0; j < 10; j++)
				System.out.println("Joueur " + monNum + " (de type " + monType + ") : je joue pour la " + i + "me fois");
			// Relacher l'acces a la table pour laisser jouer le suivant
			// A completer : appeler l'operation qui convient de la classe "moniteur"
			// maTable.le nom de l'operation();
		}
		System.out.println("Joueur " + monNum + " (de type " + monType + ") : termine");
	}
}


