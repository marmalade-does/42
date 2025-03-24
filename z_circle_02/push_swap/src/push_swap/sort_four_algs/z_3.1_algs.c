#include "../../../includes/push_swap.h"

void	ft_sort_3124(t_digit **stack_a)
{
	ft_rra(stack_a);
	ft_sa(stack_a);
	ft_ra(stack_a);
	ft_ra(stack_a);
}

void	ft_sort_3142(t_digit **stack_a)
{
	ft_sa(stack_a);
	ft_rra(stack_a);
	ft_sa(stack_a);
}

void	ft_sort_3214(t_digit **stack_a, t_digit **stack_b)
{
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_ss(stack_a, stack_b);
	ft_pa(stack_b, stack_a);
	ft_pa(stack_b, stack_a);
	ft_rra(stack_a);
}
