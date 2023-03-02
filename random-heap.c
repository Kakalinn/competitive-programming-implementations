// empty heap is -1. seems to be slower than pairing heap.
// traderoutes
int rheap_c = 0;
typedef struct { int v, l, r; } rheap; rheap rheaps[MAXN];

int rheap_init(int v)
{
    rheaps[rheap_c].l = rheaps[rheap_c].r = -1, rheaps[rheap_c].v = v;
    return rheap_c++;
}

int rheap_merge(int x, int y)
{
    if (x == -1 || y == -1) return x != -1 ? x : y;
    if (b[rheaps[y].v] < b[rheaps[x].v]) { int s = x; x = y; y = s; }
    if (rand()&1) { int s = rheaps[x].l; rheaps[x].l = rheaps[x].r; rheaps[x].r = s; }
    rheaps[x].l = rheap_merge(rheaps[x].l, y);
    return x;
}
int rheap_push(int x, int v) { return rheap_merge(rheap_init(v), x); }
int rheap_peek(int x) { return rheaps[x].v; }
int rheap_pop(int x) { return rheap_merge(rheaps[x].l, rheaps[x].r); }
