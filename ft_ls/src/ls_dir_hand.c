/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir_hand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:13:00 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:14:31 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_finalize_singledata(t_manager *data)
{
	data->list_size++;
	data->dir_list = ft_create_file(".");
	data->dir_list->npr = 1;
	data->list_end = data->dir_list;
}

t_file	*ft_find_last(t_manager **data)
{
	t_file *tmp;

	if (!data || !*data || !(*data)->dir_list)
		return (NULL);
	tmp = (*data)->dir_list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_file	*ft_posses_dir(t_manager **data, char *name, char *file)
{
	t_file *tmp;

	if (!data || !*data || !(*data)->dir_list)
		return (NULL);
	tmp = (*data)->curr_dir;
	while (tmp)
	{
		if (ft_strstr(tmp->name, name))
		{
			while (tmp->next && ft_strstr(tmp->next->name, name)
			&& ft_strcmp(ft_strrchr(tmp->next->name, '/') + 1, file) < 0)
				tmp = tmp->next;
			return (tmp);
		}
		tmp = tmp->next;
	}
	return ((*data)->list_end);
}

int		ft_opendir(DIR **dir, char *name, int *col)
{
	struct stat *stat;

	*col = 0;
	stat = (struct stat *)malloc(sizeof(struct stat));
	if (!(*dir = opendir(name)))
	{
		if (lstat(name, stat))
			*col = 1;
		free(stat);
		return (0);
	}
	ft_free_lstat(&stat);
	return (1);
}

int		ft_count_files(char *name, t_manager **data, int *count)
{
	int				col;
	DIR				*dir;
	struct dirent	*ent;

	*count = 0;
	if (!ft_opendir(&dir, name, &col))
		return (col);
	ft_set_curr_dir(data, name);
	while ((ent = readdir(dir)))
	{
		if (ft_check_a(ent->d_name, (*data)->flags))
			continue ;
		if (ft_check_aa(ent->d_name, (*data)->flags))
			continue ;
		ft_set_col(&col, ent->d_name);
		if (ent->d_type == DT_DIR && ft_check_dir(data, ent->d_name))
			ft_add_end(data, name, ent->d_name);
		(*count)++;
	}
	closedir(dir);
	col++;
	return (col);
}
