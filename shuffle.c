void shuffle(int *a, int m, int n)
{
	int i, j, s;
	rep(i, m)
	{
		j = i + rand()%(n - i);
		s = a[j]; a[j] = a[i]; a[i] = s;
	}
}

