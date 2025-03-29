#include "../../includes/push_swap_be.h"

static void	in_cleaning(int argc, char **argv, t_digit *stack_a);
static void ft_free_split_chars(char **chars);

int	main(int argc, char **argv)
{
    t_digit	*stack_a;

    in_cleaning(argc, argv, stack_a);
    if (not_sorted(stack_a))
        ft_sort(&stack_a);
	ft_free_list(stack_a);
	write(1, "happy\n", 6);
    return (0);

/* 	if(ft_stacksize(*stack_a) == 1)
		ft_free_list(*stack_a);
    else
		ft_free_lists_or_list(*stack_a, *stack_b, NULL);
    write(1, "happy\n", 6);
    return (0); */
}

static void	in_cleaning(int argc, char **argv, t_digit *stack_a)
{
    char	**split_chars;

    if (argc <= 1)
    {
        printf("more arguments needed");
        ft_error();
    }
    if (argc == 2)
    {
        split_chars = ft_spliter(argv[1]);
		stack_a = ft_lister(split_chars, argc);
		ft_free_split_chars(split_chars);
	} 
    else
        stack_a = ft_lister(&argv[1], argc);
}

static void ft_free_split_chars(char **chars)
{
	size_t	i;

	if (!chars)
		return;
	i = 0;
	while (chars[i])
	{
		free(chars[i]);
		i++;
	}
	free(chars);
}
