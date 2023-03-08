void bellman_ford(ll **g, int n, int m, int s, int *d)
{
    int i, j, k, x, w, q[n], f = 1;
    rep(i, n) d[i] = i == s ? 0 : INF, q[i] = i == s ? 0 : -1;
    for (i = 0; f; i++) for (j = f = 0; j < n; j++) if (q[j] == i) rep(k, g[j][-1])
    {
        x = next(g[j][k]), w = weight(g[j][k]);
        if (d[x] != -INF && d[j] + w < d[x]) d[x] = i < n ? d[j] + w : -INF, q[x] = i + 1, f = 1;
    }
}
