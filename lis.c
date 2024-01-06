// retesting NEEDED
// field testing trainsorting, manhattanmornings, signals

// Usage:  x = lis(a, b, n);
// Before: a is an array of length n.
// After:  x is the length of the longest incr. suseqs.
//         b is an array that contains an incr. subsec. of a of length x.
// Note:   It runs in O(n log n).

int lis(int *a, int *b, int n)
{
    int i, j, x, y, d[n + 1], e[n];
    for (i = 0; i < n + 1; i++) d[i] = i == 0 ? -INF : INF;
    for (i = 0; i < n; i++)
    {
        int r = -1, s;
        for (s = n + 1; s >= 1; s /= 2)
            while (r + s < n + 1 && d[r + s] < a[i]) r += s;
        d[r + 1] = a[i], e[i] = d[r];
    }
    for (x = n; d[x] == INF; x--);
    for (i = n - 1, j = x - 1, y = d[x]; j >= 0; i--) if (a[i] == y)
        y = e[i], b[j--] = a[i];
    return x;
}
