#include "../../includes/push_swap.h"

void	ft_mega_push_a(t_digit **stack_a, t_digit **stack_b);

void	ft_sort_big(t_digit **stack_a, t_digit **stack_b)
{
	int *ab_tmp_min;
	 // first two spaces are for temp min, last to for min ab
	ab_tmp_min = (int *)malloc(sizeof(int) * 4);
	ft_bzero(ab_tmp_min, sizeof(int) * 4);
	if (ab_tmp_min == NULL)
	{
		free(ab_tmp_min);
		super_fail_exit(*stack_a, *stack_b, NULL);
	}
	ft_pb(stack_a, stack_b);
	// stack_a comes in knowing that it > 4 and that it's not sorted
	if (ft_stacksize(*stack_a) > 4 && not_sorted(stack_a)) // change this to an && ?
		ft_pb(stack_a, stack_b);
	while (ft_stacksize(*stack_a) > 4 && not_sorted(stack_a))
	{
		ft_mesur_dist(stack_a, stack_b, ab_tmp_min);
		ft_splice_splice(stack_a, stack_b, ab_tmp_min);
	}
	ft_sort_four(stack_a, stack_b);
	// print_stacks_side_by_side(*stack_a, *stack_b);
	ft_mega_push_a(stack_a, stack_b);
	// print_stacks_side_by_side(*stack_a, *stack_b);
	ft_final_orient(stack_a);
	// print_stacks_side_by_side(*stack_a, *stack_b);
	ft_free_lists_or_list(*stack_a, *stack_b, NULL);
	free(ab_tmp_min);
}

/**
 * @brief Performs rotations and pushes the smallest element from stack_a to stack_b.
 * 
 * @param stack_a Pointer to the stack_a.
 * @param stack_b Pointer to the stack_b.
 * @param ab_tmp_min Array containing the minimum distances.
 */
void	ft_splice_splice(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min)
{
	int a;
	int b;
	
	a = ab_tmp_min[2];
	b = ab_tmp_min[3];
	ft_rotations(stack_a, a, 'a');
	ft_rotations(stack_b, b, 'b');
	ft_pb(stack_a, stack_b);
	ab_tmp_min[2] = -2147483647;
	ab_tmp_min[3] = -2147483647;
}

/**
 * @brief Measures the distance for the elements in stack_a.
 * 
 * @param stack_a Pointer to the stack_a.
 * @param ab_tmp_min Array containing the distances.
 */
void	ft_mesur_a(t_digit *stack_a, int *ab_tmp_min)
{
	int distance_back;    // backwards needs to use rra
	int distance_forward; // forward needs to use ra
	distance_back = 0;
	while (stack_a->prev != NULL)
	{
		stack_a = stack_a->prev;
		distance_back++;
	}
	distance_forward = 0;
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		distance_forward--;
	}
	if (distance_back * -1 > distance_forward)
	{
		ab_tmp_min[0] = distance_back;
		return ;
	}
	ab_tmp_min[0] = distance_forward;
	return ;
}

// ngl there is hella redundency in this code, but damm I just want to fnish
/**
 * @brief Measures the distance for the elements in stack_b.
 * 
 * @param num The number to measure the distance for.
 * @param stack_b Pointer to the stack_b.
 * @param ab_tmp_min Array containing the distances.
 */

// this is poop is removed in *_be version.
void	ft_mesur_b(int num, t_digit *stack_b, int *ab_tmp_min)
{
	int		ref_num;

	ref_num = ft_find_insert_position(num, stack_b);
	ab_tmp_min[1] = ref_num;
	return ;
}

