Client societeBricolage = new Client("Tous travaux");
Client bijoutier = new Client("L'étincelant");
Client jardinerie = new Client("Espace vert");

Map<Tache, Client> m = new HashMap<>();
m.put(coderBD, bijoutier);
m.put(coderLogique, jardinerie);
m.put(coderIHM, societeBricolage);
m.put(appelerMartine, societeBricolage);
m.put(appelerEric, null);

for(Tache t : m.keySet()) {
	Client c = m.get(t);
	if(c == null) {
		System.out.print("pas de client");
	} else {
		System.out.prnt("Client" + c);
	}
	System.out.println(", pour la tache : "+t);
}
m.get(CoderIHM).facturer(coderIHM);

client = m.get(new Clee("Telephone Martine"));
client.facturer(appelerMartine);

Collection<Client> clients = m.values();
for(Iterator<Client> it = clients.iterator() ; it.hasNext()) {
	if(societeBricolage.equals(it.next())) {
		it.remove();
	}
}

Collection<Client> clients = m.values();
clients.removeAll(Collections.singleton(societeBricolage));
System.out.println("Facturation des clients en préparation :", m);

clients.removeAll(Collections.singleton(null));
System.out.println("Facturation des clients en prépa :"+m);
