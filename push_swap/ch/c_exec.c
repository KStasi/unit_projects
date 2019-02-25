/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:49:22 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 01:49:36 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_count_ops(char **ops)
{
	int i;

	i = 0;
	while (ops && ops[i])
		i++;
	return (i);
}

int		ft_check_range(char *s)
{
	long long d;

	d = ft_atoll(s);
	return (d >= -2147483648 && d <= 2147483647);
}

int		ft_ifnum(char **av, int ac)
{
	int i;
	int j;

	i = 0;
	while (++i < ac && (j = -1))
	{
		while (++j < (int)ft_strlen(av[i]))
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+'
				&& av[i][j] != ' ')
				return (0);
		if (ac != 2 && ft_strlen(av[i]) > 9 && !ft_check_range(av[i]))
			return (0);
	}
	i = -1;
	while (++i < ac && (j = ac))
		while (--j > i)
			if (!ft_strcmp(av[i], av[j]))
				return (0);
	return (1);
}

void	ft_try_sort(t_stack **a, t_stack **b, char **ops, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (!ft_strcmp(ops[i], "sa") || !ft_strcmp(ops[i], "ss"))
			ft_cs(a);
		if (!ft_strcmp(ops[i], "sb") || !ft_strcmp(ops[i], "ss"))
			ft_cs(b);
		if (!ft_strcmp(ops[i], "pa"))
			ft_cp(a, b);
		if (!ft_strcmp(ops[i], "pb"))
			ft_cp(b, a);
		if (!ft_strcmp(ops[i], "ra") || !ft_strcmp(ops[i], "rr"))
			ft_cr(a);
		if (!ft_strcmp(ops[i], "rb") || !ft_strcmp(ops[i], "rr"))
			ft_cr(b);
		if (!ft_strcmp(ops[i], "rra") || !ft_strcmp(ops[i], "rrr"))
			ft_crr(a);
		if (!ft_strcmp(ops[i], "rrb") || !ft_strcmp(ops[i], "rrr"))
			ft_crr(b);
	}
}
