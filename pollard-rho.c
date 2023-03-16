typedef __int128 lll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll bigprod(ll x, ll y, ll m) { return ((lll)x*y)%m; }
ll modpow(ll x, ll y, ll m) 
{ 
    ll r;
    for (r = 1; y > 0; y = y/2, x = bigprod(x, x, m)) if (y&1) r = bigprod(r, x, m);
    return r; 
}

ll miller_rabin(ll n)
{
    if (n%2 == 0) return n == 2;
    if (n <= 3) return n == 3;
    ll i, k, s = 0, d = n - 1, t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    while (d%2 == 0) d /= 2, s++;
    rep(k, 12) if (t[k] <= n - 2)
    {
        ll a = t[k];
        ll x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        rep(i, s - 1) if ((x = bigprod(x, x, n)) == n - 1) break;
        if (i == s - 1) return 0;
    }
    return 1;
}

ll rho(ll n)
{
    ll s[8] = {2, 3, 4, 5, 7, 11, 13, 1031}, i, j, a, x, y, d;
    for (a = 1;; a++) rep(j, 8)
    {
        x = y = s[j], d = 1;
        while (d == 1)
        {
            x = (bigprod(x, x, n) + a)%n;
            y = (bigprod(y, y, n) + a)%n;
            y = (bigprod(y, y, n) + a)%n;
            d = gcd(llabs(x - y), n);
        }
        if (d != n) return d;
    }
}

ll pollard_rho(ll n, ll *a)
{ // thattar |n| með rho(...) og setur thaettina i |a| og skilar fjölda
    ll i, s[200], ss = 0, c = 0, p[6] = {2, 3, 5, 7, 11, 13};
    rep(i, 6) while (n%p[i] == 0) n /= p[i], a[c++] = p[i];
    s[ss++] = n;
    if (n == 1) return c;
    while (ss > 0)
    {
        ll k = s[--ss];
        if (miller_rabin(k)) a[c++] = k;
        else
        {
            ll r = rho(k);
            s[ss++] = r;
            s[ss++] = k/r;
        }
    }
    return c;
}
