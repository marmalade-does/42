#include "../includes/push_swap.h"

t_digit *create_node(int value);
void append_node(t_digit **head, int value);
void print_stacks_side_by_side(t_digit *stack_a, t_digit *stack_b);
void ft_putnbr_fd(int n, int fd);

int main(void)
{
    t_digit *stack_a = NULL; // Single pointer
    t_digit *stack_b = NULL; // Single pointer

    // Create stack_a with values 1, 2, 3
    append_node(&stack_a, 1); // Pass address of stack_a

    // Create stack_b with values 4, 5, 6
    append_node(&stack_b, 4); // Pass address of stack_b

    // Debug: Print the stacks
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);
/* 
    // Perform operations
    ft_rr(&stack_a, &stack_b); // Pass addresses of stack_a and stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_rrr(&stack_a, &stack_b);
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_ra(&stack_a); // Pass address of stack_a
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_rb(&stack_b); // Pass address of stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_rra(&stack_a); // Pass address of stack_a
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_rrb(&stack_b); // Pass address of stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_sa(&stack_a); // Pass address of stack_a
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_sb(&stack_b); // Pass address of stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_ss(&stack_a, &stack_b); // Pass addresses of stack_a and stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);
 */
    ft_pa(&stack_a, &stack_b); // Pass addresses of stack_a and stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

    ft_pb(&stack_a, &stack_b); // Pass addresses of stack_a and stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

	ft_pb(&stack_a, &stack_b); // Pass addresses of stack_a and stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

	ft_pa(&stack_a, &stack_b); // Pass addresses of stack_a and stack_b
    print_stacks_side_by_side(stack_a, stack_b);
    write(1, "\n", 1);

	// Free the stacks (optional, for cleanup)
    ft_free_lists_or_list(stack_a, stack_b, NULL);

    return (0);
}

// Helper function to create a new node
t_digit *create_node(int value)
{
    t_digit *new_node = malloc(sizeof(t_digit));
    if (!new_node)
        return (NULL);
    new_node->num = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

// Helper function to add a node to the end of a doubly linked list
void append_node(t_digit **head, int value)
{
    t_digit *new_node = create_node(value);
    t_digit *last;

    if (!new_node)
        return;
    if (!*head)
    {
        *head = new_node;
        return;
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

#include "../includes/push_swap.h"

/**
 * @brief Outputs an integer to the standard output.
 * 
 * @param n The integer to output.
 */
void ft_putnbr_fd(int n, int fd)
{
	char c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}



