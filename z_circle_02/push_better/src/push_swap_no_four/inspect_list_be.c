#include "../../includes/push_swap.h"

/**
 * @brief Returns the last element of the stack.
 * 
 * @param stack The pointer in the stack (not neceesairly the head).
 * @return t_digit* The last element of the stack.
 */
t_digit	*ft_stacklast(t_digit *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * @brief Returns the first element of the stack.
 * 
 * @param stack A pointer in a stack (not necesairly the head).
 * @return t_digit* The last element of the stack.
 */
t_digit	*ft_stackfirst(t_digit *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

/**
 * @brief Returns the size of the stack.
 * 
 * @param stack The head of the stack.
 * @return int The size of the stack.
 */
int	ft_stacksize(t_digit *stack)
{
	size_t	size;
	t_digit *temp;

	size = 0;
	temp = ft_stackfirst(stack);
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

/**
 * @brief Finds the minimum number in the stack.
 * 
 * @param stack The head of the stack.
 * @return int The minimum number in the stack.
 */
int	ft_min(t_digit *stack)
{
	int	min_value;

	min_value = stack->num;
	while (stack)
	{
		if (stack->num < min_value)
			min_value = stack->num;
		stack = stack->next;
	}
	return (min_value);
}
