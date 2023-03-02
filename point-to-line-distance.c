// retesting is NEEDED
// blowingcandles
// dist from c to the line through a and b
typedef complex double pt;

double p2l(pt a, pt b, pt c)
{
	return cimag((c - a)*cexp(-carg(b - a)*I));
}
