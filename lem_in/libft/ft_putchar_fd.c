/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:57:23 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 17:57:25 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(int c, int fd)
{
	unsigned char buff[4];

	if (c < 128)
		write(fd, &c, 1);
	else if (c < 2048)
	{
		buff[1] = (c & 63) + 128;
		buff[0] = (c >> 6 & 63) + 192;
		write(fd, buff, 2);
	}
	else if (c < 65535)
	{
		buff[2] = (c & 63) + 128;
		buff[1] = (c >> 6 & 63) + 128;
		buff[0] = (c >> 12 & 15) + 224;
		write(fd, buff, 3);
	}
	else if (c >= 65535)
	{
		buff[3] = (c & 63) + 128;
		buff[2] = (c >> 6 & 63) + 128;
		buff[1] = (c >> 12 & 63) + 128;
		buff[1] = (c >> 18 & 7) + 240;
		write(fd, buff, 4);
	}
}
