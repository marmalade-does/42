
#include <stdlib.h>
#include <stdio.h>


int		ft_strlen(char *str);

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ft_strlen(str) + 1)
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
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}