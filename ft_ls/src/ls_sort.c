/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:21:09 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:23:35 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		partition_a(t_info **arr, int l, int r, int mod)
{
	t_info	*cur;
	int		i;
	int		j;

	cur = (t_info *)malloc(sizeof(t_info));
	ft_info_copy(&(arr[l]), &cur);
	i = l;
	j = r;
	while (i <= j)
	{
		while (i <= r && ((ft_strcmp(arr[i]->name, cur->name) < 0 && !mod)
		|| (ft_strcmp(arr[i]->name, cur->name) > 0 && mod)))
			i++;
		while (j >= l && ((ft_strcmp(arr[j]->name, cur->name) > 0 && !mod)
		|| (ft_strcmp(arr[j]->name, cur->name) < 0 && mod)))
			j--;
		if (i >= j || i > r || j < l)
			break ;
		ft_swap_info(&(arr[i++]), &(arr[j--]));
	}
	free(cur);
	return (j);
}

int		partition_t(t_info **arr, int l, int r, int mod)
{
	t_info	*cur;
	int		i;
	int		j;

	cur = (t_info *)malloc(sizeof(t_info));
	ft_info_copy(&(arr[l]), &cur);
	i = l;
	j = r;
	while (i <= j)
	{
		while (i <= r && (ft_check_time1(arr[i], cur, mod) ||
		ft_check_time2(arr[i], cur, mod)))
			i++;
		while (j >= l && (ft_check_time3(arr[j], cur, mod) ||
		ft_check_time4(arr[j], cur, mod)))
			j--;
		if (i >= j || i > r || j < l)
			break ;
		ft_swap_info(&(arr[i]), &(arr[j]));
	}
	free(cur);
	return (j);
}

void	ft_sort_alphabet(t_info **arr, int l, int r, int mod)
{
	int q;

	if (l < r)
	{
		q = partition_a(arr, l, r, mod);
		ft_sort_alphabet(arr, l, q, mod);
		ft_sort_alphabet(arr, q + 1, r, mod);
	}
}

void	ft_sort_time_t(t_info **arr, int l, int r, int mod)
{
	int q;

	if (l < r)
	{
		q = partition_t(arr, l, r, mod);
		ft_sort_time_t(arr, l, q, mod);
		ft_sort_time_t(arr, q + 1, r, mod);
	}
}

void	ft_sort_arr(t_file *file, t_manager **data, t_info **arr)
{
	if ((*data)->flags[10])
		ft_sort_time_t(arr, 0, file->count - 1, (*data)->flags[7]);
	else
		ft_sort_alphabet(arr, 0, file->count - 1, (*data)->flags[7]);
}
