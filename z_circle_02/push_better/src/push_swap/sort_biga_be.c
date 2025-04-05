#include "../../includes/push_swap_be.h"

void	ft_mesur_dist(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min)
{
    int		num;
    t_digit	*current_a;

    current_a = *stack_a;
	ft_mesur_a(current_a, ab_tmp_min); // this and everything it calls is correct
    ft_mesur_b(current_a -> num, *stack_b, ab_tmp_min); // this and everything it calls is correct
	ab_tmp_min[2] = ab_tmp_min[0];
	ab_tmp_min[3] = ab_tmp_min[1];    
    while (current_a != NULL)// this is actually repeatd -- but hey who give af
    {
        ft_mesur_a(current_a, ab_tmp_min); // this and everything it calls is correct
        ft_mesur_b(current_a -> num, *stack_b, ab_tmp_min); // this and everything it calls is correct
        if (ft_abs(ab_tmp_min[0]) + ft_abs(ab_tmp_min[1]) < ft_abs(ab_tmp_min[2]) + ft_abs(ab_tmp_min[3]))
        {
            ab_tmp_min[2] = ab_tmp_min[0];
            ab_tmp_min[3] = ab_tmp_min[1];
        }
        current_a = current_a->next;
    }
}

/**
 * @brief Measures the distance from teh head or tail that elem stack_a is.
 * 
 * @param stack_a Pointer to the stack_a.
 * @param ab_tmp_min Array containing the distances.
 */
void	ft_mesur_a(t_digit *stack_a, int *ab_tmp_min)
{
	int distance_back;    // backwards needs to use rra
	int distance_forward; // forward needs to use ra
	t_digit *tmp;

	tmp = stack_a;
	distance_back = 0;
	tmp = ft_stackfirst(stack_a);
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		distance_back++;
	}
	distance_forward = 0;
	tmp = ft_stacklast(stack_a);
	while (tmp != NULL) // bcause you actually ned to move it to the top position (do that extra rotate to put it on top)
	{
		tmp = tmp->next;
		distance_forward--;
	}
	if (distance_back * -1 > distance_forward)
		ab_tmp_min[0] = distance_back;
	else
		ab_tmp_min[0] = distance_forward;
	return ;
}

// ngl there is hella redundency in this code, but damm I just want to fnish
/**
 * @brief Measures the distance for the elements in stack_b and finds the insert position.
 * 
 * @param num The number to measure the distance for.
 * @param stack_b Pointer to the stack_b.
 * @param ab_tmp_min Array containing the distances.
 */
void	ft_mesur_b(int num, t_digit *stack_b, int *ab_tmp_min)
{
    int		largest;
    int		rel_i;

    largest = ft_largest_min(stack_b, num);
    rel_i = ft_rel_index_largest(largest, stack_b);
    ab_tmp_min[1] = rel_i;
}

int ft_largest_min(t_digit *stack_b, int num)
{
	int largest;
	t_digit *current;

    current = ft_stackfirst(stack_b);
    largest = -2147483648;
    while (current != NULL)
    {
        if (current->num < num && current->num > largest)
            largest = current->num;
        current = current->next;
    }
	return (current);
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
	t_digit	*tmp;
	int		dist_back;    // backwards needs to use rra
	int		dist_forward; // forward needs to use ra


	tmp = ft_stackfirst(stack_b);
	dist_forward = 0;
	while (tmp->num != largest)
	{
		tmp = tmp->next;
		dist_forward++;
	}
	tmp = ft_stacklast(stack_b);
	dist_back = -1;
	while (tmp->num != largest)
	{
		tmp = tmp->prev;
		dist_back--;
	}
	if (dist_forward <= (dist_back * -1))
		return (dist_forward);
	return (dist_back);
}
