/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:37:35 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:38:10 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_prev_b(t_stack *l, int el)
{
	t_stack *tmp;
	int		prev;

	tmp = l;
	prev = (l->el < el) ? l->el : ft_find_min(l);
	tmp = tmp->next;
	while (tmp != l)
	{
		if (tmp->el > prev && tmp->el < el)
			prev = tmp->el;
		tmp = tmp->next;
	}
	if (el < ft_find_min(l) || el > ft_find_max(l))
		return (ft_find_max(l));
	return (prev);
}

int	ft_find_prev_a(t_stack *l, int el)
{
	t_stack *tmp;
	int		prev;

	tmp = l;
	prev = (l->el < el) ? l->el : ft_find_min(l);
	tmp = tmp->next;
	while (tmp != l)
	{
		if (tmp->el > prev && tmp->el < el)
			prev = tmp->el;
		tmp = tmp->next;
	}
	if (el < ft_find_min(l) || el > ft_find_max(l))
		return (ft_find_max(l));
	return (prev);
}

int	ft_check_sort(t_stack **a, t_stack **b, int el)
{
	t_stack *tmp;

	if (ft_find_max(*b) > ft_find_min(*a))
		return (0);
	tmp = *a;
	while (tmp->el != el)
	{
		if (tmp->el > tmp->next->el)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_is_sort_a(t_stack *a)
{
	t_stack *tmp;

	if (!a)
		return (1);
	tmp = a;
	while (tmp->next != a)
		if (tmp->el > tmp->next->el)
			return (0);
		else
			tmp = tmp->next;
	return (1);
}

int	ft_is_sort_b(t_stack *b)
{
	t_stack *tmp;

	if (!b)
		return (1);
	tmp = b;
	while (tmp->next != b)
		if (tmp->el < tmp->next->el)
			return (0);
		else
			tmp = tmp->next;
	return (1);
}
