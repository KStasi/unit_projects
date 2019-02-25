/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_paths3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:38:27 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:38:55 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_input(t_lines *lines)
{
	t_lines *l;

	l = lines;
	while (l)
	{
		if (ft_strlen(l->line))
			ft_putendl(l->line);
		l = l->next;
	}
	ft_putendl("");
}

void	ft_print_if_dirrect(t_graph *graph, t_lines *lines)
{
	int i;

	ft_print_input(lines);
	i = 0;
	while (++i < graph->n_ants + 1)
		ft_printf("L%d-%s ", i, graph->pathes[0]->rooms[1]->name);
	ft_putchar('\n');
	exit(0);
}

void	ft_hide_path(t_graph *graph, t_path *path)
{
	int		i;
	t_room	*tmp;

	tmp = graph->all_rooms;
	while (tmp && (i = -1))
	{
		while (++i < path->path_size)
			if (path->rooms[i] == tmp && tmp->status == 0)
				tmp->status = -2;
		tmp->d = -1;
		tmp = tmp->next;
	}
}

int		ft_is_dirrect(t_room *start, t_room *end)
{
	int i;

	i = -1;
	while (++i < start->list_size)
		if (start->list[i] == end)
			return (1);
	return (0);
}

int		ft_is_empty(t_graph *graph)
{
	int i;
	int j;

	i = -1;
	while (++i < graph->n_pathes)
	{
		j = graph->pathes[i]->path_size;
		while (--j)
			if (graph->pathes[i]->rooms[j - 1]->d != -1)
				return (0);
	}
	return (1);
}
