// Fieldtesting: generalchineseremainder (__int128), dvdscreensaver (__int128)
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

ll crt(ll a, ll n, ll b, ll m)
{
	ll x, y, g = egcd(n, m, &x, &y);
	if (llabs(a - b)%g != 0) printf("no solution\n"); //handle this
	else
	{
		y = (n*m)/g;
		x = (((b - a)*x)%y*n)/g + a;
		return (x%y + y)%y;
	}
}
