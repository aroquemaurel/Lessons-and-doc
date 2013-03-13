#include "element.h"
#include <stdio.h>
int compare(const Element pElem1, const Element pElem2) {
	if(pElem1.val == pElem2.val) {
		return 0;
	} else if(pElem1.val < pElem2.val) {
		return -1;
	} else {
		return 1;
	}
}

void afficherElement(const Element pElem) {
	printf("%d: %s\n", pElem.val, pElem.nom);
}
