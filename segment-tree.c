// compare, time-wise, to bfs numbering and test more. this is NEEDED.
#define MAXN 1000000
#define LEFT(x) ((x) + 1)
#define RIGHT(x, m, i) ((x) + 2*(m - i + 1))
int p[2*MAXN], o[2*MAXN];

void prop(int x, int y, int e)
{
    p[e] += (y - x + 1)*o[e];
    if (x != y) o[LEFT(e)] += o[e], o[RIGHT(e, (x + y)/2, x)] += o[e];
    o[e] = 0;
}

int qrec(int i, int j, int x, int y, int e)
{
    prop(i, j, e);
    if (x == i && y == j) return p[e];
    int m = (i + j)/2;
    if (y <= m) return qrec(i, m, x, y, LEFT(e));
    else if (x > m) return qrec(m + 1, j, x, y, RIGHT(e, m, i));
    return qrec(i, m, x, m, LEFT(e)) + qrec(m + 1, j, m + 1, y, RIGHT(e, m, i));
}
int query(int x, int y) { return qrec(0, p[0] - 1, x, y, 1); }

void urec(int i, int j, int x, int y, int z, int e)
{
    prop(i, j, e);
    if (x == i && y == j) { o[e] = z; return; }
    int m = (i + j)/2;
    p[e] += (y - x + 1)*z;
    if (y <= m) urec(i, m, x, y, z, LEFT(e));
    else if (x > m) urec(m + 1, j, x, y, z, RIGHT(e, m, i));
    else urec(i, m, x, m, z, LEFT(e)), urec(m + 1, j, m + 1, y, z, RIGHT(e, m, i));
}
void update(int x, int y, int z) { urec(0, p[0] - 1, x, y, z, 1); }

void init(int n)
{
    int i;
    rep(i, 2*n) p[i] = o[i] = 0;
    p[0] = n;
}
