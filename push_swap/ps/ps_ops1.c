/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:39:55 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:40:12 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack **l, char c, int **flags)
{
	t_stack *tmp;

	if (!l || !*l)
		return ;
	tmp = *l;
	while (tmp->next != *l)
		tmp = tmp->next;
	*l = tmp;
	if ((*flags)[7])
	{
		(*flags)[(*flags)[7]]++;
		return ;
	}
	write((*flags)[1], "rr", 2);
	write((*flags)[1], &c, 1);
	write((*flags)[1], "\n", 1);
	ft_show_collor(*l, 'R', (*flags));
	ft_show_stacks(*l, (*flags));
}

void	ft_r(t_stack **l, char c, int **flags)
{
	if (!l || !*l)
		return ;
	*l = (*l)->next;
	if ((*flags)[7])
	{
		(*flags)[(*flags)[7]]++;
		return ;
	}
	write((*flags)[1], "r", 1);
	write((*flags)[1], &c, 1);
	write((*flags)[1], "\n", 1);
	ft_show_collor(*l, 'r', (*flags));
	ft_show_stacks(*l, (*flags));
}

void	ft_s(t_stack **l, char c, int print, int **flags)
{
	if (!l || !*l || !(*l)->next || (*l)->el == (*l)->next->el)
		return ;
	(*l)->el = (*l)->el ^ (*l)->next->el;
	(*l)->next->el = (*l)->el ^ (*l)->next->el;
	(*l)->el = (*l)->el ^ (*l)->next->el;
	if (print)
	{
		if ((*flags)[7])
		{
			(*flags)[(*flags)[7]]++;
			return ;
		}
		write((*flags)[1], "s", 1);
		write((*flags)[1], &c, 1);
		write((*flags)[1], "\n", 1);
		ft_show_collor(*l, 's', (*flags));
		ft_show_stacks(*l, (*flags));
	}
}

void	ft_ss(t_stack **a, t_stack **b, int **flags)
{
	ft_s(a, 'a', 0, flags);
	ft_s(b, 'b', 0, flags);
	if ((*flags)[7])
	{
		(*flags)[(*flags)[7]]++;
		return ;
	}
	write((*flags)[1], "ss", 2);
	write((*flags)[1], "\n", 1);
	ft_show_collor(*a, 's', (*flags));
	ft_show_collor(*b, 's', (*flags));
	ft_show_stacks(*a, (*flags));
	ft_show_stacks(*b, (*flags));
}

void	ft_r_both(t_stack **a, t_stack **b, int **flags)
{
	if (a && *a)
		*a = (*a)->next;
	if (b && *b)
		*b = (*b)->next;
	if ((*flags)[7])
	{
		(*flags)[(*flags)[7]]++;
		return ;
	}
	write((*flags)[1], "rr", 1);
	write((*flags)[1], "\n", 1);
	ft_show_collor(*a, 'r', (*flags));
	ft_show_collor(*b, 'r', (*flags));
	ft_show_stacks(*a, (*flags));
	ft_show_stacks(*b, (*flags));
}
