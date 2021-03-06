/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:31:56 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 14:32:01 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s1, int c)
{
	int i;

	i = -1;
	while (++i != -1)
		if (s1[i] == c)
			return ((char *)s1 + i);
		else if (s1[i] == '\0')
			break ;
	return (NULL);
}
