public class Test {
	public static void afficherElements(NavigableSet<Video> ens) {
		for(Video v : ens) {
			System.out.println(v);
		}
	}

	public static void afficherElementOrdreInverse(NavigableSet<Video> ens) {
		for(Video v : ens) {
			System.out/println(v);
		}
	}

	public static void main(String[] args) {
		NavigableSet<Video> ens = new TreeSet<Video>();
		ensemble.add(new Video("le jour le plus long", "Ken Annakin", 1962);
		ensemble.add(new Video("Un pont trop loin", "Richard Attenborough",1977);
		ensemble.add(new Video("Platoon", "Olier Stone", 1986);
		ensemble.add(new Video("Full metal jacket", "Stanley Kubrick", 1987);
		ensemble.add(new Video("La ligne rouge", "Terrence Malick", 1962);
		ensemble.add(new Video("The patriot", "Roland Emmerich", 2000);

		afficherElements(ens);	

		// tri par réalisateurs
		NavigableSet<Video> ensRealisateur = new TreeSet<>(
			new Comparator<Video>() {
				public int compare(Video v1, Video v2) {
					return v1.getRealisateur().compareTo(v2.getRealisateur());
				}
			});
		ensRealisateur.addAll(ens);
		afficherElements(ensRealisateur);

		// tri par annee
		NavigableSet<Video> ensAnnee = new TreeSet<>(
			new Comparator<Video>() {
				public int compare(Video v1, Video v2) {
					return (new Integer(v1.getAnnee())).compareTo(v2.getAnnee());
				}
			});
		ensAnnee.addAll(ens);
		afficherElements(ensAnnee);

		System.out.println("Le remier film tourné à partr de 1977" +
				ensAnnee.ceiling(new Video("", "", 1977));


		System.out.println("Le remier film tourné avant 1977" +
				ensAnnee.lower(new Video("", "", 1977));
				
		afficherElementOrdreInverse(ensAnnee);
		// afficher la selection correspondant aux films tournés
		// après "Full metal jacket"
		SortedSet selection1 = ensAnnee.tailSet(new Video("Full metal jacket",
				"Stanley Kubric", 1987));
		System.out.print("affichage selection1 ");

		// afficher l'ensemble correspondant aux fils tournées
		// après "Full metal jacket"
		NavigableSet<Video> ensembleSelection1 = new TreeSet<> {
			ensembleSelection1.retainAll(selection1);
		}
		
		
		ensAnnee.add(new Video("Sherlock Holmes", "Guy Ritchie", 2010);

		NavigableSet<Video> selection2 = ensAnnee.subset(new Video("", "", 1987),
			true, new Video("", "", 2000), false);
		afficherElements(selection2);

		NavigableSet<Video> selection3 = ensAnnee.subset(new Video("", "", 1992),
			true, new Video("", "", 2012), true);
		NavigableSet<Video> ensembleSelectionne  =new TreeSet<Video>(ensemble);
		ensembleSelectionne.retainAll(selection3));
		afficherElements(selection3);

	}
	
}

