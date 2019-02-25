/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:15:27 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:15:46 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_lstat(struct stat **ls)
{
	if (ls && *ls)
		free(*ls);
}

void		ft_free_line(char **p)
{
	if (p && *p)
		free(*p);
}

void		ft_free_files(t_file *file)
{
	t_file *tmp;

	tmp = file;
	while (tmp)
	{
		file = tmp;
		tmp = tmp->next;
		ft_free_line(&(file->name));
		free(file);
	}
}

void		ft_free_info(t_info *info)
{
	ft_free_line(&(info->name));
	ft_free_line(&(info->right));
	ft_free_line(&(info->usr));
	ft_free_line(&(info->group));
	ft_free_line(&(info->size));
	ft_free_line(&(info->time));
	ft_free_line(&(info->link));
	free(info);
}

void		ft_free_file_list(t_info **list, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (list[i])
			ft_free_info(list[i]);
}
