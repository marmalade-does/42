
#include "../../includes/push_swap.h"


void ft_sort(t_digit **stack_a, t_digit **stack_b);
int ft_steps_to_min(t_digit **stack);
void ft_sort_u_five(stack_a, stack_b, a_len);


void ft_sort(t_digit **stack_a, t_digit **stack_b)
{
	int a_len;

	a_len = ft_stacksize((*stack_a));
	if(a_len < 5)
		ft_sort_u_five(stack_a, stack_b, a_len);
	else
		ft_sort_big(stack_a, stack_b);
	exit(0);
	// final_orient
}
// remmeber, it needs to print ou hte move that it calculates while it does it. 

void ft_sort_u_five(stack_a, stack_b, a_len)
{
	if(a_len == 1)
	{
		ft_free_lists_or_list(stack_a, stack_b, NULL);
		exit(0) ; 
	}
	else if(a_len == 2)
	{
		ft_sa(stack_a);
		ft_free_lists_or_list(stack_a, stack_b, NULL);
		exit(0);
	}
	else if(a_len == 3)
	{
		ft_sort_three(stack_a);
		ft_free_lists_or_list(stack_a, stack_b, NULL);
		exit(0);
	}
	else if(a_len == 4)
	{
		ft_sort_four(stack_a, stack_b);
		ft_free_lists_or_list(stack_a, stack_b, NULL);
		exit(0);
	}
}




