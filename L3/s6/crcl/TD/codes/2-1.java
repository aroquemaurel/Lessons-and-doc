Tache appelerEric = new TacheTelephone("Ertineric", "0211223344");
Tache appelerMartine = new TacheTelephone("", "0211223344");

Tache coderBd = new TacheCodage("bd");
Tache coderIHM = new TacheCodage("ihm");
Tache coderLogique = new TacheCodage("logique");

// Le paramètre correspond au nombre d'élément intialement alloués. 
// Ca permet d'éviter la réallocation inutile
// Par défaut = 10
List tachsAppel = new ArrayList();
List tachsCodage = new ArrayList();
List tachsLundi = new ArrayList(8);
List tachsMardi = new ArrayList(8);

tachesAppel.add(appelerEric);
tachesAppel.add(appelerMartine);

tachesCodage.add(coderBd);
tachesCodage.add(coderLogique);
tachesCodage.add(1,coderIHM);

tachesLundi.add(coderLogique);
tachesLundi.add(appelerMartine);
tachesLundi;set(1,appelerEric);

Tache toutesLesTaches = new ArrayList(tachesLundi);
toutesLesTaches.addAll(tachesMardi);

tachesLundi.remove(appelerEric);

List tachesMardiNonAppel = new ArrayList(tachesMardi);
tachesMardiNonAppel.removeAll(tachsAppel);

tachesMardi.contains(appelerMartine);
tachesMardi.containsAll(tachesMardiAppel);
