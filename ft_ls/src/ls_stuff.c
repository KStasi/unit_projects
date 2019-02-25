/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:23:53 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:24:56 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_error_generate(int err, char *str)
{
	if (err == 0)
		ft_printf("ft_ls: illegal option -- %s\nusage: ls "
		"[-AkondaursRtl] [file ...]\n", str);
	if (err == 1)
		ft_printf("ft_ls: %s: No such file or directory\n", str);
	if (err == 2)
		ft_printf("ft_ls: %s: Permission denied\n", str);
	return (0);
}

int		ft_parse_flags(int ac, char **av, t_manager **data)
{
	int i;
	int k;

	i = 0;
	ft_bzero((*data)->flags, 12 * sizeof(int));
	while (++i < ac)
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
		{
			k = 0;
			while (av[i][++k])
				ft_set_flags(av[i][k], data);
		}
		else
			break ;
	return (i);
}

void	ft_push_result(t_manager *data)
{
	int		i;
	t_file	*tmp;
	t_info	**arr;

	i = -1;
	tmp = data->dir_list;
	while (++i < data->list_size)
	{
		tmp->width[4] = ft_count_files(tmp->name, &data, &(tmp->count));
		if (!(arr = ft_create_arr(tmp, &data)))
		{
			tmp = tmp->next;
			continue;
		}
		ft_sort_arr(tmp, &data, arr);
		if (data->flags[11])
			ft_print_arr_long(((!data->files->count) && !i) ? 0 : 1,
			data->flags, arr, tmp);
		else
			ft_print_arr_col(((!data->files->count) && !i) ? 0 : 1,
			tmp->width[4], arr, tmp);
		tmp = tmp->next;
		ft_free_arr(&arr);
	}
}

void	ft_finalize_dir(t_manager *data)
{
	data->dir_list->npr = (!data->list_size) ? (char)1 : (char)0;
	data->list_end = ft_find_last(&data);
	data->list_size++;
}
