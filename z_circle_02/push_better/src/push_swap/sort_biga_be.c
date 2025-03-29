#include "../../includes/push_swap_be.h"

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







