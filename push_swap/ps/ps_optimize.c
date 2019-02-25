/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:41:22 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:44:27 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_found_opt1(int **flags)
{
	(*flags)[7] = 0;
	if ((*flags)[8] <= (*flags)[9] && (*flags)[8] <= (*flags)[10]
			&& (*flags)[8] <= (*flags)[12])
		(*flags)[4] = 1;
	else if ((*flags)[9] <= (*flags)[8] && (*flags)[9] <= (*flags)[10]
			&& (*flags)[9] <= (*flags)[12])
		(*flags)[5] = 1;
	else if ((*flags)[10] <= (*flags)[8] && (*flags)[10] <= (*flags)[9]
			&& (*flags)[10] <= (*flags)[12])
		(*flags)[6] = 1;
	else
		(*flags)[11] = 1;
}

static void	ft_free_copies(t_stack **a_cpy, t_stack **b_cpy)
{
	ft_free_stack(a_cpy);
	ft_free_stack(b_cpy);
}

void		ft_found_opt(t_stack **a, t_stack **b, int **flags)
{
	t_stack *a_cpy;
	t_stack *b_cpy;

	a_cpy = ft_cpy_stack(*a);
	b_cpy = ft_cpy_stack(*b);
	(*flags)[7] = 8;
	ft_form1(&a_cpy, &b_cpy, flags);
	ft_free_copies(&a_cpy, &b_cpy);
	a_cpy = ft_cpy_stack(*a);
	b_cpy = ft_cpy_stack(*b);
	(*flags)[7] = 9;
	ft_form2(&a_cpy, &b_cpy, flags);
	ft_free_copies(&a_cpy, &b_cpy);
	a_cpy = ft_cpy_stack(*a);
	b_cpy = ft_cpy_stack(*b);
	(*flags)[7] = 10;
	ft_form3(&a_cpy, &b_cpy, flags);
	ft_free_copies(&a_cpy, &b_cpy);
	a_cpy = ft_cpy_stack(*a);
	b_cpy = ft_cpy_stack(*b);
	(*flags)[7] = 12;
	ft_form4(&a_cpy, &b_cpy, flags);
	ft_free_copies(&a_cpy, &b_cpy);
	ft_found_opt1(flags);
	ft_choose_method(a, b, flags);
}

void		ft_choose_method(t_stack **a, t_stack **b, int **flags)
{
	if ((*flags)[4])
		ft_form1(a, b, flags);
	else if ((*flags)[5])
		ft_form2(a, b, flags);
	else if ((*flags)[6])
		ft_form3(a, b, flags);
	else if ((*flags)[11] || ft_get_size(*a) > 505)
		ft_form4(a, b, flags);
	else if (!ft_is_sort_b(*a) && (ft_get_size(*a) == 100
		|| ft_get_size(*a) == 500))
		ft_form6(a, b, flags);
	else
		ft_found_opt(a, b, flags);
}
