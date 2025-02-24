#include "../../includes/push_swap.h"

static size_t	word_len(const char *str, char delim);
static size_t	count_words(const char *str, char delim);

//print an error message
void	ft_error(void)
{	
    write (2, "Error\n", 6);
    exit(1);
}

// makes a new digit for on list
t_digit *ft_new_digit(int num)
{
    t_digit *new_digit;

    new_digit = (t_digit *)malloc(sizeof(t_digit));
    if (!new_digit)
    {
        ft_error();
        exit(3);
    }
    new_digit->num = num;
    new_digit->i = 0;
    new_digit->next = NULL;
    new_digit->prev = NULL;

    return (new_digit);
}

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













