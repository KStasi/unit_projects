/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:25:29 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/23 17:08:25 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_num(char **num)
{
	if (num && *num)
		free(*num);
	*num = NULL;
}

int			ft_is_flag(char *s)
{
	if (!(ft_strncmp("-v", s, 2)) || !(ft_strncmp("-o", s, 2)) ||
		!(ft_strncmp("-i", s, 2)) || !(ft_strncmp("-c", s, 2)) ||
		!(ft_strncmp("-m1", s, 3)) || !(ft_strncmp("-m2", s, 3)) ||
		!(ft_strncmp("-m3", s, 3)) || !(ft_strncmp("-m4", s, 3)))
		return (1);
	return (0);
}

int			ft_is_num(char **av, int ac)
{
	int i;
	int j;

	i = 0;
	while (++i < ac && (j = -1))
	{
		if (ft_is_flag(av[i]))
			continue ;
		while (++j < (int)ft_strlen(av[i]))
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' &&
					av[i][j] != '+' && av[i][j] != ' ')
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

int			ft_check_range(char *s)
{
	long long d;

	d = ft_atoll(s);
	return (d >= -2147483648 && d <= 2147483647);
}

int			ft_check_correct(char **av, int ac)
{
	int		i;
	int		j;
	char	*num;

	i = -1;
	num = NULL;
	while (av && av[++i])
	{
		j = i;
		while (av[++j])
			if (!ft_strcmp(av[i], av[j]))
				return (0);
		if (!ft_check_range(av[i]) ||
			(!((ac != 2 && i == 0) || ft_is_flag(av[i])) &&
				ft_strcmp((num = ft_itoa(ft_atoi(av[i]))), av[i])))
		{
			ft_free_num(&num);
			return (0);
		}
		ft_free_num(&num);
	}
	return (1);
}
