#include "../../includes/push_swap_be.h"

void	ft_sort_three(t_digit *stack_a)
{
    int max;
	
	max = ft_max(stack_a);
	if (max == stack_a->num)
    {
        ft_ra(&stack_a);
        if (not_sorted(stack_a))
            ft_sa(&stack_a);
    }
    else if (ft_min(stack_a) == stack_a->num)
        ft_rra(&stack_a);
		// Can't be 123 because, that wouldn't have entered ft_sort
    else
    {
        if ((ft_stacklast(stack_a)) -> num == max)
            ft_sa(&stack_a);
        else
            ft_rra(&stack_a);
    }
}