#include <stdio.h>

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
void main ()
{
	const char *str; 
	str = "this is a string of 28 chars";
	int len = ft_strlen(str);
	printf("%i", len);
	return;
}
*/