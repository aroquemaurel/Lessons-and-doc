typedef tab int[3];
tab T;
int j = 2;

void modifier1(int x) {
	j++;
	x= 1;
}

void modifier2 (int *x) {
	j++;
	*x = 1;
}

void modifier3 (tab b) {
	T[0] = b[0] + b[j] + b[2] + b[3] + b[4];
	t[1] = b[0] + b[1] + b[2] + b[3] + b[4];
}

int main(int argc, char** argv) {
	int i;
	for(i=0; i < j; ++i) {
		T[i] = 0;
	}
	modifier1(T[j]); // ... 1
	modifier2(&T[j]) ; // ... 2

	for(i = 0; i < j; ++i) {
		T[i] = 1;
	}
	modifier3(T);

	return 0;
}


