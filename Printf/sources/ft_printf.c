#include "../includes/ft_printf.h"


// issues with this code: 
// --- Doens't implement escap back slashes (is that needed?)
// --- Doens't do the extra of the project.

#include "../includes/ft_printf.h"

// issues with this code: 
// --- Doesn't implement escape backslashes (is that needed?)

static void	sp_print(char s, va_list *args, int *len, int *i);

int	ft_printf(const char *string, ...)
{
    va_list	args; // a variable type included in the stdarg.h library
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
            sp_print(string[i], &args, &length, &i);
            i++;
        }
        else
        {
            put_charsum(string[i], &length);
            i++;
        }
    }
    va_end(args);
    return (length);
}

static void	sp_print(char s, va_list *args, int *len, int *i)
{
    if (s == 'c')
        put_charsum(va_arg(*args, int), len);
    else if (s == 's')
        string(va_arg(*args, char *), len);
    else if (s == 'd' || s == 'i')
        number(va_arg(*args, int), len);
    else if (s == 'x')
        hexadecimal_low(va_arg(*args, unsigned int), len);
    else if (s == 'X')
        hexadecimal_up(va_args(*args, unsigned int), len);
    else if (s == 'u')
        unsigned_int(va_arg(*args, unsigned int), len);
    else if (s == 'p')
        pointer(va_arg(*args, size_t), len);
    else
        put_charsum(s, len);
}

int main ()
{
	char *str = "This is a string hehe %i";
	int num = 5;

	ft_printf(str, num);
	return(0);
}
