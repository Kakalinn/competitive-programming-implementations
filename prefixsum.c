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

void init(int *p, int n) { irep(i, n) if (i != 0) p[i] += p[i - 1]; }
void update(int *p, int x, int z) { irep(i, x + 1) p[i] += z; }
int query(int *p, int x, int y) { return p[y] - (x == 0 ? 0 : p[x - 1]); }

