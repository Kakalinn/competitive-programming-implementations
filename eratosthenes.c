// further testing is NEEDED
#define MAXN 100001
int e[MAXN], p[MAXN];
void eratosthenes()
{
    int i, j;
    rep(i, MAXN) e[i] = 1;
    p[0] = e[0] = e[1] = 0;
    rep(i, MAXN) if (e[i]) for (p[++p[0]] = i, j = i*i; j < MAXN; j += i) e[j] = 0;
}
