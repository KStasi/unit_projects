/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_forthalg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:33:09 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:34:53 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_order(t_stack **a, t_stack **b, int **flags)
{
	if (*a && *b && !((((*a)->el > (*b)->el || (*a)->el < (*b)->next->el)
		&& (*b)->el > (*b)->next->el) || ((*a)->el < (*b)->next->el
		&& (*a)->el > (*b)->el)))
		ft_s(b, 'b', 1, flags);
	ft_p(b, a, 'b', flags);
}

void	ft_float_max(t_stack **b, int **flags)
{
	int		mod;
	int		r;

	r = 0;
	if (*b)
	{
		mod = ft_deep(*b, ft_find_max(*b)) < ft_deep_rev(*b, ft_find_max(*b));
		while ((*b)->el != ft_find_max(*b))
		{
			if (mod)
				ft_r(b, 'b', flags);
			else
				ft_rr(b, 'b', flags);
		}
	}
}

void	ft_push_b(t_stack **a, t_stack **b, int **flags)
{
	int		mod;
	int		r;

	r = 0;
	if (*b && *a)
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
		if (*a && (*a)->el < ft_find_min(*b))
			r = 1;
	}
	ft_p(b, a, 'b', flags);
	if (r)
		ft_r(b, 'b', flags);
}

void	ft_move_to_b(t_stack **a, t_stack **b, int **flags)
{
	while (*a)
	{
		if (*b && (*b)->el == (*b)->next->next->el)
			ft_check_order(a, b, flags);
		else
			ft_push_b(a, b, flags);
	}
	ft_float_max(b, flags);
}

void	ft_form4(t_stack **a, t_stack **b, int **flags)
{
	t_stack *tmp;

	ft_move_to_b(a, b, flags);
	tmp = *a;
	while (*a && tmp->next != *a)
		tmp = tmp->next;
	while (*b && *a && (*b)->el > tmp->el)
		ft_p(a, b, 'a', flags);
	if (*b)
	{
		if (*a)
			ft_rr(a, 'a', flags);
		while (*b)
			ft_p(a, b, 'a', flags);
	}
	tmp = *a;
	while (*a && tmp->next != *a)
		tmp = tmp->next;
	if (*a && (*a)->el > tmp->el)
		ft_rr(a, 'a', flags);
}
