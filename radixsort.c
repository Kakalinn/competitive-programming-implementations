// tested: woodcutting, massivecardgame, magicsequences
#define BASE 16
#define GET(E, F) (((E) >> ((F)*BASE))&m)
void sort(int *a, int n)
{
    int i, e, q = 0, mx = 0, b[2][n], c[1 << BASE], m = (1 << BASE) - 1;
    rep(i, n) mx = mx < a[i] ? a[i] : mx;
    while (mx > 0) mx >>= BASE, q++;
    rep(i, n) b[0][i] = a[i];
    for (e = 0; q > 0; q--, e++)
    {
        rep(i, 1 << BASE) c[i] = 0;
        rep(i, n) c[GET(b[e&1][i], e)]++;
        rep(i, (1 << BASE) - 1) c[i + 1] += c[i];
        per(i, n) b[(~e)&1][--c[GET(b[e&1][i], e)]] = b[e&1][i];
    }
    rep(i, n) a[i] = b[e&1][i];
}
