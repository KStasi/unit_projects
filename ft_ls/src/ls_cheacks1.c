/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cheacks1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:06:41 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:07:06 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_check_flag(char c)
{
	if (ft_strchr("AkondaursRtl", c))
		return (1);
	return (0);
}

int			ft_check_correct(char **av, int ac)
{
	int i;
	int j;

	i = 0;
	while (++i < ac)
		if (av[i][0] == '-' && av[i][1])
		{
			j = 0;
			while (av[i][++j])
				if (!ft_check_flag(av[i][j]))
					return (ft_error_generate(0, av[i]));
		}
		else if (av[i][0] != '-')
			break ;
	return (1);
}

char		*ft_check_link(t_info *file, char *name)
{
	char *p;

	p = ft_get_link((ft_strcmp(name, file->name) ?
		name : ""), file->name);
	if (file->type == 'l')
		return (p);
	ft_free_line(&p);
	return (ft_strdup(""));
}

int			ft_check_a(char *name, short int *flags)
{
	return (!flags[0] && !flags[5] && !ft_strncmp(name, ".", 1)
			&& !ft_strchr(name, '/'));
}

int			ft_check_aa(char *name, short int *flags)
{
	return (flags[0] && (!ft_strncmp(name, ".\0", 2) ||
			!ft_strncmp(name, "..\0", 3)));
}
