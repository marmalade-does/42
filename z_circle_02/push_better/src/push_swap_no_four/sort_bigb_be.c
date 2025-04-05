#include "../../includes/push_swap_be.h"

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
	distance = ft_rel_index_largest(small, *stack_a);
	ft_rotations(stack_a, distance, 'a');
}
