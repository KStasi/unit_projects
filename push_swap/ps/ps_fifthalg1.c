/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fifthalg1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:27:08 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:27:59 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_b(t_stack **a, t_stack **b, int **flags, int mid)
{
	while (*a && mid)
		if ((*a)->el > (*a)->next->el)
			ft_s(a, 'a', 1, flags);
		else
		{
			ft_p(b, a, 'b', flags);
			mid--;
		}
}

void	ft_sort_a(t_stack **a, int **flags)
{
	while (!ft_is_sort_a(*a))
	{
		if ((*a)->el == ft_find_max(*a))
			ft_r(a, 'a', flags);
		else if ((*a)->el > (*a)->next->el)
			ft_s(a, 'a', 1, flags);
		else
			ft_r(a, 'a', flags);
	}
}

void	ft_sort_b(t_stack **b, int **flags)
{
	while (!ft_is_sort_b(*b))
	{
		if ((*b)->el == ft_find_min(*b))
			ft_r(b, 'b', flags);
		else if ((*b)->el < (*b)->next->el)
			ft_s(b, 'b', 1, flags);
		else
			ft_r(b, 'b', flags);
	}
}

void	ft_sort_both(t_stack **a, t_stack **b, int **flags)
{
	while (!ft_is_sort_a(*a) && !ft_is_sort_b(*b))
	{
		if ((*a)->el == ft_find_max(*a))
			ft_r(a, 'a', flags);
		else if ((*b)->el == ft_find_min(*b))
			ft_r(b, 'b', flags);
		else if ((*a)->el > (*a)->next->el && (*b)->el < (*b)->next->el)
			ft_ss(a, b, flags);
		else if ((*a)->el > (*a)->next->el)
			ft_s(a, 'a', 1, flags);
		else if ((*b)->el < (*b)->next->el)
			ft_s(b, 'b', 1, flags);
		else
			ft_r_both(a, b, flags);
	}
	if (!ft_is_sort_a(*a))
		ft_sort_a(a, flags);
	if (!ft_is_sort_b(*b))
		ft_sort_b(b, flags);
}

void	ft_merge(t_stack **a, t_stack **b, int **flags)
{
	t_stack *tmp;

	tmp = *a;
	while (*a && tmp->next != *a)
		tmp = tmp->next;
	while (*a && *b)
	{
		if (tmp->el > (*b)->el)
			ft_rr(a, 'a', flags);
		else
			ft_p(a, b, 'a', flags);
		tmp = *a;
		while (*a && tmp->next != *a)
			tmp = tmp->next;
	}
	while (!ft_is_sort_a(*a))
		ft_rr(a, 'a', flags);
}
