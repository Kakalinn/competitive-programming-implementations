int get_int()
{
    int r = 0, c = getchar(), s = 1;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    while (c == '-') s *= -1, c = getchar();
    while ('0' <= c && c <= '9') r = r*10 + c - '0', c = getchar();
    return s*r;
}
