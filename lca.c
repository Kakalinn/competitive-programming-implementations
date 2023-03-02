typedef struct { int n, *g[MAXN], tl[2*MAXN], t[2*MAXN - 1][22], l[MAXN], d[MAXN], p[MAXN], ee; } lca;
int lca_op(lca* a, int x, int y) { return a->d[x] < a->d[y] ? x : y; }
int lca_dfs(lca* a, int x, int p)
{
	int i;
	a->d[x] = (p == -1 ? 0 : a->d[p] + 1), a->l[x] = a->ee, a->t[a->ee++][0] = x, a->p[x] = p;
	rep(i, a->g[x][-1]) if (a->g[x][i] != p) lca_dfs(a, a->g[x][i], x), a->t[a->ee++][0] = x;
}

void lca_init(lca* a, int **g, int n)
{
	int i, j;
	a->n = n, a->ee = 0, a->tl[0] = -1;
	rep(i, a->n) a->g[i] = g[i];
	lca_dfs(a, 0, -1);
	rep(i, a->ee + 1) if (i != 0) a->tl[i] = a->tl[i/2] + 1;
	rep(j, a->tl[a->ee]) rep(i, a->ee - (1 << (j + 1)) + 1) a->t[i][j + 1] = lca_op(a, a->t[i][j], a->t[i + (1 << j)][j]);
}

int lca_query(lca *a, int u, int v)
{
	int x = min(a->l[u], a->l[v]), y = max(a->l[u], a->l[v]);
	return lca_op(a, a->t[x][a->tl[y - x + 1]], a->t[y - (1 << a->tl[y - x + 1]) + 1][a->tl[y - x + 1]]);
}
