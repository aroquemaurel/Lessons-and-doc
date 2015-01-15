int* mean(int* signal, int ws, int size, int* rsize) {
	int* res = malloc(*rsize * sizeof(int));
	*rsize = size/ws;

	for(int i = 0 ; i < *rsize ; ++i) {
		res[i] = 0;
		for(int j = 0 ; j < *rsize ; ++j) {
			res[i] += *(++signal);
			res[i] /= ws;
		}
	}

	return res;
}
