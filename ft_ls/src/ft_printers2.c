/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 03:55:53 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 03:57:37 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_arr_long(int place, const short *flags, t_info **arr,
		t_file *file)
{
	int i;

	ft_print_head(place, flags, file, &i);
	while (++i < file->count)
	{
		if (flags[8])
			ft_printf("%3d ", arr[i]->blksize);
		ft_printf("%c%9s  %*d %-*s  %-*s  %*s%-13s %s%s\n", arr[i]->type,
		arr[i]->right, file->width[0], arr[i]->st_nlink, file->width[1],
		arr[i]->usr, file->width[2], arr[i]->group, file->width[3],
		arr[i]->size, arr[i]->time, arr[i]->name, arr[i]->link);
	}
}

void	ft_print_files(t_manager *data)
{
	if (!data->files->count)
		return ;
	ft_sort_arr(data->files, &data, data->file_list);
	data->files->npr = 1;
	if (data->flags[11])
		ft_print_arr_long(-1, data->flags, data->file_list, data->files);
	else
		ft_print_arr_col(0, (data->files)->width[4] + 1,
		data->file_list, data->files);
}

void	ft_print_result(t_manager *data)
{
	ft_print_files(data);
	ft_push_result(data);
}
