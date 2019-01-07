/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 08:45:19 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/26 08:45:22 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# define BUFF_SIZE 32

typedef struct		s_buff
{
	int				fd;
	short			print;
	char			buff[BUFF_SIZE];
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
