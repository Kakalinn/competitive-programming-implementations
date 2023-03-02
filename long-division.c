// tested: nnnnn
int long_division(char *x, char *r, ll n)
{
	ll i = 0, f = 0, t = 0;
	while (*x)
	{
		t = t*10 + *x++ - '0';
		if (t/n != 0 || f) r[i++] = t/n + '0', f = 1;
		t = t%n;
	}
	r[i] = '\0';
	return t;
}
