#include "../includes/get_next_line.h"

/**
 * @brief Duplicates a string by allocating memory for a new copy.
 * 
 * @param s The string to duplicate.
 * @return A pointer to the newly allocated string, or NULL if allocation fails.
 */
char	*ft_strdup(const char *s)
{
    char	*str;
    int		i;
    int		j;

    i = 0;
    j = ft_strlen(s);
    str = (char *)malloc(sizeof(*str) * (j + 1));
    if (str == NULL)
        return (NULL);
    while (i < j)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

/**
 * @brief Joins two strings into a newly allocated string.
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the newly allocated concatenated string, or NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
    int		i;
    int		j;
    char	*str;

    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    i = 0;
    j = 0;
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (str == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}

/**
 * @brief Calculates the length of a string.
 * 
 * @param str The string to measure.
 * @return The length of the string.
 */
int	ft_strlen(const char *str)
{
    int	i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

/**
 * @brief Finds the first occurrence of a character in a string.
 * 
 * @param s The string to search.
 * @param i The character to find.
 * @return A pointer to the first occurrence of the character, or NULL if not found.
 */
char	*ft_strchr(const char *s, int i)
{
    while (*s)
    {
        if (*s == i)
            return ((char *)s);
        s++;
    }
    if (i == '\0')
        return ((char *)s);
    return (0);
}

/**
 * @brief Extracts a substring from a string.
 * 
 * @param s The source string.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return A pointer to the newly allocated substring, or NULL if allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t	i;
    size_t	j;
    char	*str;

    if (!s)
        return (NULL);
    if (start >= (unsigned int)ft_strlen(s))
        return (ft_strdup(""));
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    i = start;
    j = 0;
    while (s[i] && j < len)
    {
        str[j] = s[i];
        j++;
        i++;
    }
    str[j] = '\0';
    return (str);
}
