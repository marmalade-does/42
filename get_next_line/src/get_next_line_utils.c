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

/**
 * @brief Reads from a file descriptor and appends the content to the backup string.
 * 
 * @param backup The current backup string.
 * @param fd The file descriptor to read from.
 * @return A pointer to the updated backup string, or NULL if an error occurs.
 */
char	*append_backup(char *backup, int fd)
{
    char	buffer[BUFFER_SIZE + 1];
    char	*temp;
    int		red;

    red = 1;
    if (!backup)
        backup = ft_strdup("");
    while (red > 0)
    {
        red = read(fd, buffer, BUFFER_SIZE);
        buffer[red] = '\0';
        if (!backup)
            return (NULL);
        temp = ft_strjoin(backup, buffer);
        free(backup);
        if (!temp)
            return (NULL);
        backup = temp;
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    if (red == -1)
        return (NULL);
    return (backup);
}

/**
 * @brief Extracts the line (up to and including the first newline) from the backup string.
 * 
 * @param backup The backup string.
 * @return A pointer to the newly allocated line, or NULL if allocation fails.
 */
char	*cut_line(char *backup)
{
    char	*line;
    int		i;

    if (backup == NULL)
        return (NULL);
    i = 0;
    while (backup[i] != '\0' && backup[i] != '\n')
        i++;
    line = ft_substr(backup, 0, i + 1);
    if (line == NULL)
        return (NULL);
    return (line);
}

/**
 * @brief Removes the extracted line from the backup string, leaving only the remaining content.
 * 
 * @param backup_unshaven The original backup string.
 * @return A pointer to the updated backup string, or NULL if no content remains.
 */
char  *ft_shave_backup(char *backup_unshaven)
{
    int i;
    char *backup_shaven;

    i = 0;
    if (backup_unshaven == NULL)
        return (NULL);
    while (backup_unshaven[i] && backup_unshaven[i] != '\n')
        i++;
    if (backup_unshaven[i] == '\0')
    {
        free(backup_unshaven);
        return (NULL);
    }
    backup_shaven = ft_substr(backup_unshaven, (unsigned int)(i + 1), (ft_strlen(backup_unshaven) - i));
    free(backup_unshaven);
    return (backup_shaven);	
}
