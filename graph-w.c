// weighted version of graph.c.
// works for 32 bit weights, even a little more if you chage the constants 32 in the code.
// also works for negative weights.
int next(ll x) { return x&((1LL << 32) - 1); }
int weight(ll x) { return x >> 32; }
void tograph_w(ll **g, int *gg, int *x, int *y, int *z, int n, int m)
{
    int i;
    rep(i, n) gg[i] = 1;
    rep(i, m) gg[x[i]]++;
    rep(i, n - 1) gg[i + 1] += gg[i];
    rep(i, n) g[i] = gg + (i == 0 ? 0 : gg[i - 1]) + 1;
    rep(i, n) g[i][-1] = 0;
    rep(i, m) g[x[i]][g[x[i]][-1]++] = (((ll)z[i]) << 32) + y[i];
    //rep(i, n) { ll j; printf("%d: ", i); rep(j, g[i][-1]) printf("%d ", next(g[i][j])); printf("\n"); }
    //rep(i, n) { ll j; printf("%d: ", i); rep(j, g[i][-1]) printf("%d ", weight(g[i][j])); printf("\n"); }
}
