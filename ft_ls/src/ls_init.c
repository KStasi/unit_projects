/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:25:40 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:26:24 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_init_singledata(t_manager *data)
{
	data->file_list[0] = (t_info *)malloc(sizeof(t_info));
	data->file_list[0]->lstat = (struct stat *)malloc(sizeof(struct stat));
	data->file_list[0]->name = ft_strdup(".");
}

void		ft_init_data(t_manager *data, int ac)
{
	data->file_list = (t_info **)malloc(sizeof(t_info *) * ac);
	data->files = (t_file *)malloc(sizeof(t_file));
	data->files->name = ft_strdup(".");
	ft_bzero(data->files->width, 6 * sizeof(int));
	data->files->count = 0;
}

void		ft_init_arr(t_info ***arr, int *i, t_file *file)
{
	*arr = (t_info **)malloc(sizeof(t_info *) * (file->count + 1));
	*i = -1;
	ft_bzero(file->width, 4 * sizeof(int));
	file->width[5] = 0;
}
