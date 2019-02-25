/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sixthalg4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:52:33 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:53:11 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_b(t_stack **a, t_stack **b, int depth_b, int **flags)
{
	if (depth_b > 1 && (*b)->el > (*b)->next->el)
		ft_ss(a, b, flags);
	else
		ft_s(a, 'a', 1, flags);
}

static void	ft_swap_a(t_stack **a, t_stack **b, int *depth, int **flags)
{
	ft_p(b, a, 'b', flags);
	if (depth[1] > 1 && (*b)->el > (*b)->next->el)
	{
		if (depth[0] > 1 && (*a)->el > (*a)->next->el)
			ft_ss(a, b, flags);
		else
			ft_s(b, 'b', 1, flags);
	}
}

static int	ft_change(int *a, int *b)
{
	(*a)--;
	(*b)++;
	return (1);
}

static int	ft_place_el(t_stack **a, t_stack **b, int *depth, int **flags)
{
	ft_p(a, b, 'a', flags);
	ft_r(a, 'a', flags);
	return (ft_find_min5a(*a, *b, depth[0], depth[1]));
}

void		ft_sort_5a(t_stack **a, t_stack **b, int place, int **flags)
{
	int depth[2];
	int max;
	int min;

	depth[0] = ft_init_value(a, b, &min, &max);
	depth[1] = 0;
	while (!ft_sort_place(*a, *b, place) || depth[0] || depth[1])
		if (depth[0] == 5 && !depth[1] && ft_is_reversed(*a) == 1)
			depth[0] = ft_magic(a, b, place, flags);
		else if (ft_present_el(*a, depth[0], min) && (*a)->el != max
		&& (*a)->el != min && ft_change(&depth[0], &depth[1]))
			ft_swap_a(a, b, depth, flags);
		else if (ft_present_el(*b, depth[1], min) &&
		(*b)->el == min && depth[1]-- > 0)
			min = ft_place_el(a, b, depth, flags);
		else if ((*a)->el == min && depth[0]-- > 0)
		{
			ft_r(a, 'a', flags);
			min = ft_find_min5a(*a, *b, depth[0], depth[1]);
		}
		else if ((*a)->el == max && depth[0] != 1)
			ft_swap_b(a, b, depth[1], flags);
		else if (depth[1] == 2 && (*a)->el == max &&
		(*b)->el != min && ft_change(&depth[1], &depth[0]))
			ft_p(a, b, 'a', flags);
}
