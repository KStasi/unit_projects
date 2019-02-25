/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:19:32 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:19:46 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	ft_nlen(long long n)
{
	if (n == LLONG_MIN)
		return (19);
	if (n < 0)
		return (1 + ft_nlen(-n));
	if (n /= 10)
		return (1 + ft_nlen(n));
	return (1);
}
