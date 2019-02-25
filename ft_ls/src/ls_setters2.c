/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_setters2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:29:00 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:29:41 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_set_col(int *col, char *name)
{
	int i;

	i = (int)ft_strlen(name);
	*col = (*col > i) ? *col : i;
}

void	ft_set_curr_dir(t_manager **data, char *name)
{
	t_file *tmp;

	if (!data || !*data || !(*data)->dir_list)
		return ;
	tmp = (*data)->dir_list;
	while (tmp)
	{
		if (ft_strstr(tmp->name, name))
		{
			(*data)->curr_dir = tmp;
			return ;
		}
		tmp = tmp->next;
	}
	(*data)->curr_dir = (*data)->list_end;
}

int		ft_set_w(struct winsize *w, int col, int *n, t_file *file)
{
	ioctl(0, TIOCGWINSZ, w);
	*n = (col && w->ws_col / col != 0) ? w->ws_col / col : 1;
	return ((file->count % *n == 0) ? file->count / *n : file->count / *n + 1);
}
