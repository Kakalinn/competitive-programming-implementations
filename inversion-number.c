// field testing: froshweek, ultraquicksort

// Usage:  x = invnum(a, n);
// Before: a in an array of length n.
// Usage:  x is the inversion number of a.
// Note:   The "inversion number" of a is the number
//           of adjacent swaps needed to sort a.
//         It runs in O(n log n).
//         It is fast for large n (less than 1s. for n = 10^6),
//           but the answer grows like n^2, so it will overflow
//           32 bits.

int invnum(int* a, int n)
{
    int t = 0, z = 0, i, j, c, e, l, m, r, b[2][n];
    rep(i, n) b[t][i] = a[i];
    for (e = 1; e < n; e *= 2, t = 1 - t) for (l = 0; l < n; l += 2*e)
    {
        i = c = l, j = m = min(l + e, n), r = min(l + 2*e, n);
        while (i < m || j < r)
            if (i == m || (j < r && b[t][j] < b[t][i]))
                z += m - i, b[1 - t][c++] = b[t][j++];
            else b[1 - t][c++] = b[t][i++];
    }
    return z;
}
