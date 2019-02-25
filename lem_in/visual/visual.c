/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:34:06 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:38:26 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		main(void)
{
	t_graph	graph;
	t_lines	*lines;

	lines = (t_lines *)malloc(sizeof(t_lines));
	lines->line = NULL;
	lines->next = NULL;
	ft_create_graph(&graph, lines);
	if (lines->line)
		draw(&graph, lines);
	else
		ft_error_generate();
	return (0);
}
