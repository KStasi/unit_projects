/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_opscheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:50:00 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/22 01:50:02 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_check_ops(char **op)
{
	int i;

	i = -1;
	if (!op)
		return (1);
	while (op[++i])
		if (ft_strcmp(op[i], "sa") && ft_strcmp(op[i], "sb") &&
			ft_strcmp(op[i], "ss") && ft_strcmp(op[i], "pa") &&
			ft_strcmp(op[i], "pb") && ft_strcmp(op[i], "ra") &&
			ft_strcmp(op[i], "rb") && ft_strcmp(op[i], "rr") &&
			ft_strcmp(op[i], "rra") && ft_strcmp(op[i], "rrb") &&
			ft_strcmp(op[i], "rrr"))
			return (0);
	return (1);
}

int		ft_check_val(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = *a;
	while (*a != tmp->next && tmp->el < tmp->next->el)
		tmp = tmp->next;
	if (*a == tmp->next && !*b)
		return (1);
	return (0);
}

int		ft_free_ops(char **ops)
{
	int i;

	i = -1;
	if (!ops || !*ops)
		return (1);
	while (ops[++i])
		free(ops[i]);
	if (ops)
		free(ops);
	return (1);
}

void	ft_free_p(char **p)
{
	if (p && *p)
		free(*p);
}

int		ft_procced_ops(t_stack **a, t_stack **b)
{
	char	*op;
	char	**ops;
	char	*buf;
	char	*p;

	buf = NULL;
	while (gnl(0, &op) > 0)
	{
		p = buf;
		buf = ft_strjoin(buf, op);
		ft_free_p(&p);
		p = buf;
		buf = ft_strjoin(buf, " ");
		ft_free_p(&p);
		free(op);
	}
	ops = ft_strsplit(buf, ' ');
	if (buf)
		free(buf);
	if (!ft_check_ops(ops) && ft_free_ops(ops))
		return (-1);
	ft_try_sort(a, b, ops, ft_count_ops(ops));
	ft_free_ops(ops);
	return (ft_check_val(a, b));
}
