


#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFFER_SIZE 1024

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*cut_line(char *backup);
char	*append_backup(char *backup, int fd);

#endif

