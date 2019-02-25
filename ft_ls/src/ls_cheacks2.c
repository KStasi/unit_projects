/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cheacks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:11:25 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:11:33 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_check_dir(t_manager **data, char *name)
{
	return ((*data)->flags[9] && ft_strcmp(name, ".") && ft_strcmp(name, ".."));
}

int	ft_check_time1(t_info *el, t_info *cur, int mod)
{
	return (el && ((el->tm > cur->tm && !mod) ||
			(el->tm < cur->tm && mod)));
}

int	ft_check_time2(t_info *el, t_info *cur, int mod)
{
	return (el && (el->tm == cur->tm) && ((ft_strcmp(el->name,
			cur->name) < 0 && !mod) || (ft_strcmp(el->name, cur->name) > 0
			&& mod)));
}

int	ft_check_time3(t_info *el, t_info *cur, int mod)
{
	return (el && ((el->tm < cur->tm && !mod) ||
			(el->tm > cur->tm && mod)));
}

int	ft_check_time4(t_info *el, t_info *cur, int mod)
{
	return (el && (el->tm == cur->tm) && ((ft_strcmp(el->name,
			cur->name) > 0 && !mod) || (ft_strcmp(el->name, cur->name) < 0
			&& mod)));
}
