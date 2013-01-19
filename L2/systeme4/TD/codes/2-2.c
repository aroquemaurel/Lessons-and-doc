#define _POSIX_C_SOURCE 1

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	if(argv != 1 || !(strlen(argv[1]))) {
		return 1;
	}

	printf("%s = %s\n", argv[1], getenv(argv[1]));
}
