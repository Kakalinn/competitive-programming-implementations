#include <stdio.h>
#include "battis.h"

int main()
{ // A simple iterative method of replicating an n-fold for-loop.
	int i, j, p = 1, n = get_int();
	int a[n], k[n];
	rep(i, n) p *= (a[i] = get_int());
	rep(i, p)
	{
		int t = i;
		per(j, n) k[j] = t%a[j], t /= a[j];
		rep(j, n) printf("%d ", k[j] + 1); printf("\n");
	}
	return 0;
}
