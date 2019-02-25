/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:10:50 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 00:11:23 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**val;
	int		*flags;

	if (ac < 2 || (!ft_is_num(av, ac) && write(1, "Error\n", 6)))
		return (0);
	if ((ac == 2) && (val = ft_strsplit(av[1], ' ')))
		if (!val[0])
			return (0);
	flags = (int *)malloc(sizeof(int) * 13);
	if (!(a = ft_create_stack((ac > 2) ? av : val, ac, &flags))
			&& write(1, "Error\n", 6))
		return (0);
	b = NULL;
	ft_choose_method(&a, &b, &flags);
	return (0);
}
