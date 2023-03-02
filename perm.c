#define SWAP(E, F) { int SWAP = (E); (E) = (F); (F) = SWAP; }
int perm(int* a, int n, int x)
{
	int i;
	if (x == n)
	{
		rep(i, n) printf("%d ", a[i]);
		printf("\n");
		return 0;
	}
	for (i = x; i < n; i++)
	{
		SWAP(a[x], a[i]);
		perm(a, n, x + 1);
		SWAP(a[x], a[i]);
	}
	return 0;
}
