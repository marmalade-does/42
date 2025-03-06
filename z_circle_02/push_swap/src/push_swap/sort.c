
#include "../../includes/push_swap.h"


void fr_sort(t_digit stack_a, t_digit stack_b)


// use sort() as a main frame


void ft_sort(t_digit **stack_a, t_digit **stack_b)
{
	int a_len;

	if (a_len < 5)
	{
		if(a_len == 1)
		{
			exit(0) ; 
			// what to do if only onee number input? 
			//make a function that 'closes things off'  
		}
		if(a_len == 2)
		{
			ft_sa(stack_a); // this function 
			finish_off();
		}
		if(a_len == 3)
		{
			ft_sort_three(stack_a);
		}
		if(a_len == 4)
			ft_sort_four(stack_a, stack_b);
	}
	
	
	
	
	// if there are two things in stack_a swap them
	// if there are three things in stack_a use_solve three
	// if here are four thing in stack_a solve four
	// solve_big

	// final_orient
}

// remmeber, it needs to print ou hte move that it calculates while it does it. 


void final_orient() // this isn't correct go and write this as a propper function.
{
	if (i < ft_lstsize(*stack_a) - i)
	{
		while ((*stack_a)->nbr != ft_min(*stack_a))
			ft_ra(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->nbr != ft_min(*stack_a))
			ft_rra(stack_a, 0);
	}			
}	