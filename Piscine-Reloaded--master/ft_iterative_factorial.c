
int		ft_iterative_factorial(int nb)
{
	int r;

	r = nb;
	if (r < 0 || r > 15)
		return (0);
	else if (r == 0 || r == 1)
		return (1);
	else
	{
		while (r > 1)
		{
			r--;
			nb *= r;
		}
	}
	return (nb);
}
