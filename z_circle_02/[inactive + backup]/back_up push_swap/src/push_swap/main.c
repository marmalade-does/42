#include "../../includes/push_swap.h"

t_digit	**ft_lister(char **argv);
char	**ft_spliter(char *argv);
static void	in_cleaning(int argc, char **argv, t_digit ***stack_a, t_digit ***stack_b);

int	main(int argc, char **argv)
{
    t_digit	**stack_a;
    t_digit	**stack_b;

    in_cleaning(argc, argv, &stack_a, &stack_b);

    if (not_sorted(stack_a)) // need to make this function
        ft_sort(stack_a, stack_b);
    ft_free_lists_or_list(stack_a, stack_b, NULL);
    write(1, "happy", 5);
    return (0);
}

static void	in_cleaning(int argc, char **argv, t_digit ***stack_a, t_digit ***stack_b)
{
    char	**split_chars;

    if (argc <= 1)
    {
        // printf("more arguments needed");
        // ft_error();
        exit(1);
    }
    if (argc == 2)
    {
        split_chars = ft_spliter(argv[1]); // uses exit in ft_spliter
        *stack_a = ft_lister(split_chars);
    }
    else
    {
        *stack_a = ft_lister(&argv[1]);
        *stack_b = malloc(sizeof(t_digit *) * 1);
        if (*stack_b == NULL)
        {
            ft_free_lists_or_list(*stack_b, *stack_a, NULL);
            ft_error();
            exit(1);
        }
    }
}
// maybe latter just change for ft_algorithm(ft_lister(argv)) because exit in ft_lister means no negat
// * if (ft_lister(argv));
// ft_algorithm(argv);
// inside ft_algorithm make sure you do the ft_error and exit.
