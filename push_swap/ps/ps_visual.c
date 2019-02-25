/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:09:04 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 00:09:30 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putel_fd(int el, int fd)
{
	ft_putnbr_fd(el, fd);
	ft_putchar_fd('\n', fd);
}

void		ft_show_stacks(t_stack *s, int *flags)
{
	t_stack	*tmp;

	if (!flags[0] || flags[3] || flags[7])
		return ;
	tmp = s;
	ft_putstr_fd("\nAfter opperation:\n\n", flags[1]);
	while (tmp && tmp->next != s)
	{
		ft_putnbr_fd(tmp->el, flags[1]);
		ft_putchar_fd('\n', flags[1]);
		tmp = tmp->next;
	}
	if (tmp)
	{
		ft_putnbr_fd(tmp->el, flags[1]);
		ft_putstr_fd("\n\n", flags[1]);
	}
}

int			ft_check_col(int i, char c)
{
	if (((c == 'R' || c == 's') && i < 3) || (c == 'p' && i == 1))
		return (1);
	return (0);
}

void		ft_show_collor(t_stack *l, char c, int *flags)
{
	t_stack	*tmp;
	int		i;

	if (!flags[3] || flags[7])
		return ;
	tmp = l;
	i = 0;
	ft_putstr_fd("\n\x1b[1;32mAfter an opperation:\x1b[0m\n\n", flags[1]);
	while (tmp && tmp->next != l && ++i)
	{
		if (ft_check_col(i, c) || (c == 'r' && tmp->next->next == l))
			ft_putstr_fd("\x1b[1;31m", flags[1]);
		ft_putel_fd(tmp->el, flags[1]);
		tmp = tmp->next;
		if (ft_check_col(i, c) || (c == 'r' && tmp->next->next == l))
			ft_putstr_fd("\x1b[0m", flags[1]);
	}
	if (tmp && ++i)
	{
		if (c == 'r')
			ft_putstr_fd("\x1b[1;31m", flags[1]);
		ft_putel_fd(tmp->el, flags[1]);
		if (c == 'r')
			ft_putstr_fd("\x1b[0m", flags[1]);
	}
}
