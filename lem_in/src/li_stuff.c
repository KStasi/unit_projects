/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:40:30 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:41:15 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_error_generate(int err)
{
	ft_putendl("ERROR:");
	if (!err)
		ft_putendl("End or start missed");
	else if (err == 1)
		ft_putendl("No pathes exists");
	else if (err == 2)
		ft_putendl("Double coordinate or names");
	else if (err == 3)
		ft_putendl("Two starts or ends");
	else if (err == 4)
		ft_putendl("Incorrect format of aunts number");
	else if (err == 5)
		ft_putendl("Tubes missed or have incorrect names");
	else if (err == 6)
		ft_putendl("Too few data");
	else if (err == 7)
		ft_putendl("Name starts with L");
	exit(0);
}

int		ft_get_status(char *line)
{
	if (line[0] != '#')
		return (0);
	if (!ft_strncmp(line, "##start\0", 8))
		return (-1);
	if (!ft_strncmp(line, "##end\0", 6))
		return (1);
	return (2);
}

void	ft_add_tube(t_room *a, t_room *b, int size)
{
	int i;

	if (a == b)
		return ;
	i = -1;
	while (++i < a->list_size)
		if (a->list[i] == b)
			return ;
	if (!a->list_size)
		a->list = (t_room **)malloc(sizeof(t_room *) * (size - 1));
	if (!b->list_size)
		b->list = (t_room **)malloc(sizeof(t_room *) * (size - 1));
	a->list[(a->list_size)++] = b;
	b->list[(b->list_size)++] = a;
}

int		ft_read_tubes(t_graph *graph, char **line, t_lines *lines)
{
	int i;

	i = 0;
	if (line && *line && ft_check_format(graph, *line))
		ft_create_tube(graph, *line, &i, lines);
	else if (!line || !*line || !**line || (!ft_is_comment(*line, 1, lines)))
		return (0);
	while (get_next_line(0, line) > 0)
		if (ft_check_format(graph, *line))
			ft_create_tube(graph, *line, &i, lines);
		else if (!ft_is_comment(*line, 1, lines))
			break ;
	return ((i) ? 1 : 0);
}

int		ft_set_attrs(int **atrs, int status)
{
	if (!status)
		return (1);
	if ((status == -1 && (*atrs)[0]) || (status == 1 && (*atrs)[1]))
		return (0);
	(*atrs)[0] = (status == -1) ? 1 : (*atrs)[0];
	(*atrs)[1] = (status == 1) ? 1 : (*atrs)[1];
	return (1);
}
