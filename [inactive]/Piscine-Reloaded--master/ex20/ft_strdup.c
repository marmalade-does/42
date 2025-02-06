#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int		ft_strlen(char *str);

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ft_strlen(str) + 1);
	if(dest == NULL)
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

/*
void main ()
{
	char *a = "here is the source";
	char *b;

	b = ft_strdup(a);
	if(b == NULL)
	{
		write(1, "string failed to copy over", 26);
		return;
	}
	printf("OG strng: %s", a);
	printf("duped string: %s", b);
	return;
}
*/