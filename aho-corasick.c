// TESTING NEEDED
#define ALPHABET 96
#define MAXN 200000
typedef struct { int v, n; } listnode;
typedef struct { int t[ALPHABET], g[ALPHABET], l, e, p, c, d; } trienode;
typedef struct { int s, r, l; trienode m[MAXN]; listnode w[MAXN];} trie;
int val(char c) { return c - ' '; }
int list_node(trie *t, int v, int n)
{
	t->w[t->l].v = v,
		t->w[t->l].n = n;
	return t->l++;
}
int trie_node(trie *t, int p, int c)
{
	int i;
	memset(t->m[t->s].t, -1, sizeof t->m[t->s].t);
	memset(t->m[t->s].g, -1, sizeof t->m[t->s].g);
	//rep(i, ALPHABET) t->m[t->s].t[i] = t->m[t->s].g[i] = -1;
	t->m[t->s].l = -1, t->m[t->s].e = -1, t->m[t->s].p = p,
		t->m[t->s].c = c, t->m[t->s].d = -1;
	return t->s++;
}
void trie_init(trie *t) { t->s = t->l = 0, t->r = trie_node(t, -1, -1); }

void trie_insert(trie *t, char *s, int x)
{
	int h;
	for (h = t->r; *s; h = t->m[h].t[val(*s++)])
		if (t->m[h].t[val(*s)] == -1)
			t->m[h].t[val(*s)] = trie_node(t, h, val(*s));
	t->m[h].l = list_node(t, x, t->m[h].l);
}

int trie_step(trie*, int, int);
int trie_suffix(trie *t, int h)
{ // dp-lookup hjálparfall fyrir suffix link
	if (t->m[h].d != -1) return t->m[h].d;
	if (h == t->r || t->m[h].p == t->r) return t->m[h].d = t->r;
	return t->m[h].d = trie_step(t, trie_suffix(t, t->m[h].p), t->m[h].c);
}

int trie_step(trie *t, int h, int c)
{ // dp-lookup hjálparfall til að ítra
	if (t->m[h].g[c] != -1) return t->m[h].g[c];
	if (t->m[h].t[c] != -1) return t->m[h].g[c] = t->m[h].t[c];
	return t->m[h].g[c] = h == t->r ? t->r : trie_step(t, trie_suffix(t, h), c);
}

int trie_exit(trie *t, int h)
{ // dp-lookup hjálparfall fyrir exit link
	if (t->m[h].e != -1) return t->m[h].e;
	if (h == 0 || t->m[h].l != -1) return t->m[h].e = h;
	return t->m[h].e = trie_exit(t, trie_suffix(t, h));
}

ll topar(ll x, ll y) { return (x << 32) + y; }
ll first(ll x) { return x >> 32; }
ll second(ll x) { return x&((1LL << 32) - 1); }

trie t; // global svo það keyri locally.
#define MAXM 480000
int aho_corasick(char *s, char **p, int m, ll *r)
{
	trie_init(&t);
	int h, i, j, k, w, l[m];
	rep(i, m) l[i] = strlen(p[i]);
	rep(i, m) trie_insert(&t, p[i], i);
	for (i = 0, j = 0, h = t.r; ; j++)
	{
		k = trie_exit(&t, h);
		while (t.m[k].l != -1)
		{
			for (w = t.m[k].l; w != -1; w = t.w[w].n)
				r[i++] = topar(t.w[w].v, j - l[t.w[w].v]);
			k = trie_exit(&t, trie_suffix(&t, k));
		}
		h = trie_step(&t, h, val(*s));
		if (*s++ == '\0') break;
	}
	return i;
}
