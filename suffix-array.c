// something is NEEDED (testing? clear bounds?)
void suffix_array(char* s, int n, int* p)
{ // Eftir er |p| suffix array.  Fylkid |p| tharf ad vera med |n| + 1 stak.
    s[n] = ' ' - 1, s[n + 1] = '\0'; n++;
    int i, k = 1, a = 256, h;
    int c[n], g[a], gg[n], pn[n], cn[n];
    rep(i, a) g[i] = 0;
    rep(i, n) g[s[i]]++;
    rep(i, a) if (i != 0) g[i] += g[i - 1];
    rep(i, n) p[--g[s[i]]] = i;
    c[p[0]] = 0;
    rep(i, n - 1) c[p[i + 1]] = (s[p[i + 1]] != s[p[i]] ? ++k : k) - 1;
    for (h = 0; (1 << h) < n; h++)
    {
        rep(i, n) pn[i] = p[i] - (1 << h), pn[i] += pn[i] < 0 ? n : 0;
        rep(i, k) gg[i] = 0;
        rep(i, n) gg[c[pn[i]]]++;
        rep(i, k - 1) gg[i + 1] += gg[i];
        rep(i, n) p[--gg[c[pn[n - 1 - i]]]] = pn[n - 1 - i];
        cn[p[0]] = 0;
        k = 1;
        rep(i, n - 1) cn[p[i + 1]] = (c[p[i + 1]] != c[p[i]] || c[(p[i + 1] + (1 << h))%n] != c[(p[i] + (1 << h))%n] ? ++k : k) - 1;
        rep(i, n) c[i] = cn[i];
    }
    rep(i, n - 1) p[i] = p[i + 1];
}

void lcp(char* s, int n, int* p, int* l)
{ // Eftir er |l| LCP fylki fyrir suffix fylki |p|.  Fylkid |l| tharf ad vera med |n| - 1 stak.
    int a[n], i, j, k = 0;
    rep(i, n) a[p[i]] = i;
    rep(i, n)
    {
        if (a[i] == n - 1) { k = 0; continue; }
        j = p[a[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        l[a[i]] = k;
        if (k) k--;
    }
}

void repk(char* s, int n, int* p, int* l, int k)
{ // Prentar alla endurteknu hlutstrengi af lengd |k|.
    if (k == 0) return;
    int i, j = 1;
    rep(i, n - 1)
    {
        if (j && l[i] >= k) 
        {
            rep(j, k) printf("%c", s[p[i] + j]);
            printf("\n");
            j = 0;
        }
        else if (l[i] < k) j = 1;
    }
}
