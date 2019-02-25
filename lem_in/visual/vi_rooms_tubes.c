/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_rooms_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:33:12 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:33:21 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_add_tube(t_room *a, t_room *b, int size)
{
	if (!a->list_size)
		a->list = (t_room **)malloc(sizeof(t_room *) * (size - 1));
	if (!b->list_size)
		b->list = (t_room **)malloc(sizeof(t_room *) * (size - 1));
	a->list[(a->list_size)++] = b;
	b->list[(b->list_size)++] = a;
}

void	ft_create_tube(t_graph *graph, char *line, int *n_tubes)
{
	char		**names;
	t_room		*found[2];
	t_room		*tmp;

	names = ft_strsplit(line, '-');
	ft_free_line(&line, NULL);
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

int		ft_read_tubes(t_graph *graph, char **line, t_lines *lines)
{
	int i;

	i = 0;
	if (line && *line && ft_check_format(graph, *line))
		ft_create_tube(graph, *line, &i);
	else if (!line || !*line || !**line || (!ft_is_comment(*line, 1)))
		return (0);
	while (get_next_line(0, line) > 0)
		if (ft_check_format(graph, *line))
			ft_create_tube(graph, *line, &i);
		else if (!ft_is_comment(*line, 1))
			break ;
	ft_read_lems(line, lines);
	return ((i) ? 1 : 0);
}

void	ft_create_room(t_room **last, char **arr, int status)
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

int		ft_create_node(char *line, t_graph *graph, int status)
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
	ft_free_line(&line, NULL);
	graph->n_nodes++;
	return (1);
}
