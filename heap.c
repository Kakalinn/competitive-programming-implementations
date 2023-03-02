// further testing NEEDED (maybe with inlined macros)
#define MAXN 100000
#define PARENT(i) ((i)/2)
#define LEFT(i)   ((i)*2)
#define RIGHT(i)  ((i)*2 + 1)
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
void pop(int *h)
{
	h[1] = h[h[0]--];
	for (int i = 1, mx = i; ; swap(&h[i], &h[mx]), i = mx)
	{
		if (RIGHT(i) <= h[0] && h[mx] < h[RIGHT(i)]) mx = RIGHT(i);
		if (LEFT(i) <= h[0] && h[mx] < h[LEFT(i)]) mx = LEFT(i);
		if (i == mx) return;
	}
}

void push(int *h, int x)
{
	h[++h[0]] = x;
	for (int i = h[0]; i > 1 && h[i] > h[PARENT(i)]; i = PARENT(i))
		swap(&h[i], &h[PARENT(i)]);
}

int peek(int *h) { return h[1]; }
int size(int *h) { return h[0]; }
void init(int *h) { h[0] = 0; }
