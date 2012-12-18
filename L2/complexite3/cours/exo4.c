int y;

int f(int x) ;

int main(int argc, char *argv[]) {
	int i, z;
	y = 10;
	i = 1; //...2
	z = f(i) + y; //...3

	return z;
}

int f(int x) {
	int t = x;

	++y;
	++t;

	return (t+y); //...1
}

