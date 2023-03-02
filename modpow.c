ll modpow(ll x, ll y, ll m) 
{ 
    ll r;
    for (r = 1; y > 0; y = y/2, x = (x*x)%m) if (y&1) r = (r*x)%m;
    return r; 
}
