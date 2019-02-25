/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_paths1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:34:00 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:35:52 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_get_start(t_room *all_rooms)
{
	while (all_rooms->status != -1)
		all_rooms = all_rooms->next;
	return (all_rooms);
}

t_room	*ft_get_end(t_room *all_rooms)
{
	while (all_rooms->status != 1)
		all_rooms = all_rooms->next;
	return (all_rooms);
}

int		ft_wave(t_room *all, int d, int size)
{
	int		i;
	int		j;
	int		found;
	t_room	*source;

	i = -1;
	found = 0;
	source = all;
	while (++i < size && (j = -1))
	{
		if (source->d == d)
		{
			while (++j < source->list_size)
				if (source->list[j]->status == 1)
					return (((source->list[j])->d = d + 1));
				else if ((source->list[j])->status != -2 &&
				(source->list[j])->d == -1 && (found = 1))
					(source->list[j])->d = d + 1;
		}
		source = source->next;
	}
	return ((found) ? ft_wave(all, d + 1, size) : 0);
}

void	ft_reset_path(int d, t_path *path, t_room *end)
{
	int i;

	path->rooms = (t_room **)malloc(sizeof(t_room *) * (d + 1));
	path->rooms[d] = end;
	path->path_size = d + 1;
	while (d--)
	{
		i = -1;
		while (++i < end->list_size)
			if (end->list[i]->d == d)
				break ;
		end = end->list[i];
		path->rooms[d] = end;
	}
}

t_path	*ft_getpath(t_room *start, t_room *end, t_graph *graph)
{
	int		d;
	t_path	*path;

	path = (t_path *)malloc(sizeof(t_path));
	path->path_size = 0;
	start->d = 0;
	if (!(d = ft_wave(graph->all_rooms, 0, graph->n_nodes)))
	{
		free(path);
		return (NULL);
	}
	ft_reset_path(d, path, end);
	return (path);
}
