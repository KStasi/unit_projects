/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getinfo1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:35:32 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:37:10 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_size(t_stack *a)
{
	t_stack *tmp;
	int		size;

	if (!a)
		return (0);
	tmp = a;
	size = 1;
	while (tmp->next != a)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int		ft_find_min(t_stack *l)
{
	t_stack	*tmp;
	int		min;

	if (!l)
		return (0);
	min = l->el;
	tmp = l->next;
	while (tmp != l)
	{
		min = (min > tmp->el) ? tmp->el : min;
		tmp = tmp->next;
	}
	return (min);
}

int		ft_find_max(t_stack *l)
{
	t_stack *tmp;
	int		max;

	if (!l)
		return (0);
	max = l->el;
	tmp = l->next;
	while (tmp != l)
	{
		max = (max < tmp->el) ? tmp->el : max;
		tmp = tmp->next;
	}
	return (max);
}

int		ft_deep(t_stack *l, int el)
{
	t_stack	*tmp;
	int		i;

	tmp = l;
	i = 0;
	while (tmp->next != l)
	{
		i++;
		if (tmp->el == el)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		ft_deep_rev(t_stack *l, int el)
{
	t_stack	*tmp;
	int		i;
	int		j;

	tmp = l;
	i = 0;
	while (tmp->next != l)
	{
		if (tmp->el == el)
			break ;
		i++;
		tmp = tmp->next;
	}
	tmp = l;
	j = 0;
	while (tmp->next != l)
	{
		j++;
		tmp = tmp->next;
	}
	return (j - i);
}
