#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// How to improve
// Make it still work for arbitrairy preceding or succeding delemeters
// Make it not trip or repeated delimenter(?) <- check with other students if you need to do this

static void		free_split(char **result);
char			**ft_split(char const *s, char c);
static char		*malloc_cpy_str(char *s, int *pos, char c);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		token_count;
	int		pos;
	int		i;

	if (s == NULL)
		return (NULL);
	token_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			token_count++;
		i++;
	}
	result = (char **)malloc((token_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result[token_count] = '\0';
	i = 0;
	pos = 0;
	while (i < token_count)
	{
		result[i] = malloc_cpy_str((char *)s, &pos, c)
			/*ft_stralloc(((char *)str), c, &pos)*/;
		if (result[i] == NULL)
		{
			free_split(result);
			return (NULL);
		}
		i++;
	}
	// while loop that has a alloc_cpy_str() function
	// --- the cpy is another function inside of str.
	return (result);
}

static char	*malloc_cpy_str(char *s, int *pos, char c)
{
	char	*token;
	int		start;

	while (s[*pos] == c)
	{
		if (s[*pos] == '\0')
			break ; // I think there is something wrong here.
		*pos++;
	}
	start = *pos;
	while (s[*pos] != c && s[*pos] != '\0')
		*pos++;
	token = (char *)malloc(sizeof(char) * (*pos - start));
		// don't need to allocate '+1' becuase delimeter isn't copied over.
	if (token == NULL)
		return (NULL);
	strncpy(token, &s[start + 1], (*pos - start));
	return (token);
}

/*I think this is correct but IDK hahaha*/

static void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	main(void)
{
	const char	*s = "apple,banana,cherry,dates";
	char		delimiter;
	char		**result;
	int			i;

	delimiter = ',';
	result = ft_split(s, delimiter);
	i = 0;
	if (result != NULL)
	{
		while (result[i] != NULL)
		{
			printf("%s\n", result[i]);
			i++;
		}
		free_split(result);
	}
	else
		printf("Failed to split the string.\n");
	return (0);
}

/*

static size_t	ft_strncpy(char *dest, const char *src, size_t size);

static size_t	ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}


-----








#include "libft.h"

static void		freeup_str(char **strs, int count);
static int		wordcount(char *str, char c);
static void		ft_strcpy(char *word, char *str, char c, int j);
static char		*stralloc(char *str, char c, int *k);

// Splits the input string based on the delimiter 'c'
char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	// Allocate and copy each word
	while (i < j)
	{
		strs[i] = stralloc((char *)str, c, &pos);
		if (strs[i] == NULL)  // Memory allocation failure
		{
			freeup_str(strs, i);  // Free previously allocated memory
			return (NULL);
		}
		i++;
	}
	return (strs);
}

// Allocates memory for a single word and returns it
static char	*stralloc(char *str, char c, int *k)
{
	char	*word;
	int		start;
	int		length;

	start = *k;
	length = 0;
	while (str[start] == c)
		start++;
	// Calculate the length of the word
	while (str[start + length] != c && str[start + length] != '\0')
		length++;
	// Allocate memory for the word (including null terminator)
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	// Copy the word into the allocated memory
	ft_strcpy(word, str, c, start);
	*k = start + length;  // Update the position in the original string
	return (word);
}

// Counts the number of words in the string based on the delimiter 'c'
static int	wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
		{
			word++;
		}
		i++;
	}
	return (word);
}


// Copies a word into the destination word array
static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}


// Frees up the array of strings if any allocation fails
static void	freeup_str(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}







what the github gave me
static void	freeup_str(char *strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs);
		i++;
	}
	free(strs);
}

static int	wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*stralloc(char *str, char c, int *k)
{
	char	*word;
	int		j;

	j = *k;
	word = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k] != '\0' && str[*k] != c)
				*k += 1;
			word = (char *)malloc(sizeof(char) * (*k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		*k += 1;
	}
	ft_strcpy(word, str, c, j);
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = stralloc(((char *)str), c, &pos);
		if (strs[i] == NULL)
		{
			freeup_str(strs[i]);
		}
		i++;
	}
	return (strs);
}

*/