/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:50:25 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 01:50:28 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft.h"

typedef struct		s_stack
{
	int				el;
	struct s_stack	*next;
}					t_stack;

void				ft_crr(t_stack **l);
void				ft_cr(t_stack **l);
void				ft_cs(t_stack **l);
void				ft_cp(t_stack **a, t_stack **b);
void				ft_show_stacks(t_stack *s);
void				ft_try_sort(t_stack **a, t_stack **b, char **ops, int n);
void				ft_free_p(char **p);
int					ft_free_ops(char **ops);
int					ft_check_correct(char **av, int ac);
int					ft_check_range(char *s);
int					ft_check_ops(char **op);
int					ft_check_val(t_stack **a, t_stack **b);
int					ft_ifnum(char **av, int ac);
int					ft_count_ops(char **ops);
int					ft_procced_ops(t_stack **a, t_stack **b);
t_stack				*ft_create_list(char *num);
t_stack				*ft_create_stack(char **av, int ac);
#endif
