#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*
void main (void)
{
	char *there; 

	there = "this is a string literal";
	ft_putstr(there);
	return; 
}
*/