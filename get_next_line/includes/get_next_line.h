#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char  *ft_shave_backup(char *backup_unshaven);
char	*cut_line(char *backup);
char	*append_backup(char *backup, int fd);

#endif
