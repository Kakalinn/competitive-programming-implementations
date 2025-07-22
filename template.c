#include <stdio.h>
#include <assert.h>
#define getchar() getchar_unlocked()
#define irep(E, F) for (int E = 0; E < (F); E++)
#define iper(E, F) for (int E = (F) - 1; E >= 0; E--)
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
typedef long long ll;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int get_int()
{
    int r = 0, c = getchar(), s = 1;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    while (c == '-') s *= -1, c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return s*r;
}

int main()
{
    return 0;
}
