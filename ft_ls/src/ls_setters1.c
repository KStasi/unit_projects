/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_setters1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:26:49 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:28:40 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_set_flags(char flag, t_manager **data)
{
	char *flags;

	if (ft_check_flag(flag))
	{
		flags = ft_strdup("AkondaursRtl");
		(*data)->flags[ft_strchr(flags, flag) - flags] = 1;
		if (flag == 'n' || flag == 'o')
			(*data)->flags[ft_strchr(flags, 'l') - flags] = 1;
		if ((flag == 'a' && (*data)->flags[ft_strchr(flags, 'A') - flags])
			|| (flag == 'A' && (*data)->flags[ft_strchr(flags, 'a') - flags]))
			(*data)->flags[ft_strchr(flags, 'A') - flags] = 0;
		free(flags);
	}
}

void		ft_set_all_stuff(t_file *file, struct stat *stat)
{
	struct group *gr;

	gr = getgrgid(stat->st_gid);
	file->width[0] = (file->width[0] > ft_nlen(stat->st_nlink))
	? file->width[0] : (int)ft_nlen(stat->st_nlink);
	file->width[1] = (stat->st_uid <= 0 || !getpwuid(stat->st_uid)
	|| file->width[1] > (int)ft_strlen(getpwuid(stat->st_uid)->pw_name)) ?
	file->width[1] : (int)ft_strlen(getpwuid(stat->st_uid)->pw_name);
	file->width[2] = (!gr || file->width[2] > (int)ft_strlen(gr->gr_name)) ?
	file->width[2] : (int)ft_strlen(gr->gr_name);
	file->width[3] = (file->width[3] > ft_nlen(stat->st_size)) ?
	file->width[3] : (int)ft_nlen(stat->st_size);
	file->width[5] += stat->st_blocks;
}

void		ft_set_npr(t_manager *data, int j)
{
	data->files->count = j;
	if (j && data->dir_list)
		data->dir_list->npr = 0;
}

long		ft_set_blksize(t_info *file, short int *flags)
{
	return ((flags[1]) ? (file->lstat)->st_blocks /
	2 : (file->lstat)->st_blocks);
}

void		ft_set_extra_stuff(t_info *file, short int *flags, char *name)
{
	file->type = ft_tp((file->lstat)->st_mode);
	file->right = ft_rght((file->lstat)->st_mode);
	file->group = ft_get_group(file, flags);
	file->usr = ft_get_usr(file, flags);
	file->size = ft_get_size(file);
	file->time = ft_get_time(file, flags);
	file->st_nlink = file->lstat->st_nlink;
	file->link = ft_check_link(file, name);
	file->tm = (flags[6]) ? file->lstat->st_atime :
	file->lstat->st_mtime;
	file->blksize = ft_set_blksize(file, flags);
	ft_free_lstat(&(file->lstat));
	file->lstat = NULL;
}
