/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sixthalg6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:54:25 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:54:45 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_set_range(int *range, int a, int b, int c)
{
	range[0] = a;
	range[1] = b;
	range[2] = c;
	return (1);
}

void	ft_prepare_stack100(t_stack **a, t_stack **b, int **flags)
{
	int i;

	i = -1;
	while (++i < 14)
		ft_sort_5a(a, b, 1, flags);
	while (++i < 21)
		ft_sort_5b(a, b, 0, flags);
}

void	ft_prepare_stack500(t_stack **a, t_stack **b, int **flags)
{
	int i;

	i = -1;
	while (++i < 70)
		ft_sort_5a(a, b, 1, flags);
	while (++i < 101)
		ft_sort_5b(a, b, 0, flags);
}
