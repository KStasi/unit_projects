/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fifthalg2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:28:30 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:29:02 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_form5(t_stack **a, t_stack **b, int **flags)
{
	int		n;

	n = ft_get_size(*a);
	ft_push_to_b(a, b, flags, n / 2);
	ft_sort_both(a, b, flags);
	ft_merge(a, b, flags);
}
