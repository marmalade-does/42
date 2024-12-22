#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard C Libraries

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void			put_charsum(char character, int *len);
void			string(char *args, int *len);
void			number(int number, int *len);
void        	hexadecimal_up(unsigned int x, int *len);
void	        hexadecimal_low(unsigned int x, int *len);
void			unsigned_int(unsigned int u, int *len);
void			pointer(size_t pointer, int *len);

int				ft_printf(const char *string, ...);

#endif
