ll sum(ll *a, ll i)
{ // [0, i]
    ll r = 0;
    for (i++; i > 0; i -= (i&-i)) r += a[i];
    return r;
}

void add(ll *a, ll i, ll k) { for (i++; i <= a[0]; i += (i&-i)) a[i] += k; }
void init(ll *a, ll n) { irep(i, n + 1) a[i] = i == 0 ? n : 0; }
