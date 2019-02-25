/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_addrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 03:57:52 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:05:20 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_add_last_dir(t_manager *data, char *name)
{
	t_file		*tmp1;
	t_file		*tmp2;

	tmp1 = data->dir_list;
	while (tmp1->next && ft_strcmp(tmp1->next->name, name) < 0)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = ft_create_file(name);
	tmp1->next->next = tmp2;
	tmp1->next->npr = 0;
}

void		ft_add_dir(char *name, t_manager *data)
{
	struct stat	*ls;
	int			i;

	ls = (struct stat *)malloc(sizeof(struct stat));
	i = lstat(name, ls);
	if (i == -1 || !(ls->st_mode & S_IRUSR))
	{
		ft_free_lstat(&ls);
		return ;
	}
	if (!data->list_size)
		data->dir_list = ft_create_file(name);
	else
		ft_add_last_dir(data, name);
	ft_finalize_dir(data);
	ft_free_lstat(&ls);
}

void		ft_add_file(char *name, t_manager *data, int *j, char *path)
{
	int i;

	data->file_list[*j]->lstat = (struct stat *)malloc(sizeof(struct stat));
	data->file_list[*j]->name = ft_strdup(name);
	i = lstat(name, data->file_list[(*j)++]->lstat);
	if (i == -1 || !(data->file_list[(*j) - 1]->lstat->st_mode & S_IRUSR))
	{
		ft_error_generate((i == -1) ? 1 : 2, name);
		if (data->file_list[--(*j)]->lstat)
			free(data->file_list[*j]->lstat);
		free(data->file_list[*j]->name);
		free(data->file_list[*j]);
	}
	else
	{
		data->files->width[4] = (data->files->width[4] > (int)ft_strlen(name)) ?
		data->files->width[4] : (int)ft_strlen(name);
		ft_set_all_stuff(data->files, data->file_list[*j - 1]->lstat);
		ft_set_extra_stuff(data->file_list[*j - 1], data->flags, path);
	}
}

int			ft_add_new_file(t_info **new, t_file *file, char *d_name, int *i)
{
	char *p1;
	char *p2;

	(void)i;
	(*new) = (t_info *)malloc(sizeof(t_info));
	(*new)->name = ft_strdup(d_name);
	(*new)->lstat = malloc(sizeof(struct stat));
	p2 = ft_strjoin("/", d_name);
	p1 = ft_strjoin(file->name, p2);
	lstat(p1, (*new)->lstat);
	ft_free_line(&p1);
	ft_free_line(&p2);
	ft_set_all_stuff(file, (*new)->lstat);
	return (1);
}

void		ft_add_end(t_manager **data, char *name, char *d_name)
{
	t_file	*tmp;
	char	*p1;
	char	*p2;

	tmp = ft_posses_dir(data, name, d_name);
	(*data)->list_end = tmp->next;
	p2 = ft_strjoin("/", d_name);
	p1 = ft_strjoin(name, p2);
	tmp->next = ft_create_file(p1);
	ft_free_line(&p1);
	ft_free_line(&p2);
	tmp->next->npr = 0;
	tmp->next->next = (*data)->list_end;
	(*data)->list_end = ft_find_last(data);
	(*data)->list_size++;
}
