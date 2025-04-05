#include "../../includes/push_swap.h"

/**
 * @brief checks if the numbers in the stack are ascnding 
 * 
 * @param stack The head of the stack (or any ponter in the middle).
 * @return True or false (1, 0)
 */
int not_sorted(t_digit *stack)
{
	t_digit	*current;
	int		prev_num;

	current = ft_stackfirst(stack);
	prev_num = current -> num;
	current = current -> next;
	while(current != NULL)
	{
		if (prev_num > current -> num) // correct the smalest number needs to be at top of stack
			return (1);
		current = current -> next;
	}
	return(0);
}

/* 
void print_stacks_side_by_side(t_digit *stack_a, t_digit *stack_b)
{
    t_digit *current_a = stack_a;
    t_digit *current_b = stack_b;

    write(1, "Stack A\t\tStack B\n", 18);
    write(1, "-------------------------\n", 26);
    while (current_a || current_b)
    {
        if (current_a)
        {
            ft_putnbr_fd(current_a->num, 1);
            write(1, "\t\t", 2);
            current_a = current_a->next;
        }
        else
        {
            write(1, "\t\t", 2);
        }

        if (current_b)
        {
            ft_putnbr_fd(current_b->num, 1);
            write(1, "\n", 1);
            current_b = current_b->next;
        }
        else
        {
            write(1, "\n", 1);
        }
    }
} */

/*void	ft_print_stack(t_digit *head, char in)
{
	t_digit	*current;

	if (!head)
		return ;
	current = ft_stackfirst(head);
	while (current)
	{
		printf("%d\n", current->num);
		current = current->next;
	}
	printf("-\n%c\n\n", in);
}*/


