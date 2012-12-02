/* PE: $\top$ */
x = X;
r = 1;
/* INV: G(X) = r $\oplus$ G(x) */
while (!(N == 0)) {
	r = r *  x;
	N = N - 1;
}
r = r $\oplus$ a;
/* PS: G(X) = r */
