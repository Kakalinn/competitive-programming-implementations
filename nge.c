void nge(int* a, int* b, int n)
{
	int s[n], t[n], c = 0, i;
	for (i = 0; i < n; i++)
	{
		while (c > 0 && s[c - 1] <= a[i]) b[t[--c]] = i;
		s[c] = a[i], t[c] = i; c++;
	}
	while (c > 0) b[t[--c]] = -1;
}
