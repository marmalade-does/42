#include "../../includes/push_swap.h"

//  self evident
t_digit	*ft_stacklast(t_digit *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

// self evident
int	ft_stacksize(t_digit *stack)
{
    size_t	size;

    size = 0;
    while (stack)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}

// Finds min num in stack
int	ft_min(t_digit *stack)
{
    int		min_value;

    min_value = stack->num;
    while (stack)
    {
        if (stack->num < min_value)
            min_value = stack->num;
        stack = stack->next;
    }
    return (min_value);
}

// Finds max num in stack
int	ft_max(t_digit *stack)
{
    int		max_value;

    max_value = stack->num;
    while (stack)
    {
        if (stack->num > max_value)
            max_value = stack->num;
        stack = stack->next;
    }
    return (max_value);
}
