#include "../../includes/push_swap.h"

void	ft_rrr(t_digit **stack_a, t_digit **stack_b)
{
	t_digit *head_a;
	t_digit *but_a;
	t_digit *head_b;
	t_digit *but_b;

	if(!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	head_a = ft_stackfirst(*stack_a);
	but_a = ft_stacklast(*stack_a);
	if(!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	head_b = ft_stackfirst(*stack_b);
	but_b = ft_stacklast(*stack_b);
	
	(but_a -> prev) -> next = NULL;
	but_a -> next = head_a;
	head_a -> prev = but_a;
	but_a -> prev = NULL;
	*stack_a = but_a;
	
	(but_b -> prev) -> next = NULL;
	but_b -> next = head_b;
	head_b -> prev = but_b;
	but_b -> prev = NULL;
	*stack_b = but_b;

	write(1, "rrr\n", 4);
}

void	ft_rr(t_digit **stack_a, t_digit **stack_b)
{
	t_digit *head_a;
	t_digit *but_a;
	t_digit *head_b;
	t_digit *but_b;

	if(!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	if(!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	
	head_b = ft_stackfirst(*stack_b);
	but_b = ft_stacklast(*stack_b);
	head_a = ft_stackfirst(*stack_a);
	but_a = ft_stacklast(*stack_a);

	(head_a -> next) -> prev = NULL;
	but_a -> next = head_a;
	head_a ->prev = but_a;
	head_a -> next = NULL;
	*stack_a = ft_stackfirst(head_a);

	(head_b -> next) -> prev = NULL;
	but_b -> next = head_b;
	head_b ->prev = but_b;
	head_b -> next = NULL;
	*stack_b = ft_stackfirst(head_b);
	write(1, "rr\n", 3);
}

/* void	ft_pp(t_digit **stack_a, t_digit **stack_b)
{
	t_digit *head_a;
	t_digit *head_b;
	t_digit *temp;

	if(!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if(!stack_b || !*stack_b || !(*stack_b)->next)
		return ;

	head_b = ft_stackfirst(*stack_b);
	head_a = ft_stackfirst(*stack_a);

	(head_a -> next) -> prev = head_b;
	(head_b -> next) -> prev = head_a;
	temp = head_a -> next;
	head_a -> next = head_b -> next;
	head_b -> next = temp;
	*stack_a = head_b;
	*stack_b = head_a;
	write(1, "ss\n", 3); 
} */

