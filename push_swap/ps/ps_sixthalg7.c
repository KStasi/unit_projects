/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sixthalg7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:54:59 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:56:56 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_merge_in_a(t_stack **a, t_stack **b, int *range, int **flags)
{
	t_stack *tmp;

	tmp = (*a);
	while (tmp && tmp->next != *a)
		tmp = tmp->next;
	while (*a && *b && range[0] > 0 && range[1] > 0)
	{
		if (tmp->el < (*b)->el)
		{
			ft_rr(a, 'b', flags);
			range[0]--;
		}
		else
		{
			ft_p(a, b, 'b', flags);
			range[1]--;
		}
		tmp = (*a);
		while (tmp && tmp->next != *a)
			tmp = tmp->next;
	}
	while (*a && range[0]-- > 0)
		ft_rr(a, 'b', flags);
	while (*b && range[1]-- > 0)
		ft_p(a, b, 'b', flags);
}

static void	ft_merge_in_b(t_stack **a, t_stack **b, int *range, int **flags)
{
	t_stack *tmp;

	tmp = (*a);
	while (tmp && tmp->next != *a)
		tmp = tmp->next;
	while (*a && *b && range[0] > 0 && range[1] > 0)
	{
		if (tmp->el > (*b)->el)
		{
			ft_rr(a, 'a', flags);
			range[0]--;
		}
		else
		{
			ft_p(a, b, 'a', flags);
			range[1]--;
		}
		tmp = (*a);
		while (tmp && tmp->next != *a)
			tmp = tmp->next;
	}
	while (*a && range[0]-- > 0)
		ft_rr(a, 'a', flags);
	while (*b && range[1]-- > 0)
		ft_p(a, b, 'a', flags);
}

void		ft_merge_two(t_stack **a, t_stack **b, int *range, int **flags)
{
	if (range[2])
		ft_merge_in_a(a, b, range, flags);
	else
		ft_merge_in_b(a, b, range, flags);
}

void		ft_form6(t_stack **a, t_stack **b, int **flags)
{
	if (ft_get_size(*a) == 100)
	{
		ft_prepare_stack100(a, b, flags);
		ft_merge_all100(a, b, flags);
	}
	else
	{
		ft_prepare_stack500(a, b, flags);
		ft_merge_all500(a, b, flags);
	}
}
