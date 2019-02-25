/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bool_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:28:13 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:28:35 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_line(char **line, t_lines **lines)
{
	t_lines *l;

	if (lines)
	{
		l = *lines;
		while (*lines && l->line && l->next)
			l = l->next;
		if (*lines && (*lines)->line)
		{
			l->next = (t_lines *)malloc(sizeof(t_lines));
			l = l->next;
		}
		l->line = *line;
		l->next = NULL;
	}
	else if (line && *line)
		free(*line);
	*line = NULL;
}

void		ft_free_arr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int			ft_is_num(char *str)
{
	int j;

	j = -1;
	while (++j < (int)ft_strlen(str))
		if (!ft_isdigit(str[j]) && !((str[j] == '-'
		|| str[j] == '+') && !j))
			return (0);
	if (!ft_check_range(str))
		return (0);
	return (1);
}

int			ft_is_comment(char *line, int del, t_lines *lines)
{
	if (line && *line && line[0] == '#')
	{
		ft_free_line(&line, &lines);
		return (1);
	}
	if (del)
		ft_free_line(&line, &lines);
	return (0);
}

int			ft_is_approp(t_graph *graph, char **line, t_lines *lines, int d)
{
	return ((graph->n_nodes && d && *line) ?
		ft_read_tubes(graph, line, lines) : 0);
}
