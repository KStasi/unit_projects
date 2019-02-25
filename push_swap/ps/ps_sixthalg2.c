/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sixthalg2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:49:06 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:49:55 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min5b1(t_stack *a, int min, int depth_b)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next->next->next->next->next != a)
		tmp = tmp->next;
	while (5 - depth_b > 0)
	{
		tmp = tmp->next;
		depth_b++;
	}
	while (tmp != a)
	{
		if (min > tmp->el)
			min = tmp->el;
		tmp = tmp->next;
	}
	return (min);
}

static int	ft_find_max5b1(t_stack *a, int max, int depth_b)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next->next->next->next->next != a)
		tmp = tmp->next;
	while (5 - depth_b > 0)
	{
		tmp = tmp->next;
		depth_b++;
	}
	while (tmp != a)
	{
		if (max < tmp->el)
			max = tmp->el;
		tmp = tmp->next;
	}
	return (max);
}

int			ft_find_min5b(t_stack *a, t_stack *b, int depth_a, int depth_b)
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
	return (ft_find_min5b1(a, min, depth_b));
}

int			ft_find_max5b(t_stack *a, t_stack *b, int depth_a, int depth_b)
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
	return ((ft_find_max5b1(a, max, depth_b)));
}

int			ft_init_value(t_stack **a, t_stack **b, int *min, int *max)
{
	*min = ft_find_min5a(*a, *b, 5, 0);
	*max = ft_find_max5a(*a, *b, 5, 0);
	return (5);
}
