import java.util.Scanner;

import stratego.*;

public class TestStrategoTextuel {

	/**
	 * The main function !
	 * @param args
	 */
	public static void main(String[] args) {
		Stratego monStratego = new Stratego();
		
		Scanner sc = new Scanner(System.in);
		System.out.println(" ## Que la baitaille commence !! Mouahahaha ! ##\n" +
						   "Entrez la posistion de la piece : \n");
		
		System.out.println(monStratego);
		System.out.print("X: ");
		int xSaisi = sc.nextInt();
		System.out.print("Y: ");
		int ySaisi = sc.nextInt(); 
		
		Position posSaisie = new Position(xSaisi, ySaisi);
		try {
			monStratego.getPlateau().calculerEtAfficherDeplacements(posSaisie);
		} catch (PieceImmobileException exceptionPieceImmobile) {
			System.out.println(exceptionPieceImmobile);
		} catch (CaseVideException exceptionCaseVide) {
			System.out.println(exceptionCaseVide);
		}
	}

}
