/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file_hand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:14:50 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:14:52 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_tp(mode_t m)
{
	if (S_ISREG((m)))
		return ('-');
	if (S_ISLNK((m)))
		return ('l');
	if (S_ISDIR((m)))
		return ('d');
	if (S_ISCHR((m)))
		return ('c');
	if (S_ISBLK((m)))
		return ('b');
	if (S_ISFIFO((m)))
		return ('p');
	return ('s');
}

char	*ft_rght(mode_t m)
{
	char rght[10];

	ft_bzero(rght, 10);
	rght[0] = ((m & S_IRUSR)) ? (char)'r' : (char)'-';
	rght[1] = ((m & S_IWUSR)) ? (char)'w' : (char)'-';
	rght[2] = ((m & S_IXUSR)) ? (char)'x' : (char)'-';
	rght[3] = ((m & S_IRGRP)) ? (char)'r' : (char)'-';
	rght[4] = ((m & S_IWGRP)) ? (char)'w' : (char)'-';
	rght[5] = ((m & S_IXGRP)) ? (char)'x' : (char)'-';
	rght[6] = ((m & S_IROTH)) ? (char)'r' : (char)'-';
	rght[7] = ((m & S_IWOTH)) ? (char)'w' : (char)'-';
	rght[8] = ((m & S_IXOTH)) ? (char)'x' : (char)'-';
	return (ft_strdup(rght));
}

void	ft_carry_line(int *n, int col, struct winsize w)
{
	if (*n != w.ws_col)
		ft_putchar('\n');
	*n = (col && w.ws_col / col != 0) ? w.ws_col / col : 1;
}

void	ft_info_copy(t_info **arr1, t_info **arr2)
{
	(*arr2)->name = (*arr1)->name;
	(*arr2)->type = (*arr1)->type;
	(*arr2)->right = (*arr1)->right;
	(*arr2)->usr = (*arr1)->usr;
	(*arr2)->group = (*arr1)->group;
	(*arr2)->size = (*arr1)->size;
	(*arr2)->time = (*arr1)->time;
	(*arr2)->link = (*arr1)->link;
	(*arr2)->st_nlink = (*arr1)->st_nlink;
	(*arr2)->tm = (*arr1)->tm;
	(*arr2)->blksize = (*arr1)->blksize;
}

void	ft_swap_info(t_info **arr1, t_info **arr2)
{
	t_info *tmp;

	tmp = (t_info *)malloc(sizeof(t_info));
	ft_info_copy(arr1, &tmp);
	ft_info_copy(arr2, arr1);
	ft_info_copy(&tmp, arr2);
	free(tmp);
}
