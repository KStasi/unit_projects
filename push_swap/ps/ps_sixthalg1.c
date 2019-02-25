/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sixthalg1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:47:08 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:49:00 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min5a1(t_stack *b, int min, int depth_b)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	tmp = b;
	while (++i < depth_b)
	{
		if (min > tmp->el)
			min = tmp->el;
		tmp = tmp->next;
	}
	return (min);
}

static int	ft_find_max5a1(t_stack *b, int max, int depth_b)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	tmp = b;
	while (++i < depth_b)
	{
		if (max < tmp->el)
			max = tmp->el;
		tmp = tmp->next;
	}
	return (max);
}

int			ft_find_min5a(t_stack *a, t_stack *b, int depth_a, int depth_b)
{
	int		i;
	int		min;
	t_stack	*tmp;

	i = -1;
	if (depth_a)
		min = a->el;
	else if (depth_b)
		min = b->el;
	else
		return (-1000);
	tmp = a;
	while (++i < depth_a)
	{
		if (min > tmp->el)
			min = tmp->el;
		tmp = tmp->next;
	}
	return (ft_find_min5a1(b, min, depth_b));
}

int			ft_find_max5a(t_stack *a, t_stack *b, int depth_a, int depth_b)
{
	int		i;
	int		max;
	t_stack	*tmp;

	i = -1;
	if (depth_a)
		max = a->el;
	else if (depth_b)
		max = b->el;
	else
		return (-1000);
	tmp = a;
	while (++i < depth_a)
	{
		if (max < tmp->el)
			max = tmp->el;
		tmp = tmp->next;
	}
	return (ft_find_max5a1(b, max, depth_b));
}
