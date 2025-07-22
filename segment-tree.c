// tested: fenwick
// compare time-wise to bfs numbering and test more. this is NEEDED.

// Usage:  init(p, n);
// Before: p is an array of size 4*n (IMPORTANT).
// After:  p is a segment tree with all entries 0.
//
// Usage:  s = query(p, x, y);
// Before: p is a segment tree with n entries.
//         x and y are integers such that 0 <= x <= y < n.
// After:  s is the sum of the x-th, (x + 1)-st, ..., y-th entries in p.
//
// Usage:  update(p, x, y, z);
// Before: p is a segment tree with n entries.
//         x, y, and z are integers such that 0 <= x <= y < n.
// After:  p has been modified such that z has been added to
//         the x-th, (x + 1)-st, ..., y-th entries in p.
//
// Note:   init(p, ...) must be called before p can be used as a segment tree.
//         Both update(...) and query (...) affect inclusive intervals.
//         init(...) runs in O(n) and query(...) and update(...)
//           both run in O(log n).
//         This a very versatile and useful data structure that can handle
//           many different forms of updates and queries.

#define MAXN 100000
#define LEFT(x) ((x) + 1)
#define RIGHT(x, m, i) ((x) + 2*(m - i + 1))

void prop(ll *p, ll x, ll y, ll e)
{
    p[2*e] += (y - x + 1)*p[2*e + 1];
    if (x != y) p[2*LEFT(e) + 1] += p[2*e + 1], p[2*RIGHT(e, (x + y)/2, x) + 1] += p[2*e + 1];
    p[2*e + 1] = 0;
}

ll qrec(ll *p, ll i, ll j, ll x, ll y, ll e)
{
    prop(p, i, j, e);
    if (x == i && y == j) return p[2*e];
    ll m = (i + j)/2;
    if (y <= m) return qrec(p, i, m, x, y, LEFT(e));
    else if (x > m) return qrec(p, m + 1, j, x, y, RIGHT(e, m, i));
    return qrec(p, i, m, x, m, LEFT(e)) + qrec(p, m + 1, j, m + 1, y, RIGHT(e, m, i));
}
ll query(ll *p, ll x, ll y) { return qrec(p, 0, p[0] - 1, x, y, 1); }

void urec(ll *p, ll i, ll j, ll x, ll y, ll z, ll e)
{
    prop(p, i, j, e);
    if (x == i && y == j) { p[2*e + 1] = z; return; }
    ll m = (i + j)/2;
    p[2*e] += (y - x + 1)*z;
    if (y <= m) urec(p, i, m, x, y, z, LEFT(e));
    else if (x > m) urec(p, m + 1, j, x, y, z, RIGHT(e, m, i));
    else urec(p, i, m, x, m, z, LEFT(e)), urec(p, m + 1, j, m + 1, y, z, RIGHT(e, m, i));
}
void update(ll *p, ll x, ll y, ll z) { urec(p, 0, p[0] - 1, x, y, z, 1); }

void init(ll *p, ll n) { irep(i, 4*n) p[i] = i == 0 ? n : 0; }

