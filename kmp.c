// testing: juggling

void prefix_function(char *a, int *b)
{
    int i, j, m = strlen(a);
    for (i = 0, j = b[0] = -1; i < m; b[++i] = ++j)
        while (j >= 0 && a[i] != a[j]) j = b[j];
}

int kmp(char *s, char *p)
{
    int i, j, k = 0, n = strlen(s), m = strlen(p), b[n + m + 2];
    char a[n + m + 2];
    strcpy(a, p), strcat(a, "\n"), strcat(a, s);
    prefix_function(a, b);
    for (i = 0; i < n; i++) k += (i < n - m + 1 && b[i + 2*m + 1] >= m);
    return k;
}

int is_cyclic(char *t)
{
    int n = strlen(t);
    char s[2*n + 1];
    strcpy(s, t), strcat(s + n, t);
    return kmp(s, t) > 2;
}
