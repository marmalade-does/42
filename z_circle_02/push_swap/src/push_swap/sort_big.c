#include "../../includes/push_swap.h"

void	ft_mega_push_a(t_digit **stack_a, t_digit **stack_b);
void	ft_splice_splice(t_digit **stack_a, t_digit **stack_b, int *index_ptr);
void	ft_mesur_dist(t_digit **stack_a, t_digit **stack_b, int *ab);
int		ft_is_sorted(t_digit **stack);

void	ft_sort_big(t_digit **stack_a, t_digit **stack_b)
{
	int		a_len;
	int		min_dist;
	int		*ab_tmp_min;
	t_list	**tmp_stack_a;

	ab_tmp_min = (int)malloc(sizeof(int) * 4);
	ft_bzero(ab_tmp_min, sizeof(int) * 4);
	if (ab_tmp_min == NULL)
	{
		free(ab_tmp_min);
		ft_free_lists_or_list(stack_a, stack_b, NULL);
		exit(3);
	}
	min_dist = 0;
	ft_pb(stack_a, stack_b);
	// stack_a comes in knowing that it > 4 and that it's not sorted
	if (ft_stacksize(stack_a) > 4 || !(ft_is_sorted(stack_a)))
		ft_pb(stack_a, stack_b);
	while (ft_stacksize(tmp_stack_a) > 4 && !(ft_is_sorted(stack_a)))
	{
		ft_mesur_dist(tmp_stack_a, stack_b, ab_tmp_min);
		//(*tmp_stack_a) = (*tmp_stack_a) -> next;
		ft_splice_splice(stack_a, stack_b, ab_tmp_min);
	}
	ft_mega_push_a(stack_a, stack_b);
	ft_final_orient(stack_a);
	ft_free_lists_or_list(stack_a, stack_b, NULL);
	free(ab_tmp_min);
}

void	ft_mesur_dist(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min)
{
	int	num;

	num = ((*stack_a)->num);
	{
		ft_mesur_a(stack_a, ab_tmp_min);
		// and some mechanism to see what the head is?
		ft_mesur_b(num, stack_b, ab_tmp_min);
	}
}

void	ft_mesur_a(t_digit **stack_a, int *ab_tmp_min)
{
	/*some way to measure how far this is from the mouth*/
}

void	ft_mesur_b(int num, t_digit **stack_b, int *ab_tmp_min)
{
	int		*rl_pos;
	int		large;
	int		i;
	t_digit	*tmp;

	rl_pos = (int *)malloc(sizeof(int) * 2);
	i = ft_stacksize((*stack_b)) / 2;
	i++;
	tmp = (*stack_b);
	while (i > 0)
	{
		if (((*stack_b)->next)->num <)
			(*stack_b) = (*stack_b)->next;
		i--;
	}
	tmp = (*stack_b);
	while (i > 0)
	{
		if (((*stack_b)->next)->num <)
			(*stack_b) = (*stack_b)->next;
		i--;
	}
	/*find the biggest number that is smaller than num*/
	/*see if forward of backwards is quicker (by dividing by MAX)*/
}
int	ft_find_insert_position(int *sorted_array, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (num < sorted_array[i])
			return (i);
		i++;
	}
	return (size);
}


///////////////////////////////////////////////////// THIS FUNCTION IS NOT FOLOWNG THE 42 NORM
int	ft_bble_pos(t_digit **ptr, int num)
{
	int		*sorted_array;
	int		insert_position;
	int		size;
	t_digit	*current;
	int		i;
	int		j;
	int		temp;

	size = ft_stacksize(*ptr);
	sorted_array = (int *)malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		ft_free_lists_or_list(ptr, NULL, NULL);
		exit(3);
	}
	current = *ptr;
	i = 0;
	while (i < size)
	{
		sorted_array[i] = current->num;
		current = current->next;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sorted_array[j] > sorted_array[j + 1])
			{
				temp = sorted_array[j];
				sorted_array[j] = sorted_array[j + 1];
				sorted_array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	insert_position = ft_find_insert_position(sorted_array, size, num);
	free(sorted_array);
	return (insert_position);
}





//////////////////////////////////////////


void	final_orient(t_digit **stack_a, t_digit **stack_b)
// this isn't correct go and write this as a propper function.
{
	int steps;
	if (!(*stack_a))
	{
		ft_free_lists_or_list(stack_a, stack_b, NULL);
		exit(3);
	}
	steps = ft_steps_to_min(stack_a);
	// ft_find_min returns a positive is ned to go forward,
	negative iif need to go backwards if (steps == 0)
	{
		ft_free_lists_or_list(stack_a, stack_b);
		exit(0);
	}
	if (steps > 0)
	{
		ft_ra(stack_a);
		steps--;
	}
	else if (steps < 0)
	{
		ft_rra(stack_a);
		steps++;
	}
	ft_free_lists_or_list(stack_a, stack_b);
	exit(0);
}

int	ft_steps_to_min(t_digit **stack)
{
	int		min;
	int		steps_for;
	int		steps_back;
	t_digit	*tmp;

	min = ft_min(stack);
	steps_for = 0;
	steps_back = 0;
	tmp = *stack;
	while (tmp->next && tmp->num != min)
	{
		tmp = tmp->next;
		steps_for++;
	}
	tmp = ft_last(stack);
	while (tmp->prev && tmp->num != min)
	{
		tmp = tmp->prev;
		steps_back--;
	}
	if (steps_back * -1 < steps_for)
		return (steps_back);
	return (steps_for);
}
