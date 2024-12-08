#include <unistd.h>

void	ft_putchar(char h);

int		main(int ac, char **av)
{
	int a;
	int b;

	a = 1;
	b = 0;
	while (a < ac)
	{
		while (av[a][b])
		{
			ft_putchar(av[a][b]);
			b++;
		}
		ft_putchar('\n');
		b = 0;
		a++;
	}
	return (0);
}
