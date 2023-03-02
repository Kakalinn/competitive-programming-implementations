int get_string(char* b, char t)
{
    int i = 0;
    b[i++] = getchar();
    while (b[i - 1] != t) b[i++] = getchar();
    b[i - 1] = '\0';
    return i - 1;
}
