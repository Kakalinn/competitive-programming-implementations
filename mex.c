int mex(int* a, int n)
{
	int b[n], i;
	rep(i, n) b[i] = 0;
	rep(i, n) if (a[i] < n) b[a[i]] = 1;
	rep(i, n) if (!b[i]) break;
	return i;
}

