void floyd_warshall(ll **g, ll n, ll d[n][n])
{
    ll i, j, k;
    rep(i, n) rep(j, n) d[i][j] = INF;
    rep(i, n) d[i][i] = 0;
    rep(i, n) rep(j, g[i][-1]) d[i][next(g[i][j])] = min(weight(g[i][j]), d[i][next(g[i][j])]);
    rep(k, n) rep(i, n) rep(j, n)
    {
        if (d[i][k] == INF || d[k][j] == INF) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    rep(k, n) rep(i, n) rep(j, n)
    {
        if (d[i][k] == INF || d[k][j] == INF) continue;
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = -INF;
    }
}
