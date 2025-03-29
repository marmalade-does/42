
#include "../../includes/push_swap.h"

static size_t	count_words(const char *str, char delim);

t_digit	*ft_lister(char **argv, int argc)
{
	int		num;
	int		word_count;
	t_digit	*stack_a;

	if (!argv || !argv[0] || argc <= 1)
		return (NULL);
	ft_while_loop(argv, stack_a);
	write(1, "List, without double check:\n", 28); // delete later 
	ft_print_stack(stack_a, 'a'); // delete later
	if (ft_check_doubles_list(stack_a) == 55)
		super_fail_exit(stack_a, NULL);
	return (stack_a);
}

/**
 * @brief Populates a doubly linked list from an array of strings
 * 
 * @param argv The array of strings.
 * @param stack_a The head of the doubly linked list.
 */
int	ft_while_loop(char **argv, t_digit *stack_a)
{
	int		j;
	int		num;
	char 	flag;
	t_digit	*current;
	t_digit	*temp;

	flag = 's';
	current = ft_new_digit(num);
	if (!current)
		return ;
	current -> num = ft_hacked_atoi(argv[0], &flag); // only reason to pass hacked atoi it to fre it in case	
	if(current -> num == -1 && flag == 'f')
		exit (3) ;
	stack_a = current;
	j = 1;
	while (argv[j])
	{
		temp = ft_new_digit(num);
		if (!temp)
			super_fail_exit(stack_a, NULL);
		temp -> num = ft_hacked_atoi(argv[j], &flag);
		if (temp -> num == -1 && flag == 'f')
			super_fail_exit(stack_a, NULL);
		current->next = temp;
		temp->prev = current;
		current = temp;
		j++;
	}
}

/**
 * @brief Converts a string to an integer with error checking.
 * 
 * @param str The input string.
 * @return int The converted integer. If failure, it return -1 and changees the flag to 'f' 
 */
int	ft_hacked_atoi(const char *str, char *flag)
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
	{
		*flag = 'f';
		return (-1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (str[i] != '\0' || res * neg < INT_MIN || res * neg > INT_MAX)
	{
		*flag = 'f';
		return (-1);
	}
	return ((int)(res * neg));
}

// there used to b a function here called "count works" this has ben removed...

