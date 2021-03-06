/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:07:45 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/18 17:23:20 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap(ssize_t *a, ssize_t *b)
{
	ssize_t temp;

	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}
