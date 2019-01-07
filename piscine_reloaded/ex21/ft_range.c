/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:00:47 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/22 20:01:27 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int i;

	if (max <= min)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (max - min));
	i = -1;
	while (++i < max - min)
		arr[i] = min + i;
	return (arr);
}
