


static char	*append_backup(char *backup, int fd)
{
	char	buffer[BUFFER_LEN + 1];
	char	*temp;
	int		red;

	red = 1;
	while (red > 0)
	{
		red = read(fd, buffer, BUFFER_LEN);
		if (red == 0)
			break ;
		if (red == -1)
			return (NULL);
		if (backup == NULL)
			backup = ft_strdup("");
		if (backup == NULL)
			return (NULL);
		buffer[red] = '\0';
		temp = strjoin(buffer, backup);
		free(backup);
		if (temp == NULL)
			return (NULL);
		backup = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}
