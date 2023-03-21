// field testing: froshweek, ultraquicksort
ll invnum(ll* a, ll n)
{
    ll t = 0, z = 0, i, j, c, e, l, m, r, b[2][n];
    for (i = 0; i < n; i++) b[t][i] = a[i];
    for (e = 1; e < n; e *= 2, t = 1 - t) for (l = 0; l < n; l += 2*e)
    {
        i = c = l, j = m = min(l + e, n), r = min(l + 2*e, n);
        while (i < m || j < r)
            if (i == m || (j < r && b[t][j] < b[t][i]))
                z += m - i, b[1 - t][c++] = b[t][j++];
            else b[1 - t][c++] = b[t][i++];
    }
    return z;
}
