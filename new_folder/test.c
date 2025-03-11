#include <stdio.h>
#include <stdlib.h>

void	secondary_function(int i);

void	quick_function(void)
{
	secondary_function(1);
	printf("this is still printed?");
}

int	main(void)
{
	quick_function();
	return (0);
}