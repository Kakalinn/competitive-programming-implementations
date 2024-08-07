// tested: woodcutting, massivecardgame, magicsequences

// Usage:  sort(a, n);
// Before: n >= 0 is an integer and a is an array of size n.
//         All elements of a must be positive.
// After:  a is sorted in increasing order.
//
// Note:   If all entries in a are smaller than M then it runs
//           in O((n + 2^BASE)*log M). Although this looks
//           worse than the standard O(n log n), the constant
//           is better, because the bases of the logarithm are
//           different (BASE and 2, repsectively). Effectively,
//           it is preforming log_BASE M counting sorts. So
//           if M <= BASE, then the time complexity
//           is O(n + BASE).
//         More testing is NEEDED for different values of BASE.
//         Note that no divisions are performed.

#define BASE 16
#define GET(E, F) (((E) >> ((F)*BASE))&m)
void sort(int *a, int n)
{
    int i, e, m = (1 << BASE) - 1, b[2][n], c[1 << BASE], mx = 0;
    rep(i, n) mx = mx < (b[0][i] = a[i]) ? a[i] : mx;
    for (e = 0; mx; mx >>= BASE, e++)
    {
        rep(i, 1 << BASE) c[i] = 0;
        rep(i, n) c[GET(b[e&1][i], e)]++;
        rep(i, (1 << BASE) - 1) c[i + 1] += c[i];
        per(i, n) b[(~e)&1][--c[GET(b[e&1][i], e)]] = b[e&1][i];
    }
    rep(i, n) a[i] = b[e&1][i];
}
