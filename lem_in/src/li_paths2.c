/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_paths2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:36:04 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:37:54 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_realloc_path(t_graph *graph)
{
	t_path	**paths;
	int		i;

	paths = (t_path **)malloc(sizeof(t_path*) * graph->n_pathes);
	i = -1;
	while (++i < graph->n_pathes)
	{
		paths[i] = graph->pathes[i];
		graph->pathes[i] = NULL;
	}
	free(graph->pathes);
	graph->pathes = paths;
}

void	ft_create_paths(t_graph *graph, t_lines *lines)
{
	t_room	*start;
	t_room	*end;

	graph->n_pathes = 0;
	graph->pathes = (t_path **)malloc(sizeof(t_path*) * graph->n_nodes);
	start = ft_get_start(graph->all_rooms);
	end = ft_get_end(graph->all_rooms);
	while ((graph->pathes[graph->n_pathes] =
				ft_getpath(start, end, graph)))
	{
		ft_hide_path(graph, graph->pathes[graph->n_pathes]);
		graph->n_pathes++;
		if (ft_is_dirrect(start, end))
			ft_print_if_dirrect(graph, lines);
		start = ft_get_start(graph->all_rooms);
		end = ft_get_end(graph->all_rooms);
	}
	ft_realloc_path(graph);
}

void	ft_free_paths(t_room *rooms, t_graph *graph)
{
	int	i;

	while (rooms)
	{
		rooms->d = -1;
		rooms = rooms->next;
	}
	i = 0;
	graph->pathes[0]->move = graph->n_ants;
	while (++i < graph->n_pathes)
		graph->pathes[i]->move = graph->pathes[i - 1]->move -
		(graph->pathes[i]->path_size - graph->pathes[i - 1]->path_size) * i;
}
