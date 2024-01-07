#define MAXN 1000001
#define ALPHABET 26
typedef struct { int t[ALPHABET], v; } trienode;
typedef struct { int s, r; trienode m[MAXN]; } trie;
int trie_node(trie *t, int v)
{
    int i;
    rep(i, ALPHABET) t->m[t->s].t[i] = -1;
    t->m[t->s].v = v;
    return t->s++;
}
void trie_init(trie *t) { t->s = 0, t->r = trie_node(t, 0); }
int val(char c) { return c - 'A'; }

void trie_insert(trie *t, char *s)
{
    int h = t->r;
    while (1)
    {
        t->m[h].v++;
        if (*s == '\0') break;
        if (t->m[h].t[val(*s)] == -1) t->m[h].t[val(*s)] = trie_node(t, 0);
        h = t->m[h].t[val(*s)], s++;
    }
}
