#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char) s2[i]);
}

/*
void main ()
{
	char *s1 = "this is a string lalalalalal";
	char *s2 = "this is a string mwahaha";

	int diff = ft_strcmp(s1, s2);
	printf("%i", diff);
}
*/