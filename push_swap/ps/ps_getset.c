/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:39:01 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:39:24 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_fd(char *str, int mod)
{
	if (!mod)
		mod = open(str + 2, O_RDONLY);
	else
		mod = open(str + 2, O_WRONLY);
	return (mod);
}

int		ft_set_flags(char *flag, int **flags)
{
	int j;

	j = 0;
	if (!(ft_strncmp("-v", flag, 2)) && ++j)
		(*flags)[0] = 1;
	else if (!(ft_strncmp("-o", flag, 2)) && ++j)
		(*flags)[1] = ft_get_fd(flag, 1);
	else if (!(ft_strncmp("-i", flag, 2)) && ++j)
		(*flags)[2] = ft_get_fd(flag, 0);
	else if (!(ft_strncmp("-c", flag, 2)) && ++j)
		(*flags)[3] = 1;
	else if (!(ft_strncmp("-m1", flag, 3)) && ++j)
		(*flags)[4] = 1;
	else if (!(ft_strncmp("-m2", flag, 3)) && ++j)
		(*flags)[5] = 1;
	else if (!(ft_strncmp("-m3", flag, 3)) && ++j)
		(*flags)[6] = 1;
	else if (!(ft_strncmp("-m4", flag, 3)) && ++j)
		(*flags)[11] = 1;
	return (j);
}

int		ft_parse_flags(int i, char **av, int **flags)
{
	int j;

	j = i;
	ft_bzero(*flags, 13 * sizeof(int));
	(*flags)[1] = 1;
	while (av[i++])
		if (av[i - 1][0] == '-')
			j += ft_set_flags(av[i - 1], flags);
	return (j);
}

int		ft_read_from_file(char ***av, int *i, int *ac, int *flags)
{
	char *line;

	*i = -1;
	while (*av && (*av)[++(*i)])
		free((*av)[*i]);
	if (*av)
		free(*av);
	*ac = 2;
	*i = 0;
	if (!gnl(flags[2], &line))
		return (0);
	(*av) = ft_strsplit(line, ' ');
	return (1);
}
