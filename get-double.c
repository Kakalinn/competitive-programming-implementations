double get_double()
{
    double ret = 0;
    char c = getchar();
    int sgn;

    while (1)
    {
        if (c == EOF) return EOF;
        if (c >= '0' && c <= '9') { sgn = 1; break; }
        if (c == '-')
        {
            c = getchar();
            if (c < '0' || c > '9') continue;
            sgn = -1;
            break;
        }
        c = getchar();
    }

    while (1)
    {
        ret = ret*10 + c - '0';
        c = getchar();
        if (c == '.')
        {
            double pos = 0.1;
            c = getchar();
            while (c >= '0' && c <= '9')
            {
                ret += pos*(c - '0');
                pos /= 10;
                c = getchar();
            }
            return sgn*ret;
        }
        else if (c < '0' || c > '9') return sgn*ret;
    }
}
