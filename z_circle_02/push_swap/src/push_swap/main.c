#include "../../includes/push_swap.h"

t_digit **ft_lister(char **argv);
char	**ft_spliter(char *argv);
void	ft_algorithm(char **argv);

int	main(int argc, char **argv)
{
    char	**split_chars;
    t_digit **stack_a;

    if (argc <= 1)
    {
        printf("more arguments needed");
        ft_error();
        exit(1);
    }
    if (argc == 2)
    {
        split_chars = ft_spliter(argv[1]); // uses exit in ft_spliter
        stack_a = ft_lister(split_chars);
    }
    else
        stack_a = ft_lister(&argv[1]);
    // maybe latter just change for ft_algorithm(ft_lister(argv)) because exit in ft_lister means no negatve will be passed up.
    /* if (ft_lister(argv))
        ft_algorithm(argv); // inside ft_algorithm make sure you do the ft_error and exit.
    else
    {
        ft_error();
        exit(3);
    }
    return (0);
 */
	write(1, "happy", 5);
}
