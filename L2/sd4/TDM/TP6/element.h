#ifndef __ELEMENT
#define __ELEMENT
typedef struct elt{
	int val;
	char* nom;
} Element;
int compare(Element pElem1, Element pElement2);
void afficherElement(const Element pElem);
#endif


