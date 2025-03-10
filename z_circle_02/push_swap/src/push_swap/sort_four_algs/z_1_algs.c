
#include "../../../includes/push_swap.h"

// Functions for ft_sort_four_1 permutations
void	ft_sort_1243(t_digit **stack_a)
{
	ft_ra(stack_a);
	ft_ra(stack_a);
	ft_sa(stack_a);
	ft_rra(stack_a);
	ft_rra(stack_a);
}

void	ft_sort_1324(t_digit **stack_a)
{
	ft_ra(stack_a);
	ft_sa(stack_a);
	ft_rra(stack_a);
}

void	ft_sort_1342(t_digit **stack_a)
{
	ft_rra(stack_a);
	ft_sa(stack_a);
}

void	ft_sort_1423(t_digit **stack_a)
{
	ft_sa(stack_a);
	ft_rra(stack_a);
}

void	ft_sort_1432(t_digit **stack_a, t_digit **stack_b)
{
	ft_pa(stack_a, stack_b);
	ft_sa(stack_a);
	ft_rra(stack_a);
	ft_pb(stack_b, stack_a);
}
