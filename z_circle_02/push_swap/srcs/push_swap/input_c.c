#include "../../includes/push_swap.h"

t_digit	**ft_lister(char **argv); 
char **ft_spliter(char *argv);
int	ft_check_doubles_list(t_digit *head);
void    ft_print_stack(t_digit *head, char in);
int     ft_hacked_atoi(const char *str);


char	**ft_spliter(char *argv)
{
	char	**result;

	result = ft_split(argv, ' ');
	if (result == NULL)
	{
		ft_error();
		exit(3);
	}
	return (result);
}

// remember ony the argv not includinig the program name are passed on.
t_digit	**ft_lister(char **argv)
{
	int		i;
	int		num;
	t_digit	**a_stack;
	t_digit	*current;
	t_digit	*temp;

	num = ft_hacked_atoi(argv[0]);
	current = ft_new_digit(num);
		*a_stack = current;
	i = 1;
	while (argv[i])
	{
		num = ft_hacked_atoi(argv[i]);
			// need to make sure that the ft_hack_atoi does exit() without funny buisness
		temp = ft_new_digit(num);   
			// doesn't need safety check because program will just exit.
		current->next = temp;
		temp->prev = current;
		current = temp;
		i++;
	}
	current->next = *a_stack;
	(*a_stack)->prev = current;
    printf("list, without double check"); // This needs to be change to ft_printf, make sure you get the inicludes ect integrated
    ft_print_stack(*a_stack, 'a');
	ft_check_doubles_list(*a_stack);
	// while loop split them into an array of ints using ft_hack_atoi()
	// if the atoi finds letter, then remove it,
	// also "1 -- 45 32" should mean atoi return error
	// another thing, checks that there are no repeat numbers in the int array
	// return the int array
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

