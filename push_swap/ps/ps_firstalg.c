/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_firstalg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:29:58 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:32:10 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_norm_a(t_stack **a, t_stack *tmp, int el, int **flags)
{
	if ((*a)->el > (*a)->next->el && (*a)->next->el > el
		&& (*a)->next->el != el)
		ft_s(a, 'a', 1, flags);
	else if ((*a)->el > tmp->el)
		ft_r(a, 'a', flags);
	else
		ft_rr(a, 'a', flags);
}

void	ft_norm_b(t_stack **b, t_stack **a, int **flags)
{
	int		mod;
	int		r;

	r = 0;
	if (*b)
	{
		mod = ft_deep(*b, ft_find_prev_b(*b, (*a)->el)) <
				ft_deep_rev(*b, ft_find_prev_b(*b, (*a)->el));
		while ((*b)->el != ft_find_prev_b(*b, (*a)->el))
		{
			if (mod)
				ft_r(b, 'b', flags);
			else
				ft_rr(b, 'b', flags);
		}
		if ((*a)->el < ft_find_min(*b))
			r = 1;
	}
	ft_p(b, a, 'b', flags);
	if (r)
		ft_r(b, 'b', flags);
}

void	ft_finalize1(t_stack **a, t_stack **b, int **flags)
{
	t_stack	*tmp;
	int		mod;

	if (!*b)
		return ;
	tmp = *b;
	while (tmp->next != *b)
		tmp = tmp->next;
	mod = ft_deep(*b, ft_find_max(*b)) > ft_deep_rev(*b, ft_find_max(*b));
	while ((*b)->el < tmp->el)
	{
		if (mod)
			ft_rr(b, 'b', flags);
		else
			ft_r(b, 'b', flags);
		while (tmp->next != *b)
			tmp = tmp->next;
	}
	while (*b)
		ft_p(a, b, 'a', flags);
}

void	ft_form1(t_stack **a, t_stack **b, int **flags)
{
	int		el;
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next != *a)
		tmp = tmp->next;
	el = tmp->el;
	while ((*a)->el != el)
	{
		if (ft_check_sort(a, b, el))
			break ;
		if ((*a)->el < el && (*a)->next->el < el && (*a)->next->el < (*a)->el)
			ft_s(a, 'a', 1, flags);
		else if ((*a)->el < el)
			ft_norm_b(b, a, flags);
		else
			ft_norm_a(a, tmp, el, flags);
		while (tmp->next != *a)
			tmp = tmp->next;
	}
	ft_finalize1(a, b, flags);
}
