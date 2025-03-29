#include "../../includes/push_swap.h"

/**
 * @brief Splits a string into an array of words separated by spaces.
 * 
 * @param argv The input string.
 * @return char** The array of words.
 */
char	**ft_spliter(char *argv)
{
	char	**result;

	result = ft_split(argv, ' ');
	if (result == NULL)
	{
		write(1, "split failed", 12);
		ft_error();
		exit(3);
	}
	return (result);
}

/**
 * @brief Checks for repeated numbers in a doubly linked list.
 * 
 * @param head The head of the doubly linked list.
 * @return int 0 if no repeats, -1 if input error, 1 if there is a repeat.
 */
int	ft_check_doubles_list(t_digit *head)
{
	t_digit	*current;
	t_digit	*checker;

	if (!head)
		return (0);
	current = ft_stackfirst(head);
	checker = ft_stackfirst(head);

	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->num == checker->num)
				return (55);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

/**
 * @brief Prints the elements of a doubly linked list.
 * 
 * @param head The head of the doubly linked list.
 * @param in The character to print at the end showeing which stack iit is
 */
void	ft_print_stack(t_digit *head, char in)
{
	t_digit	*current;

	if (!head)
		return ;
	current = ft_stackfirst(head);
	while (current)
	{
		printf("%d\n", current->num);
		current = current->next;
	}
	printf("-\n%c\n\n", in);
}
