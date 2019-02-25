/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_creators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:30:42 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/06 14:26:02 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_create_room(t_room **last, char **arr, int status)
{
	*last = (t_room *)malloc(sizeof(t_room));
	(*last)->name = ft_strdup(arr[0]);
	(*last)->x = ft_atoi(arr[1]);
	(*last)->y = ft_atoi(arr[2]);
	(*last)->next = NULL;
	(*last)->status = status;
	(*last)->list = NULL;
	(*last)->list_size = 0;
	(*last)->d = -1;
}

int			ft_create_node(char *line, t_graph *graph, int status,
			t_lines *lines)
{
	t_room	*last;
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (!ft_check_arr(arr))
	{
		ft_free_arr(arr);
		return (0);
	}
	if (graph->n_nodes)
	{
		last = graph->all_rooms;
		while (last->next)
			last = last->next;
		ft_create_room(&(last->next), arr, status);
	}
	else
		ft_create_room(&(graph->all_rooms), arr, status);
	ft_free_arr(arr);
	ft_free_line(&line, &lines);
	graph->n_nodes++;
	return (1);
}

void		ft_create_tube(t_graph *graph, char *line, int *n_tubes,
			t_lines *lines)
{
	char		**names;
	t_room		*found[2];
	t_room		*tmp;

	names = ft_strsplit(line, '-');
	ft_free_line(&line, &lines);
	tmp = graph->all_rooms;
	while (tmp)
	{
		found[0] = (strcmp(names[0], tmp->name)) ? found[0] : tmp;
		found[1] = (strcmp(names[1], tmp->name)) ? found[1] : tmp;
		tmp = tmp->next;
	}
	ft_free_arr(names);
	ft_add_tube(found[0], found[1], graph->n_nodes);
	(*n_tubes)++;
}

static void	ft_get_n_ants(char *line, t_lines *lines, t_graph *graph,
			int *status)
{
	while (get_next_line(0, &line) > 0 && ft_is_comment(line, 0, lines))
		continue ;
	if (line && ft_is_num(line) && ft_atoi(line) > 0)
		graph->n_ants = ft_atoi(line);
	else
	{
		ft_free_line(&line, &lines);
		ft_error_generate(4);
	}
	*status = 0;
	graph->n_nodes = 0;
	graph->n_pathes = 0;
	ft_free_line(&line, &lines);
}

int			ft_create_graph(t_graph *graph, t_lines *lines)
{
	char	*line;
	int		status;
	int		d;

	line = NULL;
	ft_get_n_ants(line, lines, graph, &status);
	while ((d = get_next_line(0, &line)) > 0)
	{
		if ((status == 1 || status == -1) && (ft_get_status(line) == 1 ||
		ft_get_status(line) == -1))
			ft_error_generate(3);
		status = (status == 1 || status == -1) ? status : ft_get_status(line);
		if (status && line[0] == '#')
		{
			status = (status == 2) ? 0 : status;
			ft_free_line(&line, &lines);
			continue;
		}
		if (!ft_create_node(line, graph, status, lines))
			break ;
		status = 0;
	}
	if (!graph->n_nodes || (d && line && !*line))
		ft_free_line(&line, NULL);
	return (ft_is_approp(graph, &line, lines, d));
}
