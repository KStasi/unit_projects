/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sixthalg3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:50:22 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:52:17 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_sort_place(t_stack *a, t_stack *b, int place)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	while (tmp->next->next->next->next->next != a)
		tmp = tmp->next;
	i = -1;
	if (place)
	{
		while (++i < 4)
			if (tmp->el > tmp->next->el)
				return (0);
			else
				tmp = tmp->next;
	}
	else
	{
		tmp = b;
		while (++i < 4)
			if (!tmp || tmp->el < tmp->next->el)
				return (0);
			else
				tmp = tmp->next;
	}
	return (1);
}

int			ft_present_el(t_stack *a, int depth_a, int el)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = -1;
	while (++i < depth_a)
		if (tmp->el == el)
			return (1);
		else
			tmp = tmp->next;
	return (0);
}

int			ft_is_reversed(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = -1;
	while (++i < 4)
		if (tmp->el < tmp->next->el)
			return (0);
		else
			tmp = tmp->next;
	return (1);
}

static int	ft_magic1(t_stack **a, t_stack **b, int i, int **flags)
{
	while (++i < 4)
		ft_p(b, a, 'b', flags);
	ft_r(a, 'a', flags);
	i = -1;
	while (++i < 4)
	{
		ft_p(a, b, 'a', flags);
		ft_r(a, 'a', flags);
	}
	return (0);
}

int			ft_magic(t_stack **a, t_stack **b, int place, int **flags)
{
	int	i;

	i = -1;
	if (place)
		return (ft_magic1(a, b, i, flags));
	while (++i < 4)
		ft_r(a, 'a', flags);
	ft_p(b, a, 'b', flags);
	i = -1;
	while (++i < 4)
	{
		ft_rr(a, 'a', flags);
		ft_p(b, a, 'b', flags);
	}
	return (0);
}
