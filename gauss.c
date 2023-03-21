// field testing: equationsolver, equationsolverplus, arcade, lostinthewoods
// retesting NEEDED
//
// O(nm + n^2m)
// If the matrix has rank r it is O(nm + rnm)
int gauss(double* a, int s, int n, int m)
{
    int i, j, k, t, r = 0;
    for (i = 0; i < n; i++)
    {
        for (t = 0; t < s && fabs(a[i*m + t]) < 1e-9; t++);
        if (t == s) continue;
        for (r++, j = m - 1; j >= t; j--) a[i*m + j] = a[i*m + j]/a[i*m + t];
        for (j = 0; j < n; j++) if (i != j) for (k = m - 1; k >= t; k--) a[j*m + k] = a[j*m + k] - a[i*m + k]*a[j*m + t];
    }
    return r;
}
