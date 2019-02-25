/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_thirdalg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:08:22 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 00:08:25 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_form3(t_stack **a, t_stack **b, int **flags)
{
	int el;

	while (*a)
	{
		el = (*a)->el;
		ft_p(b, a, 'b', flags);
		if (el < (*b)->next->el && (*b)->el != (*b)->next->el)
		{
			ft_r(b, 'b', flags);
			while ((*b)->el != (*b)->next->el && (*b)->el > el)
				ft_p(a, b, 'a', flags);
			ft_rr(b, 'b', flags);
		}
	}
	ft_finalize2(a, b, flags);
}
