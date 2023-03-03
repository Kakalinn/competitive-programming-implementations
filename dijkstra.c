typedef struct { ll x, y; } par;
par topar(ll x, ll y) { par r = {x, y}; return r; }
void swap(par* x, par* y) { par t = *x; *x = *y; *y = t; }
void pop(par *h)
{
    h[1] = h[h[0].x--];
    for (ll i = 1, mx = i; ; swap(&h[i], &h[mx]), i = mx)
    {
        if (i*2 + 1 <= h[0].x && h[mx].x > h[i*2 + 1].x) mx = i*2 + 1;
        if (i*2 <= h[0].x && h[mx].x > h[i*2].x) mx = i*2;
        if (i == mx) return;
    }
}

void push(par *h, par x)
{
    h[++h[0].x] = x;
    for (ll i = h[0].x; i > 1 && h[i].x < h[i/2].x; i /= 2)
        swap(&h[i], &h[i/2]);
}

par peek(par *h) { return h[1]; }
ll size(par *h) { return h[0].x; }
void init(par *h) { h[0].x = 0; }

void dijkstra(ll **g, ll n, ll m, ll s, ll *d)
{
    ll i, x, w;
    par q[n + m + 1];
    rep(i, n) d[i] = INF;
    init(q);
    push(q, topar(0, s));
    d[s] = 0;
    while (size(q) > 0)
    {
        w = peek(q).x, x = peek(q).y; pop(q);
        if (w > d[x]) continue;
        rep(i, g[x][-1]) if (d[next(g[x][i])] > w + weight(g[x][i]))
        {
            push(q, topar(w + weight(g[x][i]), next(g[x][i])));
            d[next(g[x][i])] = w + weight(g[x][i]);
        }
    }
}
