// field testing: equationsolver, equationsolverplus, arcade, lostinthewoods
//
// O(nm + n^2m)
// If the matrix has rank r it is O(nm + rnm)
int gauss(double* a, int n, int m)
{
	int i, j, k, t, r = 0;
	for (i = 0; i < n; i++)
	{
		t = -1;
		while (++t < m && fabs(a[i*m + t]) < 1e-9);
		if (t == m) continue;
		r++;
		for (j = m - 1; j >= t; j--) a[i*m + j] = a[i*m + j]/a[i*m + t];
		for (j = 0; j < n; j++) if (i != j) for (k = m - 1; k >= t; k--) a[j*m + k] = a[j*m + k] - a[i*m + k]*a[j*m + t];
	}
	return r;
}
