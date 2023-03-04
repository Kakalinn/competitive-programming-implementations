void bellman_ford(ll **g, ll n, ll m, ll s, ll *d)
{
    ll i, j, k, x, w, qe = 0, qs = 0, q[n];
    rep(i, n) d[i] = i == s ? 0 : INF, q[i] = i == s ? 0 : -1;
    rep(i, n - 1) rep(j, n) if (q[j] == i) rep(k, g[j][-1])
    {
        x = next(g[j][k]), w = weight(g[j][k]);
        if (d[j] + w < d[x]) d[x] = d[j] + w, q[x] = i + 1;
    }
    rep(i, n - 1) rep(j, n) if (q[j] == n + i - 1) rep(k, g[j][-1])
    {
        x = next(g[j][k]), w = weight(g[j][k]);
        if (d[x] != -INF && d[j] + w < d[x]) d[x] = -INF, q[x] = n + i;
    }
}
