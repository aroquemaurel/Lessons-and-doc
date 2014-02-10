public class Model extends AbstractTableModel {
	private Object[][] data;
	public int getRowCount() {
		return data.length;;
	}

	public int getColumnCount() {
		return 3;
	}

	public Object getValueAt(int row, int column) {
		return data[row][column];
	}

	publi Object setValueAt(Object aValue, int row, int column) {
		data[row][column] = aValue;
		fireTableCellUpdated(row, column);
	}

	public String getColumnName(int column) {
		String name = "";
		switch(column) {
			case 0: 
				name = "Nom";
				break;
			case 1:
				name = "Prénom";
				break;
			case 2:
				name = "Adress";
				break;
		}

		return name;
	}

	public boolean isCellEditable(int rowindex, int columnindex) {
		return columnIndex >= 2;
	}

}
