package list;

class Cell {
	private int _data;
	private Cell _previous;
	private Cell _next;
	
	public Cell(int data, Cell next) {
		_data = data;
		_previous = null;
		_next = next;
	}

	public int getData() {
		return _data;
	}

	public Cell getNext() {
		return _next;
	}

	public void setNext(Cell _next) {
		this._next = _next;
	}
}
