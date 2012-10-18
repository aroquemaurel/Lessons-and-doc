int i; 

int f(int a,int b){ 
	i = i + a; 
	
	return (a + b); // 1
} 

int main(int argc, char *argv[]) { 
	int j, x; 

	i = 10; 
	j = 10;  // 2
	x = f(i, j);  // 3
}

