#include "../../includes/push_swap_be.h"

void	ft_sort_big(t_digit **stack_a, t_digit **stack_b)
{
	int *ab_tmp_min;
	 // first two spaces are for temp min, last to for min ab
	ab_tmp_min = (int *)malloc(sizeof(int) * 4);
	ft_bzero(ab_tmp_min, sizeof(int) * 4);

	// initialise b_stack here ??????
	if (ab_tmp_min == NULL)
	{
		free(ab_tmp_min);
		ft_free_list(*stack_a);
		ft_error();
	}
	ft_pb(stack_a, stack_b);
	// stack_a comes in knowing that it > 4 and that it's not sorted
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
	free(ab_tmp_min);
}

