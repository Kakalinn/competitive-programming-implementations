#define MAXN 1000000
#define BITS 8
typedef struct { int t[2], v; } node_t;
typedef struct { int s, r; node_t m[2*BITS*MAXN]; } trie;
int node(trie *t, int v)
{
  irep(i, 2) t->m[t->s].t[i] = -1;
  t->m[t->s].v = v;
  return t->s++;
}
//int val(char c) { return c - 'a'; } // enumerate
//int val(char c) { return c - 'A'; } // enumerate
int val(char c) { return c; } // enumerate

int search(trie *t, char *s)
{
  int h = t->r, i, c;
  for (c = val(*s); *s; c = val(*++s)) for (i = 0; i < BITS; i++, c >>= 1)
  {
    if (t->m[h].t[c&1] == -1) t->m[h].t[c&1] = node(t, 0);
    h = t->m[h].t[c&1];
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
// Note: This is the same as trie.c (3fe2b1b),
//         excpet the strings have been bititized.
//       This means that instead of considering strings in an alphabeta S,
//         we consider the elements of S as their binary representation,
//         for some enumeration of S.
//       This means that,
//         for strings of total length n,
//         we need less than ~2log_2(|S|)n memory.
//       The normal way requires less than ~|S|n.
//       This does, however,
//         add a factor of log(|S|) to all time complexities.
//       This *may* be beneficial for large alphabets,
//         for example all printable ASCII,
//         but it did not help in gestalisti,
//         where the alphabet is the lower case letters.

void init(trie *t) { t->s = 0, t->r = node(t, 0); }
void inc(trie *t, char *s) { t->m[search(t, s)].v++; }
void dec(trie *t, char *s) { t->m[search(t, s)].v--; }
int  cnt(trie *t, char *s) { return t->m[search(t, s)].v; }

