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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = append_backup(backup, fd);
	if (backup == NULL)
		return (NULL);
	line = cut_line(backup);
	if (line == NULL)
		return (NULL);
	temp = backup;
	backup = line;
	line = temp;
	temp = NULL;
	return (line);
}
