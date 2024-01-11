
// Usage:  x = mex(a, n);
// Before: n >= 0 is an integer and a is an array of size n.
//         No entry in a is smaller than 0.
// After:  x >= 0 is the smallest excluded number of a.
//         That is, it is the smallest natural number that
//         is not in a.
//
// Note:   It runs in O(n).

int mex(int* a, int n)
{
    int b[n], i;
    rep(i, n) b[i] = 0;
    rep(i, n) if (a[i] < n) b[a[i]] = 1;
    rep(i, n) if (!b[i]) break;
    return i;
}

