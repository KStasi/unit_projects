/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stackmanager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:07:02 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 00:07:52 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_cpy_stack(t_stack *a)
{
	t_stack	*stack;
	t_stack	*tmp;
	t_stack *tmp1;
	char	*num;

	if (!a)
		return (NULL);
	num = ft_itoa(a->el);
	stack = ft_create_list(num);
	if (num)
		free(num);
	tmp = stack;
	tmp1 = a->next;
	while (tmp1 != a)
	{
		num = ft_itoa(tmp1->el);
		tmp->next = ft_create_list(num);
		if (num)
			free(num);
		tmp = tmp->next;
		tmp1 = tmp1->next;
	}
	tmp->next = stack;
	return (stack);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*strs;
	t_stack	*ends;
	t_stack *tmp;

	if (!a || !*a)
		return ;
	strs = *a;
	ends = *a;
	while (ends->next != *a)
		ends = ends->next;
	ends->next = NULL;
	while (strs != NULL)
	{
		tmp = strs;
		strs = strs->next;
		free(tmp);
	}
}

t_stack	*ft_create_list(char *num)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->el = ft_atoi(num);
	new->next = NULL;
	return (new);
}

t_stack	*ft_create_stack(char **av, int ac, int **flags)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		i;

	if (!ft_check_correct(av, ac))
		return (NULL);
	i = (ac > 2) ? 1 : 0;
	i = ft_parse_flags(i, av, flags);
	if (((!av || !av[i]) && !(*flags)[2]) || ((*flags)[2] &&
	!ft_read_from_file(&av, &i, &ac, *flags)))
		return (NULL);
	stack = ft_create_list(av[i]);
	tmp = stack;
	i++;
	while ((ac > 2 && i < ac) || av[i])
	{
		tmp->next = ft_create_list(av[i]);
		tmp = tmp->next;
		i++;
	}
	tmp->next = stack;
	return (stack);
}
