
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Struct Definition
typedef struct s_digit
{
	int				num;
	struct s_digit	*next;
	struct s_digit	*prev;
}					t_digit;

/////////////////////////////// Function Prototypes
///////////////////////////////

// main.c

// static void	in_cleaning(void);

// in_cleaning0.c
t_digit	*ft_lister(char **argv, int argc);
int	ft_while_loop(char **argv, t_digit *stack_a);
int	ft_hacked_atoi(const char *str, char *flag);

// in_cleaning1.c
char				**ft_spliter(char *argv);
int					ft_check_doubles_list(t_digit *head);
void				ft_print_stack(t_digit *head, char in);

// inspect_list.c
t_digit				*ft_stacklast(t_digit *stack);
t_digit				*ft_stackfirst(t_digit *stack);
int					ft_stacksize(t_digit *stack);
int					ft_min(t_digit *stack);
int					ft_max(t_digit *stack);

// sort_main.c
void	ft_sort_u_five(t_digit **stack_a, t_digit **stack_b, int a_len);
void	ft_sort(t_digit *stack_a);

////////////

// sort_big.c
void	ft_sort_big(t_digit **stack_a, t_digit **stack_b);
void	ft_splice_splice(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min);
void	ft_mesur_a(t_digit *stack_a, int *ab_tmp_min);
void	ft_mesur_b(int num, t_digit *stack_b, int *ab_tmp_min);

// sort_biga.c
void	ft_mesur_dist(t_digit **stack_a, t_digit **stack_b, int *ab_tmp_min);
int		ft_find_insert_position(int num, t_digit *stack_b);
int		ft_rel_index_largest(int largest, t_digit *stack_b);
int		ft_find_dist(int largest, t_digit *stack_b);

// sort_bigb.c
int		ft_steps_to_min(t_digit **stack);
void	ft_mega_push_a(t_digit **stack_a, t_digit **stack_b);
void	ft_final_orient(t_digit **stack_a);
int		ft_dist_min_head(int small, t_digit *stack_a);
void	ft_rotations(t_digit **stack_x, int x, char id);

//////////

// utils0.c
void	ft_free_lists_or_list(t_digit *a_stack, ...);
void	super_fail_exit(t_digit *a_stack, ...);
void	ft_free_list(t_digit *stack);
void	ft_error(void);
// static void	ft_free_list(t_digit *stack)

// utils1.c
t_digit				*ft_new_digit(int num);
long				ft_abs(int num);
char				**ft_split(char const *str, char delim);
// static size_t	word_len(const char *str, char delim)
// static size_t	count_words(const char *str, char delim)

// utils2.c
char	*ft_read_perm(t_digit **stack);

// static void order_to_string(int *order, char *result)
// static void determine_order(int *values, int *order)
// static void extract_values(t_digit **stack, int *values)

// utils3.c
int not_sorted(t_digit *stack);
/* int	ft_strncmp(const char *s1, const char *s2, size_t n);
void print_stacks_side_by_side(t_digit *stack_a, t_digit *stack_b);
int		not_sorted(t_digit **stack);
 */

// push_swa_*
void				ft_ra(t_digit **stack_a);
void				ft_rb(t_digit **stack_b);
void	ft_sa(t_digit **stack_a);
void	ft_sb(t_digit **stack_b);
void	ft_pa(t_digit **stack_a, t_digit **stack_b);
void	ft_pb(t_digit **stack_a, t_digit **stack_b);
void	ft_rra(t_digit **stack_a);
void	ft_rrb(t_digit **stack_b);
void	ft_ss(t_digit **stack_a, t_digit **stack_b);
void	ft_rr(t_digit **stack_a, t_digit **stack_b);
void	ft_rrr(t_digit **stack_a, t_digit **stack_b);

///////////////////////////////


// sort_three.c
void	ft_sort_three(t_digit **stack_a);

// sort_four.c
void	ft_sort_four(t_digit **stack_a, t_digit **stack_b);
void	ft_sort_four_1(t_digit **stack_a, t_digit **stack_b, char *perm_str);
void	ft_sort_four_2(t_digit **stack_a, t_digit **stack_b, char *perm_str);
void	ft_sort_four_3(t_digit **stack_a, t_digit **stack_b, char *perm_str);
void	ft_sort_four_4(t_digit **stack_a, t_digit **stack_b, char *perm_str);

// sort_four_algs/z_1_algs.c
void				ft_sort_1243(t_digit **stack_a);
void				ft_sort_1342(t_digit **stack_a);
void				ft_sort_1324(t_digit **stack_a);
void				ft_sort_1423(t_digit **stack_a);
void				ft_sort_1432(t_digit **stack_a, t_digit **stack_b);

// sort_four_algs/z_2_algs.c
void				ft_sort_2341(t_digit **stack_a);
void				ft_sort_2413(t_digit **stack_a);
void				ft_sort_2431(t_digit **stack_a);

// sort_four_algs/z_2.1_algs.c
void				ft_sort_2134(t_digit **stack_a);
void				ft_sort_2143(t_digit **stack_a, t_digit **stack_b);
void				ft_sort_2314(t_digit **stack_a, t_digit **stack_b);

// sort_four_algs/z_3_algs.c
void				ft_sort_3241(t_digit **stack_a);
void				ft_sort_3412(t_digit **stack_a);
void				ft_sort_3421(t_digit **stack_a);

// sort_four_algs/z_3.1_algs.c
void				ft_sort_3124(t_digit **stack_a);
void				ft_sort_3142(t_digit **stack_a);
void				ft_sort_3214(t_digit **stack_a, t_digit **stack_b);

// sort_four_algs/z_4_algs.c
void				ft_sort_4231(t_digit **stack_a);
void				ft_sort_4312(t_digit **stack_a);
void				ft_sort_4321(t_digit **stack_a);

// sort_four_algs/z_4.1_algs.c
void				ft_sort_4123(t_digit **stack_a);
void				ft_sort_4132(t_digit **stack_a);
void				ft_sort_4213(t_digit **stack_a);

#endif
