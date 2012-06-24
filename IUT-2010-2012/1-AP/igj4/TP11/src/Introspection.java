import java.lang.reflect.*;
import java.util.Scanner;

final public class Introspection {
	public static void main(String[] args) {
		try {
//			lire le nom de la classe à introspecter ;
			Scanner sc = new Scanner(System.in);
			String nomClasse = sc.nextLine();
			
//			récupérer un objet de type Class associé à la classe à introspecter ;
			Class classe = ClassLoader.getSystemClassLoader().loadClass(nomClasse);
			
//			écrire le nom de la classe à introspecter ;
			System.out.println("class " + classe.getName() + " {");
			
//			récupérer les méthodes publiques de la classe sous forme d'un tableau ;
			Method methodes[] = classe.getMethods();

			
//			récupérer les attributs publics de la classe sous forme d’un tableau ;
			Field[] attributsPublic = classe.getDeclaredFields();
//			pour chaque attribut public faire
			for(Field attribut : attributsPublic) {
//			      écrire son type ;
				System.out.print("\tpublic "+attribut.getType());
//			      écrire son nom ;
				System.out.println(" "+attribut.getName()+";");
//			fin pour ;
			}
			
			System.out.println();
			
//			récupérer les constructeurs de la classe sous forme d'un tableau ;
			Constructor[] constrs = classe.getConstructors();
//			pour chaque constructeur faire
			for(Constructor constr : constrs) {
//			      écrire son nom ;
				System.out.print("\tpublic " + constr.getName() + "(");
//			      pour chaque paramètre attendu faire
				for(TypeVariable typeParam : constr.getTypeParameters()) {
//			            écrire son type ;
					System.out.print(typeParam.getName() + " ");
//			      fin pour ;
				}
				System.out.println(");");
//			fin pour ;
			}
			
			System.out.println();
			
//			pour chaque méthode faire
			for(Method m : methodes) {
//			      écrire le type de la valeur retournée ;
				System.out.print("\tpublic " + m.getReturnType());
//			      écrire son nom ;
				System.out.print(" " + m.getName() + "(");
//			      pour chaque paramètre attendu faire
				for(TypeVariable<Method> typeParam : m.getTypeParameters()) {
//			            écrire son type ;
					System.out.println(typeParam.getName() + " ");
//			      fin pour ;
				}
				System.out.println(");");
//			fin pour ;
			}
			
			System.out.println("}");

		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}
