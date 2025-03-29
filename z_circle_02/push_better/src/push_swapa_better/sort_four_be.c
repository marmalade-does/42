#include "../../includes/push_swap_be.h"

void	ft_sort_four(t_digit **stack_a, t_digit **stack_b)
{
    char	*perm_str;

    if (!(not_sorted(*stack_a)))
        return ;
    perm_str = ft_read_perm(*stack_a); // need to fix read perm here
    if (perm_str[0] == '1')
        ft_sort_four_1(stack_a, stack_b, perm_str);
    else if (perm_str[0] == '2')
        ft_sort_four_2(stack_a, stack_b, perm_str);
    else if (perm_str[0] == '3')
        ft_sort_four_3(stack_a, stack_b, perm_str);
    else if (perm_str[0] == '4')
        ft_sort_four_4(stack_a, stack_b, perm_str);
}

void	ft_sort_four_1(t_digit **stack_a, t_digit **stack_b, char *perm_str)
{
    if (ft_strncmp(perm_str, "1234", 4) == 0)
        return ;
    else if (ft_strncmp(perm_str, "1243", 4) == 0)
        ft_sort_1243(stack_a);
    else if (ft_strncmp(perm_str, "1324", 4) == 0)
        ft_sort_1324(stack_a);
    else if (ft_strncmp(perm_str, "1342", 4) == 0)
        ft_sort_1342(stack_a);
    else if (ft_strncmp(perm_str, "1423", 4) == 0)
        ft_sort_1423(stack_a);
    else if (ft_strncmp(perm_str, "1432", 4) == 0)
        ft_sort_1432(stack_a, stack_b);
}

// Functions for ft_sort_four_2 permutations
void	ft_sort_four_2(t_digit **stack_a, t_digit **stack_b, char *perm_str)
{
    if (ft_strncmp(perm_str, "2134", 4) == 0)
        ft_sort_2134(stack_a);
    else if (ft_strncmp(perm_str, "2143", 4) == 0)
        ft_sort_2143(stack_a, stack_b);
    else if (ft_strncmp(perm_str, "2314", 4) == 0)
        ft_sort_2314(stack_a, stack_b);
    else if (ft_strncmp(perm_str, "2341", 4) == 0)
        ft_sort_2341(stack_a);
    else if (ft_strncmp(perm_str, "2413", 4) == 0)
        ft_sort_2413(stack_a);
    else if (ft_strncmp(perm_str, "2431", 4) == 0)
        ft_sort_2431(stack_a);
}

// Functions for ft_sort_four_3 permutations
void	ft_sort_four_3(t_digit **stack_a, t_digit **stack_b, char *perm_str)
{
    if (ft_strncmp(perm_str, "3124", 4) == 0)
        ft_sort_3124(stack_a);
    else if (ft_strncmp(perm_str, "3142", 4) == 0)
        ft_sort_3142(stack_a);
    else if (ft_strncmp(perm_str, "3214", 4) == 0)
        ft_sort_3214(stack_a, stack_b);
    else if (ft_strncmp(perm_str, "3241", 4) == 0)
        ft_sort_3241(stack_a);
    else if (ft_strncmp(perm_str, "3412", 4) == 0)
        ft_sort_3412(stack_a);
    else if (ft_strncmp(perm_str, "3421", 4) == 0)
        ft_sort_3421(stack_a);
}

void	ft_sort_four_4(t_digit **stack_a, t_digit **stack_b, char *perm_str)
{
    if (ft_strncmp(perm_str, "4123", 4) == 0)
        ft_sort_4123(stack_a);
    else if (ft_strncmp(perm_str, "4132", 4) == 0)
        ft_sort_4132(stack_a);
    else if (ft_strncmp(perm_str, "4213", 4) == 0)
        ft_sort_4213(stack_a);
    else if (ft_strncmp(perm_str, "4231", 4) == 0)
        ft_sort_4231(stack_a);
    else if (ft_strncmp(perm_str, "4312", 4) == 0)
        ft_sort_4312(stack_a);
    else if (ft_strncmp(perm_str, "4321", 4) == 0)
        ft_sort_4321(stack_a);
}



