// Classe jouant le role du moniteur qui protege les acces
// a la table de ping-pong et assure l'alternance des coups
// des joueurs 

// Pour declarer des "variables condition"
import java.util.concurrent.locks.Condition;
// Pour declarer des verrous ou semaphores d'exclusion mutuelle
import java.util.concurrent.locks.ReentrantLock;

public class MoniteurTable {
	// Les types de coups possibles
	public final int PONG = 0;
	public final int PING = 1;

	// Variable utiles pour la synchronisation
	// verrous, variables conditions . . . 
	// A modifier /completer
	private final ReentrantLock mutex;
	private final Condition varCondition; 
	// Variables d'etat
	// A completer

	// Constructeur de la classe
	public MoniteurTable () {
		// Creer les verrous et variables condition
		// A cmodifier / ompleter
		mutex = new ReentrantLock();
		varCondition = mutex.newCondition();
	}

	// Obtenir l'acces a la table pour pouvoir jouer
	public void demanderAccesTable(int typeJoueur) throws InterruptedException {
		// Assurer l'exclusion mutuelle (E.M.) entre les operations
		// . . . 
		// Se bloquer si on ne peut pas jouer
		// . . .
		// On a acces a la table
		// . . . 
		// Fin de l'E.M.
		// . . . 
	}

	// Rendre l'acces au joueur du type oppose
	public void libererAccesTable() {
		// Assurer l'exclusion mutuelle (E.M.) entre les operations
		// . . . 
		// Liberer la table
		// . . .
		// L'autre doit jouer, le reveiller
		// . . . 
		// Fin de l'E.M.
		// . . . 
	}
}
