
#include "libft.h"

// rewrite parts of this. Kinda crappy code

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if(s1 == NULL || set == NULL)
		return (NULL)
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
		j--;
	
	
	// can probably be replaced with a ft_substr as done here.
	str = ft_substr(s1, (unsigned int)i, (j - i + 1));
/* 	
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (str)
		ft_strlcpy(str, &s1[i], j - i + 1);
*/	
	
	else
		return (NULL);
	return (str);
}

double sum(double a, double b)
{
	return (a + b);
}
