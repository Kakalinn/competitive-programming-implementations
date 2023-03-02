int uf_find(int *p, int x) { return p[x] < 0 ? x : (p[x] = uf_find(p, p[x])); }
void uf_init(int n) { int i; rep(i, n) p[i] = -1; }
void uf_size(int x) { return -p[uf_find(x)]; }
void uf_join(int *p, int x, int y)
{
    int rx = uf_find(p, x), ry = uf_find(p, y);
    if (rx == ry) return;
    if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;
    else p[rx] += p[ry], p[ry] = rx;
}
