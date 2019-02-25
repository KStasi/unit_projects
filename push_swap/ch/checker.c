/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:50:09 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/23 17:07:32 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**val;
	int		c;

	if (ac < 2)
		return (0);
	if (!ft_ifnum(av, ac) && write(1, "Error\n", 6))
		return (0);
	if (ac == 2)
		if (!(val = ft_strsplit(av[1], ' ')) || !val[0])
			return (0);
	if (!(a = ft_create_stack((ac > 2) ? av : val, ac)) &&
		write(1, "Error\n", 6))
		return (0);
	b = NULL;
	if ((c = ft_procced_ops(&a, &b)) <= 0)
		write(1, (c == 0) ? "KO\n" : "Error\n", (c == 0) ? 3 : 6);
	else
		write(1, "OK\n", 3);
	return (0);
}
