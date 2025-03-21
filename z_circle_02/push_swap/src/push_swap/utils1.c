#include "../../includes/push_swap.h"

/**
 * @brief Returns the absolute value of an integer.
 * 
 * @param num The integer whose absolute value is to be calculated.
 * @return long The absolute value of the input integer.
 */
long	ft_abs(int num)
{
	if (num >= 0)
		return ((long)num);
	return ((long)(-num));
}

/**
 * @brief Creates a new node for a doubly linked list.
 * 
 * @param num The value to be stored in the new node.
 * @return t_digit* A pointer to the newly created node.
 * 
 * @note Exits the program with an error message if memory allocation fails.
 */
t_digit	*ft_new_digit(int num)
{
	t_digit	*new_digit;

	new_digit = (t_digit *)malloc(sizeof(t_digit));
	if (!new_digit)
	{
		printf("malloc meemory alloc failure");
		ft_error();
        exit(3);
	}
	new_digit->num = num;
	new_digit->next = NULL;
	new_digit->prev = NULL;
	return (new_digit);
}

/**
 * @brief Calculates the length of a word in a string, delimited by a specific character.
 * 
 * @param str The input string.
 * @param delim The delimiter character.
 * @return size_t The length of the word.
 */
static size_t	word_len(const char *str, char delim)
{
	size_t	len;

	len = 0;
	while (*str == delim)
		str++;
	while (*str != delim && *str++)
		len++;
	return (len);
}

/**
 * @brief Counts the number of words in a string, separated by a specific delimiter.
 * 
 * @param str The input string.
 * @param delim The delimiter character.
 * @return size_t The number of words in the string.
 */
static size_t	count_words(const char *str, char delim)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == delim)
			str++;
		if (*str && *str != delim)
		{
			count++;
			while (*str != delim && *str)
				str++;
		}
	}
	return (count);
}

/**
 * @brief Splits a string into an array of words, separated by a specific delimiter.
 * 
 * @param str The input string to be split.
 * @param delim The delimiter character used to separate words.
 * @return char** A dynamically allocated array of strings (words).
 * 
 * @note Returns NULL if memory allocation fails.
 * @note The caller is responsible for freeing the allocated memory.
 */
char	**ft_split(char const *str, char delim)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**mat;

	i = 0;
	k = 0;
	mat = (char **)malloc(sizeof(char *) * (count_words(str, delim) + 1));
	if (!str || !(mat))
		return (NULL);
	while (i < count_words(str, delim))
	{
		while (str[k] == delim)
			k++;
		mat[i] = (char *)malloc(sizeof(char) * (word_len(&str[k], delim) + 1));
		if (!(mat[i]))
			return (NULL);
		j = 0;
		while (str[k] != delim && str[k])
			mat[i][j++] = str[k++];
		mat[i][j] = '\0';
		i++;
	}
	mat[i] = NULL;
	return (mat);
}
