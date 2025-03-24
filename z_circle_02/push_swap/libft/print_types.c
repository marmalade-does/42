#include "libft.h"

int put_charsum(const char c, int *len)
{
    if (write(1, &c, 1) == -1)
        return -1;
    (*len)++;
    return 0;
}

int str(const char *str, int *len)
{
    int i = 0;

    if (str == NULL)
    {
        if (write(1, "(null)", 6) == -1)
            return -1;
        (*len) += 6;
        return 0;
    }
    while (str[i] != '\0')
    {
        if (put_charsum(str[i], len) == -1)
            return -1;
        i++;
    }
    return 0;
}

int number(int nb, int *len)
{
    if (nb == INT_MIN)
    {
        if (write(1, "-2147483648", 11) == -1)
            return -1;
        (*len) += 11;
        return 0;
    }
    if (nb < 0)
    {
        if (put_charsum('-', len) == -1)
            return -1;
        nb *= -1;
    }
    if (nb >= 10)
    {
        if (number(nb / 10, len) == -1)
            return -1;
    }
    if (put_charsum((nb % 10 + '0'), len) == -1)
        return -1;
    return 0;
}

int unsigned_int(unsigned int u, int *len)
{
    if (u >= 10)
    {
        if (unsigned_int(u / 10, len) == -1)
            return -1;
    }
    if (put_charsum(u % 10 + '0', len) == -1)
        return -1;
    return 0;
}

int print_ptr(size_t ptr, int *len)
{
    if (ptr == 0)
    {
        return str("(null)", len);
    }
    else
    {
        if (str("0x", len) == -1)
            return -1;
        return rec_ptr(ptr, len);
    }
}

int rec_ptr(size_t ptr, int *len)
{
    const char *hex_arr;

    hex_arr = "0123456789abcdef";
    if (ptr >= 16)
    {
        if (rec_ptr(ptr / 16, len) == -1)
            return -1;
    }
    if (put_charsum(hex_arr[ptr % 16], len) == -1)
        return -1;
    return 0;
}

int hexadecimal_up(unsigned int x, int *len)
{
    char *hex_arr;

    hex_arr = "0123456789ABCDEF";
    if (x == 0)
    {
        if (put_charsum('0', len) == -1)
            return -1;
        return 0;
    }
    if (x >= 16)
    {
        if (hexadecimal_up(x / 16, len) == -1)
            return -1;
    }
    if (put_charsum(hex_arr[x % 16], len) == -1)
        return -1;
    return 0;
}

int hexadecimal_low(unsigned int x, int *len)
{
    char *hex_arr;

    hex_arr = "0123456789abcdef";
    if (x == 0)
    {
        if (put_charsum('0', len) == -1)
            return -1;
        return 0;
    }
    if (x >= 16)
    {
        if (hexadecimal_low(x / 16, len) == -1)
            return -1;
    }
    if (put_charsum(hex_arr[x % 16], len) == -1)
        return -1;
    return 0;
}

/* 
void put_charsum(const char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
	// make sure printf returns -1 if write fails    
}

	Need to check
* free in your ft_split
* puchar check the fd
* get **francinette**
* your make recompiles the bonus instead of not recompiiling
	

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
} */