#include "../../includes/push_swap.h"

void ft_sort(t_digit **stack_a)
{
	int a_len;
	t_digit **stack_b;

	stack_b == NULL;
	a_len = ft_stacksize(*stack_a);
	if(a_len < 5)
		ft_sort_u_five(stack_a, stack_b, a_len); // change
	else
		ft_sort_big(stack_a, stack_b); // change
	return ;
}

void	ft_sort_u_five(t_digit **stack_a, t_digit **stack_b, int a_len)
{
	/* if(a_len == 1) // en teoria nunca debe entrar por aqui ... pero ns
	{
		ft_free_list(stack_a);
		return ; 
	}
	else*/
	if(a_len == 2)
	{
		ft_sa(stack_a);
		ft_free_list(*stack_a);
		return ;
	}
	else if(a_len == 3)
	{
		ft_sort_three(stack_a);
		ft_free_list(*stack_a);
		return ;
	}
	else if(a_len == 4)
	{
		ft_sort_four(stack_a, stack_b); // need to see how this assigns memry for stack_b
		ft_free_list(*stack_b);
		return ;
	}
}






