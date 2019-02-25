/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:49:43 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/23 17:05:52 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*ft_create_list(char *num)
{
	t_stack *new;

	if (!num || !*num)
		return (NULL);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->el = ft_atoi(num);
	new->next = NULL;
	return (new);
}

static void	ft_free_num(char **num)
{
	if (num && *num)
		free(*num);
	*num = NULL;
}

int			ft_check_correct(char **av, int ac)
{
	int		i;
	int		j;
	char	*num;

	i = -1;
	num = NULL;
	while (av && av[++i])
	{
		j = i;
		while (av[++j])
			if (!ft_strcmp(av[i], av[j]))
				return (0);
		if (!ft_check_range(av[i]) ||
			(!(ac != 2 && i == 0) &&
				ft_strcmp((num = ft_itoa(ft_atoi(av[i]))), av[i])))
		{
			ft_free_num(&num);
			return (0);
		}
		ft_free_num(&num);
	}
	return (1);
}

t_stack		*ft_create_stack(char **av, int ac)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;

	if (!ft_check_correct(av, ac))
		return (NULL);
	stack = ft_create_list(av[(ac > 2) ? 1 : 0]);
	tmp = stack;
	i = (ac > 2) ? 1 : 0;
	if (ac > 2)
		while (++i < ac)
		{
			tmp->next = ft_create_list(av[i]);
			tmp = tmp->next;
		}
	else
		while (av[++i])
		{
			tmp->next = ft_create_list(av[i]);
			tmp = tmp->next;
		}
	tmp->next = stack;
	return (stack);
}

void		ft_show_stacks(t_stack *s)
{
	t_stack	*tmp;
	int		i;

	tmp = s;
	i = 0;
	ft_putstr("\nSTACK:\n\n");
	while (tmp && tmp->next != s)
	{
		ft_putnbr(tmp->el);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	if (tmp)
	{
		ft_putnbr(tmp->el);
		ft_putchar('\n');
	}
}
