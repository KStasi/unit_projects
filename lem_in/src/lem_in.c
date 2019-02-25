/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:24:31 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:26:35 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_graph graph;
	t_lines *lines;

	lines = (t_lines *)malloc(sizeof(t_lines));
	lines->line = NULL;
	lines->next = NULL;
	if (!ft_create_graph(&graph, lines))
		ft_error_generate(6);
	if (!ft_check_nodes(graph))
		ft_error_generate(0);
	ft_create_paths(&graph, lines);
	if (!graph.n_pathes)
		ft_error_generate(1);
	ft_print_input(lines);
	ft_print_result(&graph);
	return (0);
}
