#include <stdio.h>


int		ft_recursive_factorial(int nb)
{
	if(nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
	return (0);
}

/*
void main(void)
{
	int nb = 5;

	printf("factorial of %i == %i", nb, ft_iterative_factorial(nb));
	return;
}
*/
