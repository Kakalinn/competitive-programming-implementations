
// Usage:  init(p, n);
// Before: n >= 0 is an integer and p is an array of size n.
// After:  p is a uf-array of size n.
//
// Usage:  join(p, x, y);
// Before: p is a uf-array of size n. x and y are integers with 0 <= x, y < n.
// After:  x and y have been transitively joined in p.
//
// Usage:  b = check(p, x, y);
// Before: p is a uf-array of size n. x and y are integers with 0 <= x, y < n.
// After:  b is 1 if x and y have been join in p, directly or indirectly.
//         b is 0 otherwise.
//
// Usage:  s = size(p, x);
// Before: p is a uf-array of size n and x is an integer with 0 <= x < n.
// After:  s is the number of elements in that have been joined, directly
//           or indirectly, with x in p.
//         Note that x is always joined with x, so s > 0.
//
// Note:   The time complexities are complicated and still being argued in
//           the literature. Feel free to treat everything as if it was O(1),
//           amortized, although leading literature says it's a little slower.
//         One way to visualize what's going on (or apply the data structure)
//           is to use graph theory. init(..., n) gives you a graph with n
//           nodes and no edges. join(..., x, y) adds an edge from x to y and
//           check(..., x, y) checks whether x and y are in the same connected
//           component. size(..., x) returns the number of nodes in the same
//           connected component of x.
//         When extending the code you might need to use find(p, x). Roughly,
//           it return a node from the same connected component as x. Crucially,
//           it is constant on connected components for a fixed p.

int find(int *p, int x) { return p[x] < 0 ? x : (p[x] = find(p, p[x])); }
void init(int *p, int n) { irep(i, n) p[i] = -1; }
int size(int *p, int x) { return -p[find(p, x)]; }
int check(int *p, int x, int y) { return find(p, x) == find(p, y); }
void join(int *p, int x, int y)
{
    int rx = find(p, x), ry = find(p, y);
    if (rx == ry) return;
    if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;
    else p[rx] += p[ry], p[ry] = rx;
}
