/* *
 * @param t ms
 * @param f kHz
 */
float moment(char* signal, int k, float t, float f) {
	int ws = (int)(t * f);
	float res = 0;

	for(int i = 0 ; i < ws ; ++i) {
		res += pow(signal[i], k);
	}

	return res/ws;
}
