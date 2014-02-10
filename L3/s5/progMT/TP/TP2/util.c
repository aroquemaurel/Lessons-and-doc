int util_searchFirstOccurenceInArray(char** pArray, const int pSize, char* pSearch) {
	int position=0;

	while(position < pSize -1 && strcmp(pArray[position], pSearch) != 0 ) {
		++position;
	}

	return (position == pSize-1 && strcmp(pArray[position], pSearch) != 0) ? -1 : position;
}
