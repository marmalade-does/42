#include <unistd.h>
#include <stdio.h>
// Your function must return its result in less than two seconds
// check that eseo se cumple

int		ft_iterative_factorial(int nb)
{
	int abs_val;

	if(nb < 0)
		return(0);
	if(nb == 0 || nb == 1)
	// add a check for input size? 
		return(1);
	abs_val = 1;
	while(nb > 1)
	{
		abs_val *= nb;
		nb--;
	}
	return(abs_val);
}

/*
void main(void)
{
	int nb = 5;

	printf("factorial of %i == %i", nb, ft_iterative_factorial(nb));
	return;
}
*/