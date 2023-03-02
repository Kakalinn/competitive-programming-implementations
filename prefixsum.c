void init(int *p, int n)
{
    int i;
    rep(i, n) if (i != 0) p[i] += p[i - 1];
}

int query(int *p, int x, int y)
{
    return p[y] - (x == 0 ? 0 : p[x - 1]);
}

