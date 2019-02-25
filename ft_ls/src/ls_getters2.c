/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_getters2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 04:20:27 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/11 04:20:43 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_manager	*ft_get_names(int ac, char **av)
{
	t_manager	*data;
	int			i;

	data = (t_manager *)malloc(sizeof(t_manager));
	data->dir_list = NULL;
	data->file_list = NULL;
	data->files = NULL;
	data->list_end = NULL;
	data->list_size = 0;
	if (!ft_check_correct(av, ac))
		return (ft_free_data(&data));
	i = ft_parse_flags(ac, av, &data);
	ft_create_file_list(i - 1, ac, av, data);
	if (ac < 2 || ac == i)
		return (ft_create_singledata(data));
	return (data);
}
