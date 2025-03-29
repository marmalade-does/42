#include "../../includes/push_swap.h"

void	ft_free_list(t_digit *stack);

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
	t_digit	*current_list;

	va_start(args, a_stack);
	current_list = a_stack;
	while (current_list != NULL)
	{
		ft_free_list(current_list);
		current_list = va_arg(args, t_digit *);
	}
	va_end(args);
	ft_error();
}

//print an error message
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(3);
}

// used for th abov function (ft_free_lists_or_list)
void	ft_free_list(t_digit *stack)
{
	t_digit	*temp;
	t_digit	*head;

	if (!stack)
		return ;
	head = stack;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	// free(stack); -- this is a double free ?
