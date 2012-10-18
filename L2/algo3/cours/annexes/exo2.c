/*  $(N > 0) \wedge (N >30)$ */
int factorielle (int n) {
	if(0 == n) {
		return (1); // ... 1
	} else {
		int f = n; // ... 2
		while(--n > 0) {
			f *= n; // ... 3
		}
		return f; // ... 4
	}
}
/*  factorielle = n! */
