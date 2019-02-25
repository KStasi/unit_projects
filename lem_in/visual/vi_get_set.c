/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_get_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:28:34 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:28:45 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_set_lines(char **line, t_lines **lines)
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
	else if (line && *line && **line)
		free(*line);
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

void	ft_set_col(SDL_Color *col, int d)
{
	col->r = d % 256;
	col->g = d * d % 256;
	col->b = d * d * d % 256;
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

void	ft_get_n_ants(char *line, t_graph *graph, int *status)
{
	while (get_next_line(0, &line) > 0 && ft_is_comment(line, 0))
		continue ;
	if (line && ft_is_num(line) && ft_atoi(line) > 0)
		graph->n_ants = ft_atoi(line);
	else
	{
		ft_free_line(&line, NULL);
		ft_error_generate();
	}
	*status = 0;
	graph->n_nodes = 0;
	graph->n_pathes = 0;
	ft_free_line(&line, NULL);
}
