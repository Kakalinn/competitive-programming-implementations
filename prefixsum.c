// This is entirely untested. Testing is NEEDED.

// Usage:  init(p, n);
// Before: p is an array of length n.
// After:  p is a prefix sum array,
//           and can be used with update(...) and query(...).
//
// Usage:  update(p, x, z);
// Before: p is a prefix sum array of length n.
//         x and z are integers, such that 0 <= x < n.
// After:  z has been added to the x-th element of p.
//
// Usage:  r = query(p, x, y);
// Before: p is a prefix sum array of length n.
//         x and y are integers, such that 0 <= x <= y < n.
// After:  r is the sum of the x-th, (x + 1)-st, ..., y-th entries in p.
//
// Note:   init(...) and update(...) both run in O(n). query(...) runs
//           in O(1).
//         Note that init(...) is only called once so it is allowed to be
//           slow. However, update(...) may be called often, leading to
//           a bad time complexity. This can be remedied by various methods
//           (see segment-tree.c), but is not an issue if there are no
//           updates.

void init(ll *p, ll n) { iper(i, n) p[i + 1] = p[i]; p[0] = n; irep(i, n - 1) p[i + 2] += p[i + 1];}
void update(ll *p, ll x, ll z) { iper(i, p[0] - x) p[x + i + 1] += z; }
ll query(ll *p, ll x, ll y) { return y < x ? 0 : (p[y + 1] - (x == 0 ? 0 : p[x])); }
void set(ll *p, ll x, ll z) { update(p, x, -query(p, x, x)); update(p, x, z); }

