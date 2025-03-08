#include "../../includes/push_swap.h"

t_digit	**ft_lister(char **argv); 
char **ft_spliter(char *argv);
int	ft_check_doubles_list(t_digit *head);
void    ft_print_stack(t_digit *head, char in);
int     ft_hacked_atoi(const char *str);
static size_t	count_words(const char *str, char delim);

/*TODO: 
  * printf() -> ft_printf()
  * 
*/


char	**ft_spliter(char *argv)
{
	char	**result;

	result = ft_split(argv, ' ');
	if (result == NULL)
	{
		printf("split failed");
		ft_error();
		exit(3);
	}
	return (result);
}

// remember only the argv not includinig the program name are passed on.
t_digit	**ft_lister(char **argv)
{
	int			i;
	int			num;
	int			word_count;
	t_digit		**a_stack;
	t_digit		*current;
	t_digit		*temp;

	if (!argv || !argv[0])
		return (NULL);
	word_count = count_words(argv[0], ' ');
	if (word_count == 0)
		return (NULL);
	a_stack = malloc(sizeof(t_digit *) * word_count);
	if (!a_stack)
		return (NULL);
	num = ft_hacked_atoi(argv[0]);
	current = ft_new_digit(num);
	if (!current)
	{
		ft_free_lists_or_list(*a_stack);
		ft_error();
		exit(3);
	}
	*a_stack = current;
	i = 1;
	while (argv[i])
	{
		num = ft_hacked_atoi(argv[i]);
		// need to make sure that the fT_hack_atoi does exit () without funny buisness
		temp = ft_new_digit(num);
		// doesn't need safety chck becuase program will just exit
		if (!temp)
		{
			ft_free_lists_or_list(*a_stack);
			exit (3);
		}
		current->next = temp;
		temp->prev = current;
		current = temp;
		i++;
	}
	current->next = *a_stack;
	(*a_stack)->prev = current;
	printf("List, without double check:\n"); // This neds to be changed to ft_printf .. make sure you integrate the includes and stuff
	ft_print_stack(*a_stack, 'a');
	ft_check_doubles_list(*a_stack);
	return (a_stack);
	// while loop split them into an array of ints using ft_hack_atoi()
	// if the atoi finds letter, then remove it,
	// also "1 -- 45 32" should mean atoi return error
	// another thing, checks that there are no repeat numbers in the int array
	// return the int array
}


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


// void ft_hack_atoi

// checks for repeated numbers on the linked list.
// return 0 if no repeats
// -1 if input error
// 1 if there is a repeat
int	ft_check_doubles_list(t_digit *head)
{
	t_digit	*current;
	t_digit	*checker;

	if (!head)
	{
		printf("bad head value input into ft_check_doubles_list");
		ft_error();
		exit(3);
	}
	current = head;
	while (current)
	{
		checker = current->next;
		while (checker && checker != head)
		{
			if (current->num == checker->num)
			{
				printf("There was a repeat number in the input");
				ft_error();
				exit(3);
			}
			checker = checker->next;
		}
		current = current->next;
		if (current == head)
			break ;
	}
	return (0);
}

int	ft_hacked_atoi(const char *str)
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
        printf("number input begins with char");
		ft_error();
        exit(3);
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (str[i] - '0') + (res * 10);
        i++;
    }
    if (str[i] != '\0' || res * neg < INT_MIN || res * neg > INT_MAX)
    {
        printf("non-digit chars at end of token");
		ft_error();
        exit(3);
    }
    return ((int)(res * neg));
}

void	ft_print_stack(t_digit *head, char in)
{
    t_digit	*current;

    if (!head)
        return ;
    current = head;
    while (1)
    {
        printf("%d\n", current->num); // need to change this to ft_printf(), geneerally need to make sure libs and includees are integrated
        current = current->next;
        if (current == head)
            break;
    }
    printf("-\n%c\n", in); // need to change this to ft_printf(), geneerally need to make sure libs and includees are integrated
}

