ll amin(ll *t, ll x, ll y) { return t[x + 2*t[0]] < t[y + 2*t[0]] ? x : y; }
void update(ll *t, ll p, ll w)
{
    for (t[p + 2*t[0]] = w, p += t[0]; p > 1; p >>= 1) t[p >> 1] = amin(t, t[p], t[p^1]);
}

void init(ll *t, ll n)
{
    for (ll i = 0; i < (t[0] = n); i++) t[i + 2*t[0]] = INF;
    for (ll i = 2*t[0] - 1; i > 0; i--) t[i] = i < t[0] ? amin(t, t[i << 1], t[i << 1|1]) : i - t[0];
}

void dijkstra(ll **g, ll n, ll m, ll s, ll *d)
{
    ll i, x, w, q[3*n];
    rep(i, n) d[i] = (i == s ? 0 : INF);
    init(q, n);
    update(q, s, 0);
    while (q[q[1] + 2*n] < INF)
    {
        x = q[1], w = d[x];
        update(q, x, INF);
        rep(i, g[x][-1]) if (d[next(g[x][i])] > w + weight(g[x][i]))
        {
            d[next(g[x][i])] = w + weight(g[x][i]);
            update(q, next(g[x][i]), d[next(g[x][i])]);
        }
    }
}
