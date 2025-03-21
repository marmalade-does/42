#include "../../includes/push_swap.h"

/**
 * @brief Measures the distances for the elements in stack_a and stack_b.
 * 
 * @param stack_a Pointer to the stack_a.
 * @param stack_b Pointer to the stack_b.
 * @param ab_tmp_min Array containing the minimum distances.
 */
void	ft_mesur_dist(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min)
{
    int		num;
    t_digit	*current_a;

    current_a = *stack_a;
    while (current_a != NULL)
    {
        ft_mesur_a(current_a, ab_tmp_min);
        ft_mesur_b(num, *stack_b, ab_tmp_min);
        if (ft_abs(ab_tmp_min[0]) + ft_abs(ab_tmp_min[1]) < ft_abs(ab_tmp_min[2]) + ft_abs(ab_tmp_min[3]))
        {
            ab_tmp_min[2] = ab_tmp_min[0];
            ab_tmp_min[3] = ab_tmp_min[1];
        }
        current_a = current_a->next;
    }
}

/**
 * @brief Finds the insert position for the given number in stack_b.
 * 
 * @param num The number to find the insert position for.
 * @param stack_b Pointer to the stack_b.
 * @return int The relative index of the largest number smaller than num.
 */
int		ft_find_insert_position(int num, t_digit *stack_b)
{
	int largest;
	int rel_i;
	t_digit *current;

	current = stack_b;
	largest = -2147483648;
	while (current->prev != NULL)
		current = current->prev;
	while (current != NULL)
	{
		if (current->num < num && current->num > largest)
			largest = current->num;
		current = current->next;
	}
	rel_i = ft_rel_index_largest(largest, stack_b);
	return (rel_i);
}

/**
 * @brief Finds the relative index of the largest number in stack_b.
 * 
 * @param largest The largest number to find the index for.
 * @param stack_b Pointer to the stack_b.
 * @return int The relative index of the largest number.
 */
int	ft_rel_index_largest(int largest, t_digit *stack_b)
{
	int	stack_size;
	int	dist;
	int abs_dist;

	stack_size = ft_stacksize(stack_b);
	dist = ft_find_dist(largest, stack_b);
	if (dist < 0)
		abs_dist = -dist;
	else
		abs_dist = dist;
	// If dist is larger than half of stack_size, adjust it to the 'opposite' value
	if (abs_dist > stack_size / 2)
	{
		dist = stack_size - dist;
		return (dist * -1);
	}
	return (dist);
}

/**
 * @brief Finds the distance to the largest number in stack_b.
 * 
 * @param largest The largest number to find the distance for.
 * @param stack_b Pointer to the stack_b.
 * @return int The distance to the largest number.
 */
int	ft_find_dist(int largest, t_digit *stack_b)
{
	int		dist_forward;
	int		dist_backward;
	t_digit	*tmp;

	dist_forward = 0;
	dist_backward = 0;
	tmp = stack_b;
	while (tmp->num != largest)
	{
		tmp = tmp->next;
		dist_forward++;
	}
	tmp = stack_b;
	while (tmp->num != largest)
	{
		tmp = tmp->prev;
		dist_backward--;
	}
	if (dist_forward <= (dist_backward * -1))
		return (dist_forward);
	return (dist_backward);
}

// This isn't correct, need to change it so that the.
// Using a simlpe straight doulby linked list.
// nonee of the fancy partially doubly linked list shit.
/**
 * @brief Orients the stack_a to the correct position.
 * 
 * @param stack_a Pointer to the stack_a.
 * @param stack_b Pointer to the stack_b.
 */
void	final_orient(t_digit **stack_a, t_digit **stack_b)
// this isn't correct go and write this as a propper function.
{
	int steps;
	if (!(*stack_a))
	{
		ft_free_lists_or_list(stack_a, stack_b, NULL);
		exit(3);
	}
	steps = ft_steps_to_min(stack_a);
	// ft_find_min returns a positive is ned to go forward,
	//negative iif need to go backwards if (steps == 0)
	{
		ft_free_lists_or_list(stack_a, stack_b);
		exit(0);
	}
	if (steps > 0)
	{
		ft_ra(stack_a);
		steps--;
	}
	else if (steps < 0)
	{
		ft_rra(stack_a);
		steps++;
	}
	ft_free_lists_or_list(stack_a, stack_b);
	exit(0);
}



