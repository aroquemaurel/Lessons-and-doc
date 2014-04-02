public class Personne {
	private String _firstName;
	private String _lastName;

	public Personne(String firstName, String lastName) {
		_firstName = firstName;
		_lastName = lastName;
	}

	public String getFirstName() {
		return _firstName;
	}

	public String getLastName() {
		return _lastName;
	}

	@Override
	public boolean equals(Object o) {
		return o instanceof Personne && 
			_firstName.equals(((Personne)o.getFirstName())) && 
			_lastName.equals(((Personne)o.getLastName()));
	}

	@Override 
	public int hashCode() {
		return _firstName.hashCode() + _lastName.hashCode();
	}
}

