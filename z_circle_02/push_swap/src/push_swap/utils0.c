#include "../../includes/push_swap.h"

// pass one or more than one list, NEEDS to end with NULL sentinel value.
void	ft_free_lists_or_list(t_digit *a_stack, ...)
{
	va_list	args;
	t_digit	*current_list;

	va_start(args, a_stack);
	current_list = a_stack;
	while (current_list != NULL)
	{
		ft_free_list(current_list);
		current_list = va_arg(args, t_digit *);
	}
	va_end(args);
}

/**
 * @brief Wrapper function to free lists, print an error message,
	and exit the program.
 * 
 * @param a_stack The head of the stack.
 * @param ... Additional arguments to be passed to ft_free_lists_or_list.
 */
void	super_fail_exit(t_digit *a_stack, ...)
{
	va_list	args;

	va_start(args, a_stack);
	ft_free_lists_or_list(a_stack, args);
	va_end(args);
	ft_error();
	exit(3);
}

//print an error message
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// used for th abov function (ft_free_lists_or_list)
static void	ft_free_list(t_digit *stack)
{
	t_digit	*temp;
	t_digit	*head;

	if (!stack)
		return ;
	head = stack;
	while (stack->next != head)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
}
