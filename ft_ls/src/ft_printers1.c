/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 03:52:19 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 03:55:38 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_dir_name(int place, t_file *file)
{
	if (file->npr)
		;
	else if (!place)
		ft_printf("%s:\n", ft_strncmp(file->name, "//", 2) ? file->name :
		file->name + 1);
	else
		ft_printf("\n%s:\n", ft_strncmp(file->name, "//", 2) ? file->name :
		file->name + 1);
}

void	ft_print_with_break(int *n, int col, char *name, struct winsize w)
{
	*n = (col && w.ws_col / col != 0) ? w.ws_col / col : 1;
	ft_printf("%-*s\n", col, name);
}

void	ft_print_without_break(int *n, int col, char *name, struct winsize w)
{
	*n = (w.ws_col > col) ? *n - 1 : *n;
	ft_printf("%-*s", col, name);
}

void	ft_print_arr_col(int place, int col, t_info **arr, t_file *file)
{
	int				i;
	int				j;
	struct winsize	w;
	int				n;
	int				r;

	r = ft_set_w(&w, col, &n, file);
	ft_print_dir_name(place, file);
	j = -1;
	while (++j < r && (i = -1))
		while ((++i < w.ws_col / col) || (n == 1))
		{
			if (i * r + j > file->count - 1)
			{
				ft_carry_line(&n, col, w);
				break ;
			}
			if (n > 1 || w.ws_col < col)
				ft_print_without_break(&n, col, (arr[i * r + j])->name, w);
			else
				ft_print_with_break(&n, col, (arr[i * r + j])->name, w);
		}
	if ((col && n != w.ws_col / col && (w.ws_col / col != 0)))
		ft_putchar('\n');
}

void	ft_print_head(int place, const short *flags, t_file *file, int *i)
{
	if (file->npr)
		;
	else if (!place)
		ft_printf("%s:\n", ft_strncmp(file->name, "//", 2) ? file->name :
		file->name + 1);
	else
		ft_printf("\n%s:\n", ft_strncmp(file->name, "//", 2) ? file->name :
		file->name + 1);
	*i = -1;
	if ((place != -1 && file->width[5]) || flags[8])
		ft_printf("total %d\n", (flags[1]) ? file->width[5] / 2 :
		file->width[5]);
}
