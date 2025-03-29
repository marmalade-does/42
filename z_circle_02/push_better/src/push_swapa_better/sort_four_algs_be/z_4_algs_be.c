#include "../../../includes/push_swap.h"

void	ft_sort_4231(t_digit **stack_a)
{
    ft_rra(stack_a);
    ft_sa(stack_a);
    ft_ra(stack_a);
}

void	ft_sort_4312(t_digit **stack_a)
{
    ft_sa(stack_a);
    ft_ra(stack_a);
    ft_ra(stack_a);
}

void	ft_sort_4321(t_digit **stack_a)
{
    ft_sa(stack_a);
    ft_ra(stack_a);
    ft_ra(stack_a);
    ft_sa(stack_a);
}
