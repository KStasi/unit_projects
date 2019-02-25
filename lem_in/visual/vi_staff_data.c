/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_staff_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:33:44 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:33:46 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		ft_error_generate(void)
{
	ft_putendl("ERROR");
	exit(0);
}

int		*ft_find_max(t_graph *graph)
{
	t_room	*room;
	int		*max;

	max = (int *)malloc(sizeof(int) * 2);
	max[0] = graph->all_rooms->x;
	max[1] = graph->all_rooms->y;
	room = graph->all_rooms->next;
	while (room)
	{
		max[0] = (max[0] > room->x) ? max[0] : room->x;
		max[1] = (max[1] > room->y) ? max[1] : room->y;
		room = room->next;
	}
	max[0] = 1000 / ++max[0];
	max[1] = 1000 / ++max[1];
	return (max);
}

void	ft_read_lems(char **line, t_lines *lines)
{
	while (get_next_line(0, line) > 0)
		ft_set_lines(line, &lines);
}

int		ft_create_graph(t_graph *graph, t_lines *lines)
{
	char	*line;
	int		status;
	int		d;

	line = NULL;
	ft_get_n_ants(line, graph, &status);
	while ((d = get_next_line(0, &line)) > 0)
	{
		status = (status == 1 || status == -1) ? status : ft_get_status(line);
		if (status && line[0] == '#')
		{
			status = (status == 2) ? 0 : status;
			ft_free_line(&line, NULL);
			continue;
		}
		if (!ft_create_node(line, graph, status))
			break ;
		status = 0;
	}
	if (!graph->n_nodes)
		ft_free_line(&line, NULL);
	return ((graph->n_nodes && d) ? ft_read_tubes(graph, &line, lines) : 0);
}
