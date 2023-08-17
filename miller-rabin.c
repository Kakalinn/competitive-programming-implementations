ll bigprod(ll x, ll y, ll m) { return ((__int128)x*y)%m; }
ll modpow(ll x, ll y, ll m) 
{ 
    ll r;
    for (r = 1; y > 0; y = y/2, x = bigprod(x, x, m)) if (y&1) r = bigprod(r, x, m);
    return r; 
}

int miller_rabin(ll n)
{
    if (n%2 == 0) return n == 2;
    if (n <= 3) return n == 3;
    ll a, x, i, k, s = 0, d = n - 1, t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    while (d%2 == 0) d /= 2, s++;
    rep(k, 12) if (t[k] <= n - 2)
    {
        a = t[k], x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        rep(i, s - 1) if ((x = bigprod(x, x, n)) == n - 1) break;
        if (i == s - 1) return 0;
    }
    return 1;
}




