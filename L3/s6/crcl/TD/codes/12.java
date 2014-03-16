Map<Priorite, ArrayDeque<Tache>> m = new EnumMap<>(Priorite.class);
for(Priorite p : Priorite.value()) {
	m.put(p, new ArrayDeque<>());
}

m.get(Priorite.MOYENNE).offerFirst(appelerEric);
m.get(Priorite.HAUTE).offerFirst(appelerMartine);
m.get(Priorite.HAUTE).offerFirst(coderBD);
m.get(Priorite.BASSE).offerFirst(coderLogique);
m.get(Priorite.MOYENNE).offerFirst(coderIHM);

ArrayDeque<Tache> l = m.get(Priorite.HAUTE);
System.out.println("La liste des taches de priorités haute est : "+l);
