#define MAXN 100001
int e[MAXN], p[MAXN], pp = 0;
void eratosthenes()
{
	int i, j;
	rep(i, MAXN) e[i] = 1;
	e[0] = e[1] = 0;
	rep(i, MAXN) if (e[i]) { p[pp++] = i; for (j = 2*i; j < MAXN; j += i) e[j] = 0; }
}
