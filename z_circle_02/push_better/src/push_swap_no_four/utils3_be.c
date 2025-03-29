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