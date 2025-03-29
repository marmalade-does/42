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

	min = ft_min(*stack);
	steps_for = 0;
	steps_back = 0;
	tmp = *stack;
	while (tmp->next && tmp->num != min)
	{
		tmp = tmp->next;
		steps_for++;
	}
	tmp = ft_stacklast(*stack);
	while (tmp->prev && tmp->num != min) // might be a mistake here where they need to do one more rotation
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
	int	size;
	int	i;

	i = 0;
	size = ft_stacksize(*stack_b);
	while (i < size)
	{
		ft_pa(stack_a, stack_b);
		i++;
	}
}

void	ft_final_orient(t_digit **stack_a)
{
	int	small;
	int	distance;

	small = ft_min(*stack_a);
	// similar to dst_a functon, but made diifferent to avoid the iint array BS
	distance = ft_dist_min_head(small, *stack_a);
	while (distance < 0)
	{
		ft_rra(stack_a);
		distance++;
	}
	while (distance > 0)
	{
		ft_ra(stack_a);
		distance--;
	}
}

int	ft_dist_min_head(int small, t_digit *stack_a)
{
	int distance_back;    // backwards needs to use rra
	int distance_forward; // forward needs to use ra
	t_digit *from_back;

	distance_back = -1;
	from_back = ft_stacklast(stack_a);
	while (from_back->prev != NULL)
	{
		if (from_back -> num == small)
			break ;
		from_back = from_back->prev;
		distance_back--;
	}
	distance_forward = 0;
	while (stack_a->next != NULL)
	{
		if (stack_a -> num == small)
			break ;
		stack_a = stack_a->next;
		distance_forward++;
	}
	if (distance_back * -1 > distance_forward)
		return (distance_forward);
	return (distance_back);
}

/**
 * @brief Performs rotations on the stack based on the given distance.
 * 
 * @param stack_x Pointer to the stack.
 * @param x Distance to rotate.
 * @param id Identifier for the stack ('a' or 'b').
 */
void	ft_rotations(t_digit **stack_x, int x, char id)
{
	if (x < 0)
	{
		while (x != 0)
		{
			if (id == 'a')
				ft_ra(stack_x);
			else if (id == 'b')
				ft_rb(stack_x);
			x--;
		}
	}
	else if (x > 0)
	{
		while (x != 0)
		{
			if (id == 'a')
				ft_rra(stack_x);
			else if (id == 'b')
				ft_rrb(stack_x);
			x++;
		}
	}
}
