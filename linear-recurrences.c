// testing is NEEDED (euler-258 sammaeining)

// Usage:  x = linerec(a, c, n, l);
// Before: a and c are arrays of length l and n is an integer.
// After:  x is the n-th element of the recurrence given by
//           a_k = sum_{j = 1}^l a_{k - j}c_{l - j}.
//
// Note:   The time complexity is O(k^2 log n).
//           This is better than matrix exponantiation.
//         There is not a consensus of which order c should be given.
//           Here it is such that the next term is given by a
//           standard inner product. So if a = c = (1, 2) then
//           the next term in the concurrence is 5.
//         The recurrence is zero indexed. Don't get lost in the flood.

void mul(ll *a, ll *b, ll *c, ll *t, ll n)
{
    irep(i, 2*n) t[i] = 0; 
    irep(i, n) irep(j, n) t[i + j] = (t[i + j] + (a[i]*b[j])%MOD)%MOD;
    iper(i, n - 1) irep(j, n)
        t[i + n - j - 1] = (t[i + n - j - 1] + (t[i + n]*c[n - 1 - j])%MOD)%MOD;
    irep(i, n) a[i] = t[i];
}

ll linrec(ll *a, ll *c, ll n, ll l)
{ // Computes a_n for the recurrence a_k = sum_{j = 1}^l a_{k - j}c_j.
    ll x[l], r[l], t[2*l], i, z = 0;
    rep(i, l) x[i] = i == 1, r[i] = i == 0;
    for (; n; mul(x, x, c, t, l), n /= 2) if (n%2) mul(r, x, c, t, l);
    rep(i, l) z = (z + (a[i]*r[i])%MOD)%MOD;
    return (z + MOD)%MOD;
}
