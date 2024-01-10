int find(int *p, int x) { return p[x] < 0 ? x : (p[x] = find(p, p[x])); }
void init(int *p, int n) { int i; rep(i, n) p[i] = -1; }
int size(int *p, int x) { return -p[find(p, x)]; }
int check(int *p, int x, int y) { return find(p, x) == find(p, y); }
void join(int *p, int x, int y)
{
    int rx = find(p, x), ry = find(p, y);
    if (rx == ry) return;
    if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;
    else p[rx] += p[ry], p[ry] = rx;
}
