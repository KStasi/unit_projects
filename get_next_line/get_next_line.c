/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:30:15 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/26 10:30:20 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		buff_reduce(char *line, t_buff **p)
{
	char	*i;
	int		l;

	ft_bzero(line, BUFF_SIZE);
	if (ft_memchr((*p)->buff, '\n', BUFF_SIZE))
		(*p)->print = 1;
	i = ft_memccpy(line, (*p)->buff, '\n', BUFF_SIZE);
	if (i)
	{
		ft_memmove((*p)->buff, i, BUFF_SIZE + (int)((*p)->buff - i));
		ft_bzero((*p)->buff + BUFF_SIZE + (int)((*p)->buff - i),
			(int)(i - (*p)->buff));
		l = 1;
		line[ft_strlen(line) - 1] = '\0';
	}
	else
	{
		ft_bzero((*p)->buff, BUFF_SIZE);
		l = 0;
	}
	return (l);
}

void	rebuilt_buff(char **line, const int fd, t_buff *buffs, t_buff **p)
{
	if (!p || !(*p))
	{
		*p = buffs;
		while ((*p)->next)
			*p = (*p)->next;
		if (!((*p)->next = (t_buff *)malloc(sizeof(t_buff))))
			return ;
		(*p)->next->fd = fd;
		(*p)->next->next = NULL;
		(*p)->next->print = 0;
		(*p) = (*p)->next;
	}
	else
	{
		(*p)->print = 0;
		buff_reduce(*line, p);
	}
}

void	ft_check(char **line, const int fd, t_buff *buffs, t_buff **p)
{
	if (line && *line)
		*line = NULL;
	*p = buffs;
	while (*p)
	{
		if ((*p)->fd == fd)
			break ;
		*p = (*p)->next;
	}
	if (!(*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return ;
	ft_bzero(*line, BUFF_SIZE + 1);
	rebuilt_buff(line, fd, buffs, p);
}

char	*ft_realloc(char **line, int size, int new_size)
{
	char	*new;
	int		i;

	if (new_size <= 0 && *line)
	{
		free(*line);
		return (0);
	}
	if (!(new = (char *)malloc(sizeof(char) * new_size)))
		return (NULL);
	ft_bzero(new, new_size);
	i = -1;
	while (++i < size)
		new[i] = (*line)[i];
	free(*line);
	*line = new;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	int					ret;
	unsigned int		size;
	t_buff				*p;
	static t_buff		buffs;

	if (fd < 0 || !line)
		return (-1);
	ft_check(line, fd, &buffs, &p);
	size = ft_strlen(*line) < BUFF_SIZE ? ft_strlen(*line) : BUFF_SIZE;
	while (!p->print && (ret = read(fd, p->buff, BUFF_SIZE)) > 0)
	{
		ft_bzero(p->buff + ret, BUFF_SIZE - ret);
		ft_realloc(line, size, size + BUFF_SIZE + 1);
		if (buff_reduce(*line + size, &p))
			return (1);
		size += BUFF_SIZE;
	}
	if (ret < 0 && !ft_realloc(line, size, 0))
		return (-1);
	if (!p->print && !ret && ft_strlen(p->buff) <= 0 && (ft_strlen(*line)) <= 0)
		return (0);
	return (1);
}
