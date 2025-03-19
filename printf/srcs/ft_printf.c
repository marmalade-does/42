#include "../include/ft_printf.h"

static int	sp_print(char s, va_list *args, int *len);

int ft_printf(const char *string, ...)
{
    va_list args;
    int i;
    int length;
    int result;

    i = 0;
    length = 0;
    va_start(args, string);
    while (string[i] != '\0')
    {
        if (string[i] == '%')
        {
            i++;
            result = sp_print(string[i], &args, &length);
            if (result == -1)
            {
                va_end(args);
                return -1;
            }
            i++;
        }
        else
        {
            result = put_charsum(string[i], &length);
            if (result == -1)
            {
                va_end(args);
                return -1;
            }
            i++;
        }
    }
    va_end(args);
    return length;
}

static int sp_print(char s, va_list *args, int *len)
{
    if (s == 'c')
        return (put_charsum(va_arg(*args, int), len));
    else if (s == 's')
        return (str(va_arg(*args, char *), len));
    else if (s == 'd' || s == 'i')
        return (number(va_arg(*args, int), len));
    else if (s == 'x')
        return (hexadecimal_low(va_arg(*args, unsigned int), len));
    else if (s == 'X')
        return (hexadecimal_up(va_arg(*args, unsigned int), len));
    else if (s == 'u')
        return (unsigned_int(va_arg(*args, unsigned int), len));
    return (0);
}

/*
int main()
{
    // Test %c (single character)
    char c = 'A';
    printf("Test %%c:\n");
    printf("Expected: [%c]\n", c);
    ft_printf("Result:   [%c]\n\n", c);

    // Test %s (string)
    char *str = "Hello, world!";
    printf("Test %%s:\n");
    printf("Expected: [%s]\n", str);
    ft_printf("Result:   [%s]\n\n", str);

    // Test %p (pointer)
    void *ptr = &c;
    printf("Test %%p:\n");
    printf("Expected: [%p]\n", ptr);
    ft_printf("Result:   [%p]\n\n", ptr);

    // Test %d (decimal number)
    int d = -12345;
    printf("Test %%d:\n");
    printf("Expected: [%d]\n", d);
    ft_printf("Result:   [%d]\n\n", d);

    // Test %i (integer in base 10)
    int i = 6789;
    printf("Test %%i:\n");
    printf("Expected: [%i]\n", i);
    ft_printf("Result:   [%i]\n\n", i);

    // Test %u (unsigned decimal)
    unsigned int u = UINT_MAX;
    printf("Test %%u:\n");
    printf("Expected: [%u]\n", u);
    ft_printf("Result:   [%u]\n\n", u);

    // Test %x (hexadecimal lowercase)
    unsigned int x = 0xabcdef;
    printf("Test %%x:\n");
    printf("Expected: [%x]\n", x);
    ft_printf("Result:   [%x]\n\n", x);

    // Test %X (hexadecimal uppercase)
    unsigned int X = 0xABCDEF;
    printf("Test %%X:\n");
    printf("Expected: [%X]\n", X);
    ft_printf("Result:   [%X]\n\n", X);

    // Test %% (percent symbol)
    printf("Test %%%%:\n");
    printf("Expected: [%%]\n");
    ft_printf("Result:   [%%]\n\n");

    // Edge Cases
    printf("Edge Cases:\n");
    
    // Null string
    printf("Test %%s with NULL string:\n");
    printf("Expected: it is not meant to compile");
    ft_printf("Result:   [%s]\n", (char *)NULL);

    // Large integers
    printf("Test %%d with INT_MAX and INT_MIN:\n");
    printf("Expected: [%d] [%d]\n", INT_MAX, INT_MIN);
    ft_printf("Result:   [%d] [%d]\n\n", INT_MAX, INT_MIN);

    printf("Test %%u with 0:\n");
    printf("Expected: [%u]\n", 0);
    ft_printf("Result:   [%u]\n\n", 0);

    // Zero pointer
    printf("Test %%p with NULL pointer:\n");
    printf("Expected: [%p]\n", (void *)NULL);
    ft_printf("Result:   [%p]\n\n", (void *)NULL);

    // Hexadecimal with 0
    printf("Test %%x and %%X with 0:\n");
    printf("Expected: [%x] [%X]\n", 0, 0);
    ft_printf("Result:   [%x] [%X]\n\n", 0, 0);

    return 0;
}
*/