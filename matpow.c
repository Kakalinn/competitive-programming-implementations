// comparing to linear currence version NEEDED
// field testing macarons tritiling
#define MOD 1000000000
void matpow(ll* a, ll y, ll n)
{
	ll i, j, k, r[n][n], x[n][n], t[n][n];
	rep(i, n) rep(j, n) r[i][j] = i == j ? 1 : 0;
	rep(i, n*n) x[i/n][i%n] = a[i];
	while (y > 0)
	{
		if (y%2 == 1)
		{
			rep(i, n) rep(j, n) t[i][j] = 0;
			rep(i, n) rep(j, n) rep(k, n) t[i][j] = (t[i][j] + (r[i][k]*x[k][j])%MOD)%MOD;
			rep(i, n) rep(j, n) r[i][j] = t[i][j];
		}
		y /= 2;
		rep(i, n) rep(j, n) t[i][j] = 0;
		rep(i, n) rep(j, n) rep(k, n) t[i][j] = (t[i][j] + (x[i][k]*x[k][j])%MOD)%MOD;
		rep(i, n) rep(j, n) x[i][j] = t[i][j];
	}
	rep(i, n*n) a[i] = r[i/n][i%n];
}
