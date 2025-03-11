#include "../../../includes/push_swap.h"

// Functions for ft_sort_four_4 permutations
void	ft_sort_4123(t_digit **stack_a)
{
	ft_ra(stack_a);
}

void	ft_sort_4132(t_digit **stack_a)
{
	ft_rra(stack_a);
	ft_sa(stack_a);
	ft_ra(stack_a);
	ft_sa(stack_a);
}

void	ft_sort_4213(t_digit **stack_a)
{
	ft_ra(stack_a);
	ft_sa(stack_a);
}
