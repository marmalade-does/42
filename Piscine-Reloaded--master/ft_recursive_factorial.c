
int		ft_recursive_factorial(int nb)
{
	if (nb >= 0 && nb <= 15)
	{
		if (nb == 0 || nb == 1)
			return (1);
		else
			return (nb * ft_recursive_factorial(nb - 1));
	}
	return (0);
}
