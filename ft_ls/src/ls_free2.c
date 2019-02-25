/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:16:00 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:16:03 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_arr(t_info ***arr)
{
	int i;

	if (!arr || !*arr)
		return ;
	i = -1;
	while ((*arr)[++i])
		ft_free_info((*arr)[i]);
	free(*arr);
}

void		*ft_free_data(t_manager **data)
{
	if (!data || !*data)
		return (NULL);
	ft_free_files((*data)->dir_list);
	ft_free_files((*data)->files);
	ft_free_file_list((*data)->file_list, (*data)->list_size);
	free(*data);
	return (NULL);
}
