

int		ft_sqrt(int nb)
{
	int root;

	root = 1;
	while (root * root < nb)
		root++;
	if (root * root == nb)
		return (root);
	else
		return (0);
}
