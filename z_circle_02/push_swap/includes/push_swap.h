#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_digit
{
    int			num;
    // int			i; this was a index variable in the oriiginal code, reemoved cause it doesn't do shieee
    struct s_digit	*next;
    struct s_digit	*prev;
}	t_digit;

// main.c


// in_cleaning.c
t_digit	**ft_lister(char **argv);
char **ft_spliter(char *argv);
int	ft_check_doubles_list(t_digit *head);
void    ft_print_stack(t_digit *head, char in);
int     ft_hacked_atoi(const char *str); // Corrected to ft_hacked_atoi

// inpect_list.c
t_digit	*ft_stacklast(t_digit *stack);
int		ft_stacksize(t_digit *stack);
int		ft_min(t_digit *stack);
int		ft_max(t_digit *stack);

// sort.c
void ft_sort(t_digit **stack_a, t_digit **stack_b);


// utils1.c
t_digit *ft_new_digit(int num);
void	ft_error(void);
void ft_free_lists_or_list(t_digit *a_stack, ...);

// push_rotate_utils.c
void		ft_ra(t_digit **stack_a);
void		ft_rb(t_digit **stack_b);
void		ft_sa(t_digit **stack_a);
void		ft_pa(t_digit **stacl_a, t_digit **stack_b);
void		ft_pb(t_digit **stack_a, t_digit **stack_b);
void		ft_rra(t_digit **stack_a);
void		ft_ss(t_digit **stack_a, t_digit **stack_b);
void		ft_rr(t_digit **stack_a, t_digit **stack_b);
void		ft_rrr(t_digit **stack_a, t_digit **stack_b);

//#####################333333333333







void		list_args(char **argv, t_digit **stack_a);
void		ft_add_back(t_digit **stack, t_digit *stack_new);
t_digit		*ft_digit_new(int content);
int			check_args(char **argv);
void		alpha_check(char **argv);
int			check_error(char **argv, int i, int j);
int			ft_checkdup(t_digit *a);
int			ft_isalpha(int c);
int			sign(int c);
int			digit(int c);
int			space(int c);
void		ft_error(void);
t_digit		*ft_stacklast(t_digit *lst);

t_digit		*ft_stacklast(t_digit *lst);
int			ft_stacksize(t_digit *lst);
int			ft_min(t_digit *a);
int			ft_max(t_digit *a);
int			ft_find_index(t_digit *a, int nbr);
int			ft_find_place_b(t_digit *stack_b, int nbr_push);
int			ft_find_place_a(t_digit *a, int nbr);
//void		ft_sort(t_digit **stack_a);
int			ft_checksorted(t_digit *stack_a);
//void		ft_sort_big(t_digit **stack_a);
//void		ft_sort_three(t_digit **stack_a);
t_digit		*ft_parse(int argc, char **argv);
t_digit		*ft_parse_args_quoted(char **argv);
void		ft_freestr(char **lst);
int			ft_case_rarb_a(t_digit *a, t_digit *b, int c);
int			ft_case_rrarrb_a(t_digit *a, t_digit *b, int c);
int			ft_case_rarrb_a(t_digit *a, t_digit *b, int c);
int			ft_case_rrarb_a(t_digit *a, t_digit *b, int c);
int			ft_case_rarb(t_digit *a, t_digit *b, int c);
int			ft_case_rrarrb(t_digit *a, t_digit *b, int c);
int			ft_case_rrarb(t_digit *a, t_digit *b, int c);
int			ft_case_rarrb(t_digit *a, t_digit *b, int c);
int			ft_rotate_type_ab(t_digit *a, t_digit *b);
int			ft_rotate_type_ba(t_digit *a, t_digit *b);
int			ft_apply_rarb(t_digit **a, t_digit **b, int c, char s);
int			ft_apply_rrarrb(t_digit **a, t_digit **b, int c, char s);
int			ft_apply_rrarb(t_digit **a, t_digit **b, int c, char s);
int			ft_apply_rarrb(t_digit **a, t_digit **b, int c, char s);
void		ft_rrb(t_digit **b, int j);
void		ft_check_sub(t_digit **a, t_digit **b, char *line);
char		*ft_check(t_digit **a, t_digit **b, char *line);
void		ft_checker_sub(t_digit **a, t_digit **b, char *line);
t_digit		*ft_process(int argc, char **argv);
void		ft_sb(t_digit **b, int j);
void		algorithm(int argc, char **argv);
void		ft_sort_b_till_3(t_digit **stack_a, t_digit **stack_b);
t_digit		*ft_sub_process(char **argv);
void		ft_error_ch(void);

#endif