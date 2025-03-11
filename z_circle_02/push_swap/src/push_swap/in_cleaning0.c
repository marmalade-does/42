#include "../../includes/push_swap.h"

static size_t	count_words(const char *str, char delim);

// remember only the argv not including the program name ara passed on
/**
 * @brief Creates a doubly linked list from an array of strings.
 * 
 * @param argv The array of strings.
 * @return t_digit** The head of the doubly linked list.
 */
t_digit	**ft_lister(char **argv)
{
	int		num;
	int		word_count;
	t_digit	**stack_a;
	t_digit	*current;
	t_digit	*temp;

	if (!argv || !argv[0])
		return (NULL);
	word_count = count_words(argv[0], ' ');
	stack_a = malloc(sizeof(t_digit *) * word_count);
	if (word_count == 0 || !stack_a)
	{
		ft_free_lists_or_list(stack_a, NULL);
		ft_error();
		exit(3);
	}
	ft_while_loop(argv, stack_a);
	ft_printf("List, without double check:\n");
	ft_print_stack(*stack_a, 'a');
	if (ft_check_doubles_list(*stack_a) == 55)
		super_fail_exit(*stack_a, NULL);
	return (stack_a);
}

/**
 * @brief Populates a doubly linked list from an array of strings
 * 
 * @param argv The array of strings.
 * @param stack_a The head of the doubly linked list.
 */
void	ft_while_loop(char **argv, t_digit **stack_a)
{
	int		j;
	int		num;
	t_digit	*current;
	t_digit	*temp;

	j = 0;
	num = ft_hacked_atoi(argv[0], stack_a);
	current = ft_new_digit(num);
	if (!current)
		super_fail_exit(*stack_a, NULL);
	*stack_a = current;
	while (argv[j])
	{
		num = ft_hacked_atoi(argv[j], stack_a);
		temp = ft_new_digit(num);
		if (!temp)
			super_fail_exit(*stack_a, NULL);
		current->next = temp;
		temp->prev = current;
		current = temp;
		j++;
	}
}
// need to pass stack_a so that it can be freed if fails.

/**
 * @brief Counts the number of words in a string separated by a delimiter.
 * 
 * @param str The input string.
 * @param delim The delimiter character.
 * @return size_t The number of words in the string.
 */
static size_t	count_words(const char *str, char delim)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == delim)
			str++;
		if (*str && *str != delim)
		{
			count++;
			while (*str != delim && *str)
				str++;
		}
	}
	return (count);
}

/**
 * @brief Converts a string to an integer with error checking.
 * 
 * @param str The input string.
 * @return int The converted integer.
 */
int	ft_hacked_atoi(const char *str, t_list **stack_a)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		super_fail_exit(*stack_a, NULL);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (str[i] != '\0' || res * neg < INT_MIN || res * neg > INT_MAX)
		super_fail_exit(*stack_a, NULL);
	return ((int)(res * neg));
}
