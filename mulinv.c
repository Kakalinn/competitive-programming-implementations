ll egcd(ll a, ll b, ll* c, ll* d)
{
    ll s = 0, os = 1, t = 1, ot = 0, r = b, or = a;
    while (r != 0)
    {
        ll q = or/r, m;
        m = r, r = or - q*m, or = m;
        m = s, s = os - q*m, os = m;
        m = t, t = ot - q*m, ot = m;
    }
    *c = os, *d = ot;
    return or;
}

ll mulinv(ll a, ll m)
{
    ll k1, k2;
    egcd(a, m, &k1, &k2);
    return (k1 + m)%m;
}
