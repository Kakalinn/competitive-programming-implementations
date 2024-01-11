
// Usage:  init(h);
// Before: h is an array of size n + 1.
// After:  h is an empty heap with capacity n.
//
// Usage:  pop(h);
// Before: h is a non-empty heap.
// After:  The largest element in h has been removed.
//
// Usage:  push(h, x);
// Before: h is a non-full heap.
// After:  x has been added to h.
//
// Usage:  x = peek(h);
// Before: h is a non-empty heap.
// After:  x is the largest element in h.
//
// Usage:  x = size(h);
// Before: h is a heap.
// After:  x is the number of elements in h.
//
// Note:   init(...), peek(...), and size(...) run in O(1).
//         pop(...) and push(...) run in O(log n).

void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
void pop(int *h)
{
    h[1] = h[h[0]--];
    for (int i = 1, mx = i; ; swap(&h[i], &h[mx]), i = mx)
    {
        if (i*2 + 1 <= h[0] && h[mx] < h[i*2 + 1]) mx = i*2 + 1;
        if (i*2 <= h[0] && h[mx] < h[i*2]) mx = i*2;
        if (i == mx) return;
    }
}

void push(int *h, int x)
{
    h[++h[0]] = x;
    for (int i = h[0]; i > 1 && h[i] > h[i/2]; i = i/2)
        swap(&h[i], &h[i/2]);
}

int peek(int *h) { return h[1]; }
int size(int *h) { return h[0]; }
void init(int *h) { h[0] = 0; }
