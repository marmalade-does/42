#include "../../includes/push_swap.h"

//print an error message
void	ft_error(void)
{	
    write (2, "Error\n", 6);
    exit(1);
}

// makes a new digit for on list
t_digit *ft_new_digit(int num)
{
    t_digit *new_digit;

    new_digit = (t_digit *)malloc(sizeof(t_digit));
    if (!new_digit)
    {
        ft_error();
        exit(3);
    }
    new_digit->num = num;
    new_digit->i = 0;
    new_digit->next = NULL;
    new_digit->prev = NULL;

    return (new_digit);
}

