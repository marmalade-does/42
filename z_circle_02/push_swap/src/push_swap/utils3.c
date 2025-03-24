#include "../../includes/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/**
 * @brief Prints two doubly linked lists side by side.
 * 
 * @param stack_a The head of the first doubly linked list (stack_a).
 * @param stack_b The head of the second doubly linked list (stack_b).
 */
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
}

/**
 * @brief checks if the numbers in the stack are ascnding 
 * 
 * @param stack The head of the stack (or any ponter in the middle).
 * @return True or false (1, 0)
 */
int not_sorted(t_digit **stack)
{
	t_digit	*current;
	int		prev_num;

	current = ft_stackfirst(*stack);
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



