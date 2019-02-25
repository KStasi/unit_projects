/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:49:51 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 01:49:53 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_crr(t_stack **l)
{
	t_stack *tmp;

	if (!l || !*l)
		return ;
	tmp = *l;
	while (tmp->next != *l)
		tmp = tmp->next;
	*l = tmp;
}

void	ft_cr(t_stack **l)
{
	if (!l || !*l)
		return ;
	*l = (*l)->next;
}

void	ft_cs(t_stack **l)
{
	if (!l || !*l || (*l) == (*l)->next)
		return ;
	(*l)->el = (*l)->el ^ (*l)->next->el;
	(*l)->next->el = (*l)->el ^ (*l)->next->el;
	(*l)->el = (*l)->el ^ (*l)->next->el;
}

void	ft_cp(t_stack **a, t_stack **b)
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
	if (*a)
	{
		tmp->next = (*a)->next;
		(*a)->next = tmp;
		ft_cs(a);
		return ;
	}
	*a = tmp;
	(*a)->next = *a;
}
