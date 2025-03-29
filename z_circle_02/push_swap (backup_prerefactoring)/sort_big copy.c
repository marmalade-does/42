#include "includes/push_swap.h"

void	ft_mega_push_a(t_digit **stack_a, t_digit **stack_b);
void	ft_splice_splice(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min);
void	ft_mesur_dist(t_digit **stack_a, t_digit **stack_b, int *ab);
int		ft_is_sorted(t_digit **stack);

void	ft_sort_big(t_digit **stack_a, t_digit **stack_b)
{
	int *ab_tmp_min;
	 // first two spaces are for temp min, last to for min ab
	ab_tmp_min = (int)malloc(sizeof(int) * 4);
	ft_bzero(ab_tmp_min, sizeof(int) * 4);
	if (ab_tmp_min == NULL)
	{
		free(ab_tmp_min);
		ft_free_lists_or_list(*stack_a, *stack_b, NULL);
		exit(3);
	}
	ft_pb(stack_a, stack_b);
	// stack_a comes in knowing that it > 4 and that it's not sorted
	if (ft_stacksize(stack_a) > 4 || !(ft_is_sorted(stack_a)))
		ft_pb(stack_a, stack_b);
	while (ft_stacksize(stack_a) > 4 && !(ft_is_sorted(stack_a)))
	{
		ft_mesur_dist(stack_a, stack_b, ab_tmp_min);
		ft_splice_splice(stack_a, stack_b, ab_tmp_min);
	}
	ft_sort_four(stack_a, stack_b);
	ft_mega_push_a(stack_a, stack_b);
	ft_final_orient(stack_a); // ft_final_orient doesn't exist? 
	ft_free_lists_or_list(*stack_a, *stack_b, NULL);
	free(ab_tmp_min);
}

void	ft_splice_splice(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min)
{
	int a;
	int b;
	
	a = ab_tmp_min[2];
	b = ab_tmp_min[3];
	ft_rotations(stack_a, a, 'a');
	ft_rotations(stack_b, b, 'b');
	ft_pb(stack_a, stack_b);
	ab_tmp_min[2] = -2147483647;
	ab_tmp_min[3] = -2147483647;
}

void ft_rotations(t_digit **stack_x, int x, char id)
{
	if(x > 0)
	{
		while(x != 0)
		{
			if(id == 'a')
				ft_ra(stack_x);
			else if(id == 'b')
				ft_rb(stack_x);
			x--;
		}
	}
	if(x < 0)
	{
		while(x != 0)
		{
			if(id == 'a')
				ft_rra(stack_x);
			else if(id == 'b')
				ft_rrb(stack_x);
			x++;
		}
	}
}

void	ft_mesur_dist(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min)
{
    int		num;
    t_digit	*current_a;

    current_a = *stack_a;
    while (current_a != NULL)
    {
        ft_mesur_a(current_a, ab_tmp_min);
        ft_mesur_b(num, *stack_b, ab_tmp_min);
        if (ft_abs(ab_tmp_min[0]) + ft_abs(ab_tmp_min[1]) < ft_abs(ab_tmp_min[2]) + ft_abs(ab_tmp_min[3]))
        {
            ab_tmp_min[2] = ab_tmp_min[0];
            ab_tmp_min[3] = ab_tmp_min[1];
        }
        current_a = current_a->next;
    }
}

// function assumes a singly linkeed list ->> good this assumption is correct

void	ft_mesur_a(t_digit *stack_a, int *ab_tmp_min)
{
	int distance_back;    // backwards needs to use rra
	int distance_forward; // forward needs to use ra
	distance_back = 0;
	while (stack_a->prev != NULL)
	{
		stack_a = stack_a->prev;
		distance_back++;
	}
	distance_forward = 0;
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		distance_forward--;
	}
	if (distance_back * -1 > distance_forward)
	{
		ab_tmp_min[0] = distance_back;
		return ;
	}
	ab_tmp_min[0] = distance_forward;
	return ;
}


// ngl there is hella redundency in this code, but damm I just want to finish
void	ft_mesur_b(int num, t_digit *stack_b, int *ab_tmp_min)
{
	int		ref_num;

	ref_num = ft_find_insert_position(num, stack_b);
	ab_tmp_min[1] = ref_num;
	return ;
}

int		ft_find_insert_position(int num, t_digit *stack_b)
{
	int largest;
	int rel_i;
	t_digit *current;

	current = stack_b;
	largest = -2147483648;
	while (current->prev != NULL)
		current = current->prev;
	while (current != NULL)
	{
		if (current->num < num && current->num > largest)
			largest = current->num;
		current = current->next;
	}
	rel_i = ft_rel_index_largest(largest, stack_b);
	return (rel_i);
}

int	ft_rel_index_largest(int largest, t_digit *stack_b)
{
	int	stack_size;
	int	dist;
	int abs_dist;

	stack_size = ft_stacksize(stack_b);
	dist = ft_find_dist(largest, stack_b);
	if (dist < 0)
		abs_dist = -dist;
	else
		abs_dist = dist;
	// If dist is larger than half of stack_size, adjust it to the 'opposite' value
	if (abs_dist > stack_size / 2)
	{
		dist = stack_size - dist;
		return (dist * -1);
	}
	return (dist);
}

int	ft_find_dist(int largest, t_digit *stack_b)
{
	int		dist_forward;
	int		dist_backward;
	t_digit	*tmp;

	dist_forward = 0;
	dist_backward = 0;
	tmp = stack_b;
	while (tmp->num != largest)
	{
		tmp = tmp->next;
		dist_forward++;
	}
	tmp = stack_b;
	while (tmp->num != largest)
	{
		tmp = tmp->prev;
		dist_backward--;
	}
	if (dist_forward <= (dist_backward * -1))
		return (dist_forward);
	return (dist_backward);
}

// This isn't correct, need to change it so that the.
// Using a simlpe straight doulby linked list.
// nonee of the fancy partially doubly linked list shit.
void	final_orient(t_digit **stack_a, t_digit **stack_b)
// this isn't correct go and write this as a propper function.
{
	int steps;
	if (!(*stack_a))
	{
		ft_free_lists_or_list(*stack_a, *stack_b, NULL);
		exit(3);
	}
	steps = ft_steps_to_min(stack_a);
	// ft_find_min returns a positive is ned to go forward,
	//negative iif need to go backwards if (steps == 0)
	{
		ft_free_lists_or_list(*stack_a, *stack_b);
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
	ft_free_lists_or_list(*stack_a, *stack_b, NULL);
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

void	ft_mega_push_a(t_digit **stack_a, t_digit **stack_b)
{
	int size;
	int i;

	size = ft_stacksize(stack_b);
	while(i < size)
	{
		ft_pa(stack_a, stack_b);	
		i++;
	}
}

