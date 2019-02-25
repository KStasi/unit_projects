/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_getters1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:16:31 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:18:56 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_link(char *path, char *name)
{
	char *link;
	char *buf;
	char *p1;
	char *p2;

	buf = (char *)malloc(sizeof(char) * 256);
	ft_bzero(buf, 256);
	p2 = ft_strjoin(path, "/");
	readlink((p1 = ft_strjoin(p2, name)), buf, 255);
	ft_free_line(&p1);
	ft_free_line(&p2);
	link = ft_strjoin(" -> ", buf);
	free(buf);
	return (link);
}

char	*ft_get_size(t_info *file)
{
	char *size;
	char *p1;
	char *p2;

	if ((S_ISCHR(((file->lstat)->st_mode)) ||
	S_ISBLK(((file->lstat)->st_mode))))
	{
		p1 = ft_itoa(major((file->lstat)->st_rdev));
		p2 = ft_strjoin(p1, ", ");
		ft_free_line(&p1);
		p1 = ft_itoa(minor((file->lstat)->st_rdev));
		size = ft_strjoin(p2, p1);
		ft_free_line(&p1);
		ft_free_line(&p2);
	}
	else
		size = ft_itoa((int)(file->lstat)->st_size);
	return (size);
}

char	*ft_get_time(t_info *file, short int *flags)
{
	char	*tm;
	char	*year;
	char	*tim;
	char	*p1;

	tm = ctime((flags[6]) ? &(file->lstat->st_atime) :
	&(file->lstat->st_mtime));
	year = ft_strdup(ft_strrchr(tm, ' ') + 1);
	year[ft_strlen(year) - 1] = '\0';
	ft_bzero(ft_strrchr(tm, ':'), ft_strlen(ft_strrchr(tm, ':')));
	if ((file->lstat->st_mtime < time(NULL) - 15552000 && !flags[6]) ||
		(file->lstat->st_atime < time(NULL) - 15552000 && flags[6]))
		ft_bzero(ft_strrchr(tm, ' ') + 1, ft_strlen(ft_strrchr(tm, ' ')) - 1);
	p1 = ft_strdup(ft_strchr(tm, ' '));
	if ((file->lstat->st_mtime < time(NULL) - 15552000 && !flags[6]) ||
		(file->lstat->st_atime < time(NULL) - 15552000 && flags[6]))
	{
		tim = ft_strjoin(p1, year);
		ft_free_line(&p1);
	}
	else
		tim = p1;
	ft_free_line(&year);
	return (tim);
}

char	*ft_get_group(t_info *file, short int *flags)
{
	if (flags[2] || !getgrgid((file->lstat)->st_gid))
		return (ft_strdup(" "));
	if (flags[3])
		return (ft_itoa((file->lstat)->st_gid));
	return (ft_strdup(getgrgid((file->lstat)->st_gid)->gr_name));
}

char	*ft_get_usr(t_info *file, short int *flags)
{
	if (!getpwuid((file->lstat)->st_uid))
		return (ft_strdup(" "));
	if (flags[3])
		return (ft_itoa((file->lstat)->st_uid));
	return (ft_strdup(getpwuid((file->lstat)->st_uid)->pw_name));
}
