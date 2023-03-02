// empty heap is -1. seems to be faster than random heap.
// traderoutes
int pheapc = 0;
typedef struct { int v, lch, sib; } pheap; pheap pheaps[MAXN];

int pheap_init(int v)
{
	pheaps[pheapc].v = v, pheaps[pheapc].lch = pheaps[pheapc].sib = - 1;
	return pheapc++;
}

int pheap_merge(int x, int y)
{
	if (x == -1 || y == -1) return x == -1 ? y : x;
	if (b[pheaps[x].v] > b[pheaps[y].v]) { int s = x; x = y; y = s; }
	if (pheaps[x].lch == -1) pheaps[x].lch = y;
	else pheaps[y].sib = pheaps[x].lch, pheaps[x].lch = y;
	return x;
}

int pheap_twopass(int x)
{
	if (x == -1 || pheaps[x].sib == -1) return x;
	int y = pheaps[x].sib, z = pheaps[pheaps[x].sib].sib;
	pheaps[x].sib = pheaps[y].sib = -1;
	return pheap_merge(pheap_merge(x, y), pheap_twopass(z));
}

int pheap_peek(int x) { return pheaps[x].v; }
int pheap_push(int x, int v) { return pheap_merge(x, pheap_init(v)); }
int pheap_pop(int x) { return pheap_twopass(pheaps[x].lch); }
