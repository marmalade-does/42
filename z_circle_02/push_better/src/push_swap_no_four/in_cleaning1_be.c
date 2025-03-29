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


