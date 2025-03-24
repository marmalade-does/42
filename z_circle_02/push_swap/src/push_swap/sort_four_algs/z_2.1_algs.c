#include "../../../includes/push_swap.h"

void	ft_sort_2134(t_digit **stack_a)
{
	ft_sa(stack_a);
}

void	ft_sort_2143(t_digit **stack_a, t_digit **stack_b)
{
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_ss(stack_a, stack_b);
	ft_pb(stack_b, stack_a);
	ft_pb(stack_b, stack_b);
}

void	ft_sort_2314(t_digit **stack_a, t_digit **stack_b)
{
	ft_pa(stack_a, stack_b);
	ft_sa(stack_a);
	ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	ft_rra(stack_a);
}
