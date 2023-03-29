int f[MAXN], d[MAXN], p[MAXN];

void hld_init(int **g, int n)
{
    int i, j, k = n, qs = 0, qe = 0, a[n], s[n], h[n];
    rep(i, n) s[i] = 1, f[i] = i, p[i] = 0, d[i] = g[i][-1] + (i == 0);
    rep(i, n) if (d[i] == 1) h[qe++] = a[--k] = i;                                                  // Determine a topoligcal sorting.
    for (i = h[qs++]; qs <= qe; i = h[qs++])
        rep(j, g[i][-1]) if (--d[g[i][j]] == 1) h[qe++] = g[i][j], a[--k] = g[i][j];
    rep(i, n) d[i] = (i == 0 ? 0 : -1), h[i] = -1;
    rep(i, n) rep(j, g[a[i]][-1]) if (d[g[a[i]][j]] == -1) d[g[a[i]][j]] = d[a[i]] + 1;             // Compute the depths.
    rep(i, n) rep(j, g[i][-1]) if (d[i] == d[g[i][j]] + 1) p[i] = g[i][j];                          // Computing the parents.
    per(i, n) if (i != 0) s[p[a[i]]] += s[a[i]];                                                    // Compute the subtree sizes.
    rep(i, n) if (i != 0) h[p[i]] = i;                                                              // Assign some edges as heavy edges.
    rep(i, n) if (i != 0) h[p[i]] = s[h[p[i]]] < s[i] ? i : h[p[i]];                                // Determine the correct heavy edges.
    rep(i, n) if (h[a[i]] != -1) f[h[a[i]]] = f[a[i]];                                              // Assigning the heavy paths.
}

int hld_lca(int u, int v)
{
    while (f[u] != f[v]) (d[f[u]] > d[f[v]]) ? (u = p[f[u]]) : (v = p[f[v]]);
    return d[u] < d[v] ? u : v;
}
