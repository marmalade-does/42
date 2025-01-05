#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard C Libraries

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

int	put_charsum(const char character, int *len);
int str(const char *str, int *len);
int	number(int number, int *len);
int hexadecimal_up(unsigned int x, int *len);
int	hexadecimal_low(unsigned int x, int *len);
int	unsigned_int(unsigned int u, int *len);
int	print_ptr(size_t pointer, int *len);
int	rec_ptr(size_t ptr, int *len);

int	ft_printf(const char *string, ...);

#endif