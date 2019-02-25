/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sixthalg8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:57:12 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:58:32 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_merge_all100(t_stack **a, t_stack **b, int **flags)
{
	int range[3];
	int i;

	i = -1;
	while (++i < 6 && ft_set_range(range, 5, 5, 1))
		ft_merge_two(b, a, range, flags);
	i = -1;
	while (++i < 6 && ft_set_range(range, 10, 5, 1))
		ft_merge_two(b, a, range, flags);
	i = -1;
	while (++i < 2 && ft_set_range(range, 5, 15, 0))
		ft_merge_two(a, b, range, flags);
	i = -1;
	while (++i < 2 && ft_set_range(range, 20, 15, 0))
		ft_merge_two(a, b, range, flags);
	ft_set_range(range, 35, 15, 0);
	ft_merge_two(a, b, range, flags);
	ft_set_range(range, 15, 50, 1);
	ft_merge_two(b, a, range, flags);
	ft_set_range(range, 35, 65, 0);
	ft_merge_two(a, b, range, flags);
}

static void	ft_merge_all5001(t_stack **a, t_stack **b, int **flags)
{
	int range[3];
	int i;

	i = -1;
	while (++i < 2 && ft_set_range(range, 35, 100, 0))
		ft_merge_two(a, b, range, flags);
	ft_set_range(range, 135, 100, 0);
	ft_merge_two(a, b, range, flags);
	ft_set_range(range, 135, 65, 0);
	ft_merge_two(a, b, range, flags);
	ft_set_range(range, 65, 200, 1);
	ft_merge_two(b, a, range, flags);
	ft_set_range(range, 235, 265, 0);
	ft_merge_two(a, b, range, flags);
}

void		ft_merge_all500(t_stack **a, t_stack **b, int **flags)
{
	int range[3];
	int i;

	i = -1;
	while (++i < 30 && ft_set_range(range, 5, 5, 1))
		ft_merge_two(b, a, range, flags);
	i = -1;
	while (++i < 30 && ft_set_range(range, 10, 5, 1))
		ft_merge_two(b, a, range, flags);
	i = -1;
	while (++i < 10 && ft_set_range(range, 5, 15, 0))
		ft_merge_two(a, b, range, flags);
	i = -1;
	while (++i < 10 && ft_set_range(range, 20, 15, 0))
		ft_merge_two(a, b, range, flags);
	i = -1;
	while (++i < 5 && ft_set_range(range, 35, 15, 0))
		ft_merge_two(a, b, range, flags);
	i = -1;
	while (++i < 5 && ft_set_range(range, 15, 50, 1))
		ft_merge_two(b, a, range, flags);
	i = -1;
	while (++i < 3 && ft_set_range(range, 65, 35, 1))
		ft_merge_two(b, a, range, flags);
	ft_merge_all5001(a, b, flags);
}
