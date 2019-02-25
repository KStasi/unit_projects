/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sixthalg5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:53:28 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:54:10 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_change(int *a, int *b)
{
	(*a)--;
	(*b)++;
	return (1);
}

static int	ft_init_val(t_stack **a, t_stack **b, int *min, int *max)
{
	*min = ft_find_min5b(*a, *b, 5, 0);
	*max = ft_find_max5b(*a, *b, 5, 0);
	return (5);
}

void		ft_sort_5b(t_stack **a, t_stack **b, int place, int **flags)
{
	int val[2];
	int depth[2];

	depth[0] = ft_init_val(a, b, &val[0], &val[1]);
	depth[1] = 0;
	while (!ft_sort_place(*a, *b, place) || depth[0] || depth[1])
		if (depth[0] == 5 && ft_is_reversed(*a) == 1 && !(depth[0] = 0))
			ft_magic(a, b, place, flags);
		else if (ft_present_el(*a, depth[0], val[0]) && (*a)->el != val[1]
				&& (*a)->el != val[0] && depth[0]-- > 0 && ++depth[1])
			ft_r(a, 'a', flags);
		else if (!ft_present_el(*a, depth[0], val[0]) &&
		depth[1] > 0 && ft_change(&depth[1], &depth[0]))
			ft_rr(a, 'a', flags);
		else if ((*a)->el == val[0] && depth[0]-- > 0)
		{
			ft_p(b, a, 'b', flags);
			val[0] = ft_find_min5b(*a, *b, depth[0], depth[1]);
		}
		else if ((*a)->el == val[1] && depth[0] != 1)
			ft_s(a, 'a', 1, flags);
		else if (ft_present_el(*a, depth[0], val[0]) && (*a)->el != val[0])
			ft_s(a, 'a', 1, flags);
}
