#define MAXN 1000000
#define ALPHABET 26
typedef struct { int t[ALPHABET], v; } node_t;
typedef struct { int s, r; node_t m[MAXN]; } trie;
int node(trie *t, int v)
{
  irep(i, ALPHABET) t->m[t->s].t[i] = -1;
  t->m[t->s].v = v;
  return t->s++;
}
int val(char c) { return c - 'a'; }

int search(trie *t, char *s)
{
  int h = t->r;
  while (*s != '\0')
  {
    if (t->m[h].t[val(*s)] == -1) t->m[h].t[val(*s)] = node(t, 0);
    h = t->m[h].t[val(*s)], s++;
  }
  return h;
}

   // Usage:  init(t);
  //  Before: t is a pointer to an uninitialized trie.
 //   After:  t is a pointer to an initialized trie.
//
   // Usage:  inc(t, s);
  //  Before: t is a pointer to a trie and s is a (null terminated) string.
 //   After:  s has been added to t.
//
   // Usage:  dec(t, s);
  //  Before: t is a pointer to a trie and s is a (null terminated) string.
 //   After:  s has been removed from t.
//
    // Usage:  x = cnt(t, s);
   //  Before: t is a pointer to a trie and s is a (null terminated) string.
  //   After:  x is an integer
 //              corresponding to how many occurences of s there are in t.
//
// Note: inc(...), dec(...), and cnt(...) are all linear in the length of s.
//       The behaviour is similar to a map
//         where all strings are initially assumed to map to 0.  
//       This means that a string can be decremented before it is incremented,
//         and it's count will then be negative.
//       cnt(...) does not exit early, for simpler implementation.
//       In inc(...), dec(...), and cnt(...)
//         it is assumed the trie is initialized.
//       These function are just an idea of how this can be used.

void init(trie *t) { t->s = 0, t->r = node(t, 0); }
void inc(trie *t, char *s) { t->m[search(t, s)].v++; }
void dec(trie *t, char *s) { t->m[search(t, s)].v--; }
int  cnt(trie *t, char *s) { return t->m[search(t, s)].v; }
