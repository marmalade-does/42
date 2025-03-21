#include "../../includes/push_swap.h"


/**
 * @brief Finds the steps to the minimum number in the stack.
 * 
 * @param stack Pointer to the stack.
 * @return int The number of steps to the minimum number.
 */
int	ft_steps_to_min(t_digit **stack)
{
	int		min;
	int		steps_for;
	int		steps_back;
	t_digit	*tmp;

	min = ft_min(stack);
	steps_for = 0;
	steps_back = 0;
	tmp = *stack;
	while (tmp->next && tmp->num != min)
	{
		tmp = tmp->next;
		steps_for++;
	}
	tmp = ft_last(stack);
	while (tmp->prev && tmp->num != min)
	{
		tmp = tmp->prev;
		steps_back--;
	}
	if (steps_back * -1 < steps_for)
		return (steps_back);
	return (steps_for);
}

/**
 * @brief Pushes all elements from stack_b to stack_a.
 * 
 * @param stack_a Pointer to the stack_a.
 * @param stack_b Pointer to the stack_b.
 */
void	ft_mega_push_a(t_digit **stack_a, t_digit **stack_b)
{
	int size;
	int i;

i = 0;
	size = ft_stacksize(stack_b);
	while(i < size)
	{
		ft_pa(stack_a, stack_b);	
		i++;
	}
}

