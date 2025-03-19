/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroberts <marvin@42.barcelona>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:51 by lroberts          #+#    #+#             */
/*   Updated: 2025/03/19 20:42:18 by lroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Things that need to improve this code:
* I don't think -- (need to test) that this code works for when tehre are
--- >1 '\n' in a biven BUFFER_SIZE read
* Need to do the extra things that are mentioned in the pdf
* ---> read the pdf :)
*/

/*
 ** @brief      Takes data until \n from file and appends it to end of buffer
 **             -- Returns until a \n from the front (eg a a line of text)
 **
 ** @param fd   The file descriptor that you want to read line-to-line from
 ** @return     A dynamically allocated string with a '\0' behind
 **             the '\n' (allow for eg printf() usage)
 ** @remarks    You need to free the return in the caller function
 */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) 
		return (NULL);
	backup = append_backup(backup, fd);
	if (backup == NULL)
		return (NULL);
	line = cut_line(backup);
	if (line == NULL)
	{
		free(backup);
		return (NULL);
	}
	backup = ft_shave_backup(backup);
	if(backup == NULL)
		return (NULL);
	return (line);
}
/* 
int	main(int argc, char **argv)
{
    int		fd;
    char	*line;

    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
		free(line);
    }
    close(fd);
    return (0);
}
 */