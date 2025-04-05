#include "../../includes/push_swap_be.h"

void	ft_sort_big(t_digit **stack_a, t_digit **stack_b)
{
	int ab_tmp_min[4] = {0, 0, 0, 0};
	// first two spaces are for temp min, last to for min ab

	// initialise b_stack here ??????
	ft_pb(stack_a, stack_b);
	// stack_a comes in knowing that it > 3 && not_sorted
	if (ft_stacksize(*stack_a) > 3 && not_sorted(*stack_a)) // change this to an && ?
		ft_pb(stack_a, stack_b);
	while (ft_stacksize(*stack_a) > 3 && not_sorted(*stack_a))
	{
		ft_mesur_dist(stack_a, stack_b, ab_tmp_min); 
		ft_splice_splice(stack_a, stack_b, ab_tmp_min);
	}
	ft_sort_three(stack_a);
	// print_stacks_side_by_side(*stack_a, *stack_b);
	ft_mega_push_a(stack_a, stack_b);
	// print_stacks_side_by_side(*stack_a, *stack_b);
	ft_final_orient(stack_a);
	// print_stacks_side_by_side(*stack_a, *stack_b);
	ft_free_lists_or_list(*stack_a, *stack_b, NULL);
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
}

void	ft_rotations(t_digit **stack_x, int x, char id)
{
	if (x > 0)
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
	else if (x < 0)
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
