// Base pour le jeu de ping pong avec synchronisation entre joueurs

// TODO A modifier pour faire jouer un joueur Ping et un joueur Pong
// TODO puis N joueurs Ping et M joueurs Pong avec N et M = parametres de l'application

public class BasePingPongSynchro {

	public static void main(String[] args)  {
		// Creation du "moniteur" gerant les acces synchronises a la table de jeu
		// la meme instance de la classe pour tous les joueurs (sinon, impossible
		// d'avoir de la synchro
		MoniteurTable laTable = new MoniteurTable();

		// Creation du comportement d'un joueur Ping
		Joueur comportementJoueurPing = new Joueur(1, Joueur.PING, laTable);
		Joueur comportementJoueurPong = new Joueur(2, Joueur.PONG, laTable);

		// Creation du thread associe
		Thread joueurPing = new Thread(comportementJoueurPing);
		Thread joueurPong = new Thread(comportementJoueurPong);

		// Lancement du joueur
		joueurPing.start();
		joueurPong.start();
		System.out.println("Fin lancement application BasePingPong_VRunnable");

		System.out.println("Fin application BasePingPong_VRunnable");
	}
}
