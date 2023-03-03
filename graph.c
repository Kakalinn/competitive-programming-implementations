// edges are (x[i], y[i]). for undirected graph two edges must be added.
// n nodes and m edges in directed (m/2 edges in directed).
// gg is a buffer to store the data. must be size m + n, at least.
// the degree of x is g[x][-1].
void tograph(int **g, int *gg, int *x, int *y, int n, int m)
{
    int i;
    rep(i, n) gg[i] = 1;
    rep(i, m) gg[x[i]]++;
    rep(i, n - 1) gg[i + 1] += gg[i];
    rep(i, n) g[i] = gg + (i == 0 ? 0 : gg[i - 1]) + 1;
    rep(i, n) g[i][-1] = 0;
    rep(i, m) g[x[i]][g[x[i]][-1]++] = y[i];
    //rep(i, n) { int j; printf("%d: ", i + 1); rep(j, g[i][-1]) printf("%d ", g[i][j] + 1); printf("\n"); }
}

