int	binpow(int a, int n)
{
	int	res;

	res = 0;
	while (n > 0)
	{
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return (res);
}
