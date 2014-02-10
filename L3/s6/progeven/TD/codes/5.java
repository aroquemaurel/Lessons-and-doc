public class Model extends AbstractTableModel {
	public int getRowCount() {
		return 10;
	}

	public int getColumnCount() {
		return 10;
	}

	public Object getValueAt(int row, int column) {
		return new Integer((row+1)*(column+1));
	}

	public boolean isCellEditable(int rowIndex, int columnIndex) {
		return false;
	}

	public String getColumnName(int column) {
		return super.getColumnName(column+1);
	}
}
