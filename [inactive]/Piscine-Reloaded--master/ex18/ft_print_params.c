#include <unistd.h>

/*void	ft_putchar(char h);*/

int		main(int argc, char *argv[])
{
	int a;
	int b;

	a = 1;
	b = 0;
	while (a < argc)
	{
		while (argv[a][b])
		{
			ft_putchar(argv[a][b]);
			b++;
		}
		ft_putchar('\n');
		b = 0;
		a++;
	}
	return (0);
}

/*
void	ft_putchar(char h)
{
	write(1, &h, 1);
}
*/