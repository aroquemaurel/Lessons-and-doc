boolean isPalindrome(String s) {
	ArrayList<Character> l;
	// l contient les charactères de la String 
	ListIterator iBegin = l.iterator();
	ListIterator iEnd = l.iterator(l.size());
	boolean out = true;

	while(iBegin.hasNext() && iEnd.hasPrevious() && 
			iBegin.nextIndex() <= iEnd.previousIndex() && out) {
		out = iBegin.netx().equals(iEnd.previous());
	}

	return out;
}
