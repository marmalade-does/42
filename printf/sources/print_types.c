#include "../includes/ft_printf.h"

void put_charsum(const char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void str(const char *str, int *len)
{
	int i = 0;

	if(str == NULL)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return;
	}
	while(str[i] != '\0')
	{
		put_charsum(str[i], len);
		i++;
	}
}

void number(int nb, int *len)
{
	if(nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return;
	}
	if(nb < 0)
	{
		put_charsum('-', len);
		nb *= -1;
	}
	if(nb >= 10)
	{
		number(nb/10, len);
	}
	put_charsum((nb % 10 + '0'), len);
}

void	unsigned_int(unsigned int u, int *len)
{
	if (u >= 10)
		unsigned_int(u / 10, len);
	put_charsum(u % 10 + '0', len);
}

void	print_ptr(size_t ptr, int *len)
{
	if(ptr == 0)
	{
		str("(null)", len);
	}
	else
	{
		str("0x", len);
		rec_ptr(ptr, len);
	}
	return ;
}

void	rec_ptr(size_t ptr, int *len)
{
	const char	*hex_arr;

	hex_arr = "0123456789abcdef";
	if (ptr >= 16)
		rec_ptr(ptr / 16, len);
	put_charsum(hex_arr[ptr % 16], len);
}

void	hexadecimal_up(unsigned int x, int *len)
{
	char *hex_arr; 

	hex_arr = "0123456789ABCDEF";
	if(x == 0)
	{
		put_charsum('0', len);
		return ;
	}
	if(x >= 16)
	{
		hexadecimal_up(x / 16, len);
	}
	put_charsum(hex_arr[x % 16], len);
}

void	hexadecimal_low(unsigned int x, int *len)
{
	char *hex_arr; 

	hex_arr = "0123456789abcdef";
	if(x == 0)
	{
		put_charsum('0', len);
		return ;
	}
	if(x >= 16)
	{
		hexadecimal_low(x / 16, len);
	}
	put_charsum(hex_arr[x % 16], len);
}