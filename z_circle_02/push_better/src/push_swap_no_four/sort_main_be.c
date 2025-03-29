#include "../../includes/push_swap.h"

void ft_sort(t_digit **stack_a)
{
	int a_len;
	t_digit **stack_b;

	stack_b == NULL;
	a_len = ft_stacksize(*stack_a);
	if(a_len < 4)
		ft_sort_u_four(stack_a, a_len); // change
	else
	// should asssign memory before I push it into here, or maby I asign in there
		ft_sort_big(stack_a, stack_b); // change
	return ;
}

void	ft_sort_u_four(t_digit **stack_a, int a_len)
{
	if(a_len == 2)
	{
		ft_sa(stack_a);
		ft_free_list(*stack_a);
		return ;
	}
	ft_sort_three(stack_a);
	ft_free_list(*stack_a);
	return ;

}






