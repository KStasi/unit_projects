/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:28:52 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:30:25 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_range(char *s)
{
	long long	d;

	d = ft_atoll(s);
	return (d >= -2147483648 && d <= 2147483647);
}

int		ft_check_arr(char **arr)
{
	int i;

	i = 0;
	if (!arr || !arr[0] || ft_strchr(arr[0], '-'))
		return (0);
	while (arr[++i])
		if (!ft_is_num(arr[i]))
			return (0);
	return ((i == 3));
}

int		ft_check_format(t_graph *graph, char *line)
{
	char	**names;
	int		found[2];
	t_room	*tmp;

	if (!ft_strchr(line, '-') || ft_strchr(line, '-') == line || !graph ||
			ft_strchr(line, '-') != ft_strrchr(line, '-') || !graph->all_rooms
			|| ft_strchr(line, '-') == line + ft_strlen(line) - 1)
		return (0);
	names = ft_strsplit(line, '-');
	ft_bzero(found, sizeof(int) * 2);
	tmp = graph->all_rooms;
	while (tmp)
	{
		found[0] = (strcmp(names[0], tmp->name)) ? found[0] : 1;
		found[1] = (strcmp(names[1], tmp->name)) ? found[1] : 1;
		tmp = tmp->next;
	}
	ft_free_arr(names);
	return ((found[0] && found[1]));
}

int		ft_check_atrs(int **atrs)
{
	int result;

	result = ((*atrs)[0] == 1 && (*atrs)[1] == 1);
	free(*atrs);
	return (result);
}

int		ft_check_nodes(t_graph graph)
{
	int		i;
	t_room	*tmp1;
	t_room	*tmp2;
	int		*atrs;

	i = -1;
	atrs = (int *)malloc(sizeof(int) * 2);
	ft_bzero(atrs, sizeof(int) * 2);
	tmp1 = graph.all_rooms;
	while (++i < graph.n_nodes && (tmp2 = tmp1->next) != tmp1)
	{
		while (tmp2)
		{
			if (!ft_strcmp(tmp1->name, tmp2->name) || (tmp1->x == tmp2->x &&
				tmp1->y == tmp2->y))
				ft_error_generate(2);
			tmp2 = tmp2->next;
		}
		if (!ft_set_attrs(&atrs, tmp1->status))
			ft_error_generate(3);
		else if (tmp1->name[0] == 'L')
			ft_error_generate(7);
		tmp1 = tmp1->next;
	}
	return (ft_check_atrs(&atrs));
}
