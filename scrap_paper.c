#include "./libft/libft.h"
#include <stdio.h>


















* grit to get ti finished
* realise hoalfway throught that this isn't going to be valuable'
* decide to continue gven that you have spent so much time on t already


#include <stdarg.h>

int fr_error_va(char *errmsg, ...)
{
	va_list args;
	char *red;

	va_start(args, errmsg)
	write(2, errmsg, stlen(errmsg));
	while((red = va_arg(args, char *)) != NULL)
		write(2, red, strlen(red));
	write(2,'\n', 1);
	va_close(args);
	return (0);
}

int ft_error_va(char *errmsg, ...)
{
	va_list args;
	char	*red;

	va_start(args, errmsg);
	write(2, errmsg, strlen(errmsg));
	while((red = va_arg(args, char *)) != NULL)
	{
		write(2, red, strlen(red))
	}
	write(2, "\n", 1);
	va_end(args);
	return(0);
}















int function(int x, int y)
{
	return(x + y); 
}

int main()
{
	void (*function_ptr)(int, int);
	function_ptr = &function;
	(*function_ptr)(4);
}













#include <stdargs.h>

sourcee code exampl
{
	Here is some source code 
	if (2 = 3)
		return(ft_error("2 s not eequals to three", _FILE_, _FUNCTION_, _LINE_))
}

ft_error(char *errmsg, const char *file, const char *function, int line)
{
	return(ft_error_va(
		"asdfas",
		"asdfa"
		itoa(line);
		NULL
	));
}

int ft_error_va(char *errmsg, ...)
{
	va_args args;
	char *red;

	va_start(args, errmsg);
	write(2, errmsg, strlen(errmsg));
	while((red = va_arg(args, char*)) != NULL)
	{
		write(2, red, strlen(red));
	}
	write(2, "\n", 1);
	va_end(args);
	return(0);
}
