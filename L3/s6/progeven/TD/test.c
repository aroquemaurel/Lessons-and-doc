int main(int argc, char *argv[])
{
	fonction(); //4
	fonction(); //5
	fonction(); //6
}
void fonction() {
	static a = 3;
	++a;
	printf("%d", a);
}

void kamolox() {
	printf("%d", a);
}

void test(int a) {
	printf("%d", a);
}
