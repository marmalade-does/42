#include "../../includes/push_swap_be.h"

void	ft_ra(t_digit **stack_a)
{
	t_digit *head;
	t_digit *but;
	t_digit *temp;

	if(!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	head = ft_stackfirst(*stack_a);
	but = ft_stacklast(*stack_a);
	
	temp = head -> next;
	temp -> prev = NULL;

	but -> next = head;
	head ->prev = but;
	head -> next = NULL;
	*stack_a = temp;
	*stack_a = ft_stackfirst(head);
	write(1, "ra\n", 3);
}

void	ft_rb(t_digit **stack_b)
{
	t_digit *head;
	t_digit *but;
	t_digit *temp;

	if(!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	head = ft_stackfirst(*stack_b);
	but = ft_stacklast(*stack_b);
	
	temp = head -> next;
	temp -> prev = NULL;

	but -> next = head;
	head ->prev = but;
	head -> next = NULL;
	*stack_b = ft_stackfirst(head);
	write(1, "rb\n", 3);
}

void	ft_rrb(t_digit **stack_b)
{
	t_digit *head;
	t_digit *but;
	t_digit *temp;

	if(!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	head = ft_stackfirst(*stack_b);
	but = ft_stacklast(*stack_b);
	
	temp = but -> prev;
	temp -> next = NULL;

	but -> next = head;
	head -> prev = but;
	but -> prev = NULL;

	*stack_b = but;
	write(1, "rrb\n", 4);
}

void	ft_rra(t_digit **stack_a)
{
	t_digit *head;
	t_digit *but;
	t_digit *temp;

	if(!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	head = ft_stackfirst(*stack_a);
	but = ft_stacklast(*stack_a);
	
	temp = but -> prev;
	temp -> next = NULL;

	but -> next = head;
	head -> prev = but;
	but -> prev = NULL;

	*stack_a = ft_stackfirst(but);
	write(1, "rra\n", 4);
}
