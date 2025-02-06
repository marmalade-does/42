void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int i;

	i = 0;
	if (tab == NULL || f == NULL)
		return;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
