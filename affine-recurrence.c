void multo(ll* a, ll* b, ll n)
{ // Eins og `a *= b`.
    ll i, j, k, c[n][n];
    rep(i, n) rep(j, n) c[i][j] = 0;
    rep(i, n) rep(j, n) rep(k, n) c[i][j] = (c[i][j] + (a[i*n + k]*b[k*n + j])%MOD)%MOD;
    rep(i, n) rep(j, n) a[i*n + j] = c[i][j];
}

void matpow(ll* a, ll p, ll n)
{ // Eins og a = a^p.
    ll r[n][n], i, j;
    rep(i, n) rep(j, n) r[i][j] = 0;
    rep(i, n) r[i][i] = 1;
    for (; p; multo(a, a, n), p /= 2) if (p%2) multo(*r, a, n);
    rep(i, n) rep(j, n) a[i*n + j] = r[i][j];
}

ll linrec(ll* a, ll* c, ll c0, ll k, ll n)
{ // a_N = c0 + c_1*a_{N - 1} + c_2*a_{N - 2} + ... + c_k*a_{N - k}.
    if (n < k) return a[n]%MOD;
    ll i, j, b[k + 1][k + 1], r = 0;
    rep(i, k + 1) rep(j, k + 1) b[i][j] = 0;
    rep(i, k) b[0][i] = c[i]%MOD;
    b[0][k] = c0%MOD, b[k][k] = 1;
    rep(i, k - 1) b[i + 1][i] = 1;
    matpow(*b, n - k + 1, k + 1);
    rep(i, k + 1) r = (r + (b[0][i]*(i != k ? a[k - 1 - i] : 1))%MOD)%MOD;
    return (r + MOD)%MOD;
}
