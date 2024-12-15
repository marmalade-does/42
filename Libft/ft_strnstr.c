
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	char	*editable_haystack;

	editable_haystack = (char *)haystack;  // Create a modifiable pointer
	i = 0;
	j = 0;
	if (needle == NULL || needle[0] == '\0')
		return (editable_haystack);  // Return the modifiable pointer
	while (editable_haystack[i] != '\0' && i < n)
	{
		if (editable_haystack[i] == needle[j])
		{
			while (editable_haystack[i + j] == needle[j] && i + j < n)
			{
				if (needle[j + 1] == '\0')
					return (editable_haystack + i);  // Return the modifiable pointer
				j++;
			}
			j = 0;
		}	
		i++;
	}
	return (NULL);
}