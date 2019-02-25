/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:13:38 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 00:20:12 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft.h"

typedef struct		s_stack
{
	int				el;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_create_stack(char **av, int ac, int **flags);
t_stack				*ft_cpy_stack(t_stack *a);
t_stack				*ft_create_list(char *num);
void				ft_choose_method(t_stack **a, t_stack **b, int **flags);
void				ft_found_opt(t_stack **a, t_stack **b, int **flags);
void				ft_free_stack(t_stack **a);
void				ft_rr(t_stack **l, char c, int **flags);
void				ft_r(t_stack **l, char c, int **flags);
void				ft_s(t_stack **l, char c, int print, int **flags);
void				ft_ss(t_stack **a, t_stack **b, int **flags);
void				ft_r_both(t_stack **a, t_stack **b, int **flags);
void				ft_p(t_stack **a, t_stack **b, char c, int **flags);
void				ft_push_to_b(t_stack **a, t_stack **b, int **flags,
		int mid);
void				ft_sort_a(t_stack **a, int **flags);
void				ft_sort_b(t_stack **b, int **flags);
void				ft_sort_5a(t_stack **a, t_stack **b, int place,
		int **flags);
void				ft_sort_5b(t_stack **a, t_stack **b, int place,
		int **flags);
void				ft_sort_both(t_stack **a, t_stack **b, int **flags);
void				ft_merge(t_stack **a, t_stack **b, int **flags);
void				ft_merge_two(t_stack **a, t_stack **b, int *range,
		int **flags);
void				ft_merge_all100(t_stack **a, t_stack **b, int **flags);
void				ft_merge_all500(t_stack **a, t_stack **b, int **flags);
void				ft_float_max(t_stack **b, int **flags);
void				ft_push_b(t_stack **a, t_stack **b, int **flags);
void				ft_move_to_b(t_stack **a, t_stack **b, int **flags);
void				ft_show_stacks(t_stack *s, int *flags);
void				ft_show_collor(t_stack *l, char c, int *flags);
void				ft_norm_a(t_stack **a, t_stack *tmp, int el, int **flags);
void				ft_norm_b(t_stack **b, t_stack **a, int **flags);
void				ft_fill_a(t_stack **a, t_stack **b, int n, int **flags);
void				ft_fill_b(t_stack **a, t_stack **b, int n, int **flags);
void				ft_prepare_stack100(t_stack **a, t_stack **b, int **flags);
void				ft_prepare_stack500(t_stack **a, t_stack **b, int **flags);
void				ft_finalize1(t_stack **a, t_stack **b, int **flags);
void				ft_finalize2(t_stack **a, t_stack **b, int **flags);
void				ft_form1(t_stack **a, t_stack **b, int **flags);
void				ft_form2(t_stack **a, t_stack **b, int **flags);
void				ft_form3(t_stack **a, t_stack **b, int **flags);
void				ft_form4(t_stack **a, t_stack **b, int **flags);
void				ft_form5(t_stack **a, t_stack **b, int **flags);
void				ft_form6(t_stack **a, t_stack **b, int **flags);
void				ft_check_order(t_stack **a, t_stack **b, int **flags);
int					ft_set_range(int *range, int a, int b, int c);
int					ft_init_value(t_stack **a, t_stack **b, int *min, int *max);
int					ft_magic(t_stack **a, t_stack **b, int place, int **flags);
int					ft_check_col(int i, char c);
int					ft_check_range(char *s);
int					ft_check_correct(char **av, int ac);
int					ft_check(t_stack *a, t_stack *b);
int					ft_is_flag(char *s);
int					ft_is_num(char **av, int ac);
int					ft_get_fd(char *str, int mod);
int					ft_set_flags(char *flag, int **flags);
int					ft_parse_flags(int i, char **av, int **flags);
int					ft_read_from_file(char ***av, int *i, int *ac, int *flags);
int					ft_get_size(t_stack *a);
int					ft_find_min(t_stack *l);
int					ft_find_max(t_stack *l);
int					ft_deep(t_stack *l, int el);
int					ft_deep_rev(t_stack *l, int el);
int					ft_find_prev_b(t_stack *l, int el);
int					ft_find_prev_a(t_stack *l, int el);
int					ft_check_sort(t_stack **a, t_stack **b, int el);
int					ft_sort_place(t_stack *a, t_stack *b, int place);
int					ft_present_el(t_stack *a, int depth_a, int el);
int					ft_is_reversed(t_stack *a);
int					ft_is_sort_a(t_stack *a);
int					ft_is_sort_b(t_stack *b);
int					ft_find_min5a(t_stack *a, t_stack *b, int depth_a,
		int depth_b);
int					ft_find_max5a(t_stack *a, t_stack *b, int depth_a,
		int depth_b);
int					ft_find_min5b(t_stack *a, t_stack *b, int depth_a,
		int depth_b);
int					ft_find_max5b(t_stack *a, t_stack *b, int depth_a,
		int depth_b);
#endif
