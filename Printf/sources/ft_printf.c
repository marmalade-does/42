#include "../includes/ft_printf.h"


// issues with this code: 
// --- Doens't implement escap back slashes (is that needed?)
// --- Doens't do the extra of the project.

static void	ft_printf_checker(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i') // this looks like rank check if correct
		ft_putnbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_put_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_puthex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_puthex(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_putptr(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar_leng(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_leng('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args; // a variable type included in the stdarg.h librairy
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%') // There is no checking for escape backslashes ? 
		{
			i++;
			ft_printf_checker(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putcharacter_length((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}



// typedef /* implementation-defined */ va_list;
// void va_start(va_list ap, last_fixed_param);

