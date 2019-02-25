/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:40:35 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:40:56 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_p_print(t_stack **a, t_stack **b, char c, int **flags)
{
	if ((*flags)[7])
	{
		(*flags)[(*flags)[7]]++;
		return ;
	}
	write((*flags)[1], "p", 1);
	write((*flags)[1], &c, 1);
	write((*flags)[1], "\n", 1);
	ft_show_collor(*a, 'p', (*flags));
	ft_show_collor(*b, 'P', (*flags));
	ft_show_stacks(*a, (*flags));
	ft_show_stacks(*b, (*flags));
}

static void	ft_connect_a(t_stack **a, t_stack *tmp, int **flags)
{
	if (*a)
	{
		tmp->next = (*a)->next;
		(*a)->next = tmp;
		ft_s(a, 'a', 0, flags);
	}
	else
	{
		*a = tmp;
		(*a)->next = *a;
	}
}

void		ft_p(t_stack **a, t_stack **b, char c, int **flags)
{
	t_stack *tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	if (*b == (*b)->next)
		*b = NULL;
	else
	{
		while (tmp->next != *b)
			tmp = tmp->next;
		tmp->next = (*b)->next;
		tmp = *b;
		*b = (*b)->next;
	}
	ft_connect_a(a, tmp, flags);
	ft_p_print(a, b, c, flags);
}
