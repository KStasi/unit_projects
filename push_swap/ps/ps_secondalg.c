/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_secondalg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:45:37 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:46:35 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_b(t_stack **a, t_stack **b, int n, int **flags)
{
	int i;
	int size;

	size = ft_get_size(*a);
	i = 1;
	while (*a && (size - n))
	{
		if (!*b || (*a)->el > (*b)->el || i)
		{
			ft_p(b, a, 'b', flags);
			i = 0;
		}
		else
		{
			ft_p(b, a, 'b', flags);
			ft_s(b, 'b', 1, flags);
		}
		n++;
	}
	if (*a)
		ft_rr(a, 'a', flags);
	ft_p(a, b, 'a', flags);
}

void	ft_fill_a(t_stack **a, t_stack **b, int n, int **flags)
{
	int i;
	int size;

	size = ft_get_size(*a);
	i = 1;
	while (*b && (size - n))
	{
		if (!*a || (*b)->el > (*a)->el || i)
		{
			ft_p(a, b, 'a', flags);
			i = 0;
		}
		else
		{
			ft_p(a, b, 'a', flags);
			ft_s(a, 'a', 1, flags);
		}
		n++;
	}
	ft_r(a, 'a', flags);
}

int		ft_check(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	if (b)
	{
		tmp = b->next;
		while (tmp != b)
		{
			if (tmp->el < tmp->next->el && tmp->next != b)
				return (0);
			tmp = tmp->next;
		}
	}
	if (!a)
		return (1);
	tmp = a;
	if (tmp->el > tmp->next->el && tmp->next != a)
		return (0);
	tmp = tmp->next;
	while (tmp != a)
	{
		if (tmp->el > tmp->next->el && tmp->next != a)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_finalize2(t_stack **a, t_stack **b, int **flags)
{
	t_stack *tmp;

	while (*b)
		ft_p(a, b, 'a', flags);
	tmp = *a;
	while (tmp->next != *a)
		tmp = tmp->next;
	while (tmp->el < (*a)->el)
	{
		ft_r(a, 'a', flags);
		tmp = *a;
		while (tmp->next != *a)
			tmp = tmp->next;
	}
}

void	ft_form2(t_stack **a, t_stack **b, int **flags)
{
	int size;
	int n;

	size = ft_get_size(*a);
	n = -1;
	while (++n < size && !ft_check(*a, *b))
	{
		if (!(n % 2))
			ft_fill_b(a, b, n, flags);
		else
			ft_fill_a(a, b, n, flags);
	}
	ft_finalize2(a, b, flags);
}
