#include "get_next_line.h"

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*append_backup(char *backup, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		red;

	red = 1;
	while (red > 0)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		buffer[red] = '\0';
		if (!backup)
			backup = ft_strdup("");
		if (!backup)
			return (NULL);
		temp = strjoin(buffer, backup);
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

char	*cut_line(char *backup)
{
	char	*new_backup;
	int		i;

	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
		return (NULL);
	new_backup = ft_substr(backup, (unsigned int)i, (strlen(backup) - i));
	if (new_backup == NULL)
		return (NULL);
	backup[i + 1] = '\0';
	return (new_backup);
}
