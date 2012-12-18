int i;
int j;

void pr (int *x, int *y, int *z) ;

int main(int argc, char *argv[]) {
	i = 3; 
	j = 7;	// ... 3
	pr(&i, &i, &j); // ... 4

	i = 3;
	j = 7; // ... 5
	pr(&j, &j, &i); /// ...6
}

void pr (int *x, int *y, int *z) {
	*y = i + *x; // ... 1
	*z = *x + *y; // ... 2
}

