/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_creators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:11:54 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:12:45 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_create_file(char *file)
{
	t_file *new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new->name = ft_strdup(file);
	new->next = NULL;
	return (new);
}

t_manager	*ft_create_singledata(t_manager *data)
{
	if (data->flags[4])
	{
		ft_init_singledata(data);
		if (lstat(".", data->file_list[0]->lstat) == -1)
		{
			ft_error_generate(1, ".");
			if (data->file_list[0]->lstat)
				free(data->file_list[0]->lstat);
			free(data->file_list[0]);
		}
		else
		{
			data->files->width[4] = (data->files->width[4] > 1) ?
									data->files->width[4] : 1;
			ft_set_all_stuff(data->files, data->file_list[0]->lstat);
			ft_set_extra_stuff(data->file_list[0], data->flags, ".");
		}
		data->files->count = 1;
		return (data);
	}
	ft_finalize_singledata(data);
	return (data);
}

void		ft_create_file_list(int i, int ac, char **av, t_manager *data)
{
	struct stat	*ls;
	DIR			*dir;
	int			j;

	j = 0;
	ft_init_data(data, ac);
	ls = (struct stat *)malloc(sizeof(struct stat));
	while (++i < ac)
	{
		lstat(av[i], ls);
		if (!(ft_tp(ls->st_mode) == 'l' && data->flags[11])
			&& !data->flags[4] && (dir = opendir(av[i])))
		{
			ft_add_dir(av[i], data);
			closedir(dir);
		}
		else if ((data->file_list[j] = (t_info *)malloc(sizeof(t_info))))
			ft_add_file(av[i], data, &j, av[i]);
	}
	ft_free_lstat(&ls);
	ft_set_npr(data, j);
}

t_info		**ft_create_arr(t_file *file, t_manager **data)
{
	t_info			**arr;
	struct dirent	*ent;
	DIR				*dir;
	int				i;

	if (!(dir = opendir(file->name)))
	{
		ft_error_generate(2, file->name);
		return (NULL);
	}
	ft_init_arr(&arr, &i, file);
	while ((ent = readdir(dir)))
	{
		if (ft_check_a(ent->d_name, (*data)->flags))
			continue ;
		if (ft_check_aa(ent->d_name, (*data)->flags))
			continue ;
		if (ft_add_new_file(&arr[++i], file, ent->d_name, &i))
			ft_set_extra_stuff(arr[i], (*data)->flags, file->name);
	}
	arr[++i] = NULL;
	file->count = i;
	closedir(dir);
	return (arr);
}
