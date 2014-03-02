Deque<Tache> fileDeTaches = new ArrayDeque<>();
fileDeTaches.offer(appelerEric);
fileDeTaches.offer(appelerMartine);

System.out.println("La tache suivante est : "+fileDeTaches.poll() + 
		" est traité");
System.out.println("La tache suivante est : "+fileDeTaches.peek());
System.out.println("La tache suivante est : "+fileDeTaches.remove() +
		"est traité");
