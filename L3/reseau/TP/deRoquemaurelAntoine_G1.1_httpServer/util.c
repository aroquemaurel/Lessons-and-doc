#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char *trim (char *str) {
	char *ibuf, *obuf;

	if (str) {
		for (ibuf = obuf = str; *ibuf; ) {
			while (*ibuf && (isspace (*ibuf)))
				ibuf++;
			
			if (*ibuf && (obuf != str))
				*(obuf++) = ' ';
			while (*ibuf && (!isspace (*ibuf)))
				*(obuf++) = *(ibuf++);
		}
		*obuf = '\0';
	}
	return (str);
}

char** trimTab(char** s, int nb) {
	int i;

	for(i = 0 ; i <= nb ; ++i) {
		s[i] = trim(s[i]);
	}

	return s;
}

char **str_split(char *s, const char c) {
	int i, j=0, k=1;
	char** ret;
	ret = malloc(sizeof(char*)*256);
	for(i = 0 ; i < 256 ; ++i) {
		ret[i] = malloc(sizeof(char)*256);
	}
	for(i=0 ; i < strlen(s) ; ++i,++k) {
		ret[j][k-1] = s[i];
		if(s[i] == c) {
			ret[j][i] = '\0';
			++j;
			k=0;
		}
	}
	ret[j][i+1] = '\0';
	ret = trimTab(ret, j);
	ret[j+1] = NULL;
	return ret;
}
