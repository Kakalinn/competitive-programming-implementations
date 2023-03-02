int split(char *s, char *t, char **a)
{
    int i, n = 0, m[128];
    char *p;
    rep(i, 128) m[i] = 0;
    if (t) while (*t) m[*t++] = 1;
    else m['\n'] = 1, m['\t'] = 1, m['\r'] = 1, m[' '] = 1;
    if (!m[*s]) a[n++] = s++;
    for (p = s; *p; p++) if (!m[*p] && m[*(p - 1)]) a[n++] = p;
    for (p = s; *p; p++) if (m[*p] && !m[*(p - 1)]) *p = '\0';
    return n;
}

