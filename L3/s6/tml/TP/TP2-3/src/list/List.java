package list;

public class List {
	private Cell _head;

	public List(int... data) {
		for(int d : data) {
			add(d);
		}
	}
	
	public void add(int data) {
		Cell current = _head;
		Cell previous = null;
		Cell newCell;
		boolean notEnd = current != null;
		
		while(notEnd && current != null) {
			if(current.getData() > data) {
				notEnd = false;
			} else {
				previous = current;
				current = current.getNext();
			}
		}
		newCell = new Cell(data, current);

		if(previous == null) {
			_head = newCell;
		} else {
			previous.setNext(newCell);
		}
	}
	
	@Override
	public String toString() {
		Cell current = _head;
		String ret = "";
		while(current != null) {
			ret += current.getData()+", "; 
			current = current.getNext();
		}
		
		return ret;
	}
}


