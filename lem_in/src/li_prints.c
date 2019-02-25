/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:39:10 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:40:18 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_ants(t_graph *graph)
{
	int i;
	int j;

	i = -1;
	while (++i < graph->n_pathes)
	{
		j = graph->pathes[i]->path_size - 1;
		while (--j)
			if (graph->pathes[i]->rooms[j]->d != -1)
				ft_printf("L%d-%s ", graph->pathes[i]->rooms[j]->d,
						graph->pathes[i]->rooms[j]->name);
	}
	if (graph->pathes[0]->rooms[0]->status == -1 &&
		graph->pathes[0]->rooms[1]->status
		== 1)
		ft_printf("L%d-%s ", graph->pathes[0]->rooms[1]->d,
				graph->pathes[0]->rooms[1]->name);
	ft_putchar('\n');
}

int		ft_poses_ants(t_graph *graph, int ants)
{
	int i;
	int j;

	i = -1;
	while (++i < graph->n_pathes && (j = graph->pathes[i]->path_size) != -1)
	{
		while (--j > 0)
			if (graph->pathes[i]->rooms[j - 1]->d != -1)
			{
				if (j == graph->pathes[i]->path_size - 1)
					ft_printf("L%d-%s ", graph->pathes[i]->rooms[j - 1]->d,
					graph->pathes[i]->rooms[j]->name);
				graph->pathes[i]->rooms[j]->d =
						graph->pathes[i]->rooms[j - 1]->d;
				graph->pathes[i]->rooms[j - 1]->d = -1;
			}
			else
				graph->pathes[i]->rooms[j]->d = -1;
		if (ants < graph->pathes[i]->move)
			graph->pathes[i]->rooms[1]->d = ++ants;
		else
			graph->pathes[i]->rooms[1]->d = -1;
	}
	ft_print_ants(graph);
	return (ants);
}

int		ft_poses_ants1(t_graph *graph, int ants)
{
	int i;
	int j;

	i = -1;
	while (++i < graph->n_pathes && (j = graph->pathes[i]->path_size) != -1)
	{
		while (--j > 0)
			if (graph->pathes[i]->rooms[j - 1]->d != -1)
			{
				if (j == graph->pathes[i]->path_size - 1)
					ft_printf("L%d-%s ", graph->pathes[i]->rooms[j - 1]->d,
					graph->pathes[i]->rooms[j]->name);
				graph->pathes[i]->rooms[j]->d =
						graph->pathes[i]->rooms[j - 1]->d;
				graph->pathes[i]->rooms[j - 1]->d = -1;
			}
			else
				graph->pathes[i]->rooms[j]->d = -1;
		if (ants < graph->n_ants)
			graph->pathes[i]->rooms[1]->d = ++ants;
		else
			graph->pathes[i]->rooms[1]->d = -1;
	}
	ft_print_ants(graph);
	return (ants);
}

void	ft_push_ants(t_graph *graph)
{
	while (!ft_is_empty(graph))
		ft_poses_ants1(graph, graph->n_ants);
}

void	ft_print_result(t_graph *graph)
{
	int i;

	i = 0;
	ft_free_paths(graph->all_rooms, graph);
	while (i < graph->n_ants)
	{
		i = ft_poses_ants(graph, i);
	}
	ft_push_ants(graph);
}
