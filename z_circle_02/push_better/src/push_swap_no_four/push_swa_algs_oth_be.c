#include "../../includes/push_swap_be.h"

void	ft_sa(t_digit **stack_a)
{
    t_digit *head;
    t_digit *second;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    head = *stack_a;
    second = head->next;
    head->next = second->next;
    if (second->next) 
        second->next->prev = head;
    second->prev = NULL;
    head->prev = second;
    second->next = head;
    *stack_a = second;
    write(1, "sa\n", 3);
}

void	ft_sb(t_digit **stack_b)
{
    t_digit *head;
    t_digit *second;

    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    head = ft_stackfirst(*stack_b);
    second = head -> next;

    head -> next = second -> next;
    if(second -> next)
        (second -> next) -> prev = head;
    second -> next = head;
    second -> prev = NULL;
    head -> prev = second;

    *stack_b = ft_stackfirst(second);
    write(1, "sb\n", 3);
}

void	ft_ss(t_digit **stack_a, t_digit **stack_b)
{
    t_digit *head_a;
    t_digit *head_b;
    t_digit *second_a;
    t_digit *second_b;

    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    head_a = ft_stackfirst(*stack_a);
    second_a = head_a -> next;
    head_a -> next = second_a -> next;
    if (second_a->next)
        (second_a->next)->prev = head_a;
    second_a -> next = head_a;
    second_a -> prev = NULL;
    head_a -> prev = second_a;

    head_b = ft_stackfirst(*stack_b);
    second_b = head_b -> next;
    head_b -> next = second_b -> next;
    if(second_b -> next)
        (second_b -> next) -> prev = head_b;
    second_b -> next = head_b;
    second_b -> prev = NULL;
    head_b -> prev = second_b;

    *stack_a = ft_stackfirst(*stack_a);
    *stack_b = ft_stackfirst(*stack_b);
    write(1, "ss\n", 3);
}

void	ft_pa(t_digit **stack_a, t_digit **stack_b)
{
    t_digit *head_a;
    t_digit *head_b;

    if (!stack_a)
        return ;
    if (!stack_b || !*stack_b)
        return ;

    head_a = ft_stackfirst(*stack_a);
    head_b = ft_stackfirst(*stack_b);

    *stack_b = head_b->next;
    if (*stack_b)
        (*stack_b)->prev = NULL;

    head_b->next = head_a;
    if (head_a)
        head_a->prev = head_b;

    *stack_a = head_b;

    write(1, "pa\n", 3);
}

// this function is correect / has ben checkd and is good <thumbs up>
void	ft_pb(t_digit **stack_a, t_digit **stack_b)
{
    t_digit *head_a;
    t_digit *head_b;

    if (!stack_a || !*stack_a)
        return ;

    head_a = ft_stackfirst(*stack_a);

    if (!*stack_b)
    {
        *stack_b = head_a;
        *stack_a = head_a->next;
        if (*stack_a)
            (*stack_a)->prev = NULL;
        head_a->next = NULL;
    }
    else
    {
        head_b = ft_stackfirst(*stack_b);
        *stack_b = head_a;
        *stack_a = head_a->next;
        if (*stack_a)
            (*stack_a)->prev = NULL;
        head_a->next = head_b;
        head_b->prev = head_a;
    }

    write(1, "pb\n", 3);
}


