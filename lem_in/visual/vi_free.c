/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:27:12 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:28:11 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		ft_free_line(char **line, t_lines **lines)
{
	t_lines *l;

	if (lines)
	{
		l = *lines;
		while (*lines && l->line && l->next)
			l = l->next;
		if (*lines && (*lines)->line)
		{
			l->next = (t_lines *)malloc(sizeof(t_lines));
			l = l->next;
		}
		l->line = *line;
		l->next = NULL;
	}
	else if (line && *line)
		free(*line);
	*line = NULL;
}

void		ft_free_arr(char **arr)
{
	int i;

	if (!arr || !*arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void		ft_free_stuff(SDL_Renderer *ren, TTF_Font **sans)
{
	SDL_SetRenderDrawColor(ren, 255, 183, 1, 255);
	TTF_CloseFont(*sans);
}

int			ft_is_num(char *str)
{
	int j;

	j = -1;
	while (++j < (int)ft_strlen(str))
		if (!ft_isdigit(str[j]) && !((str[j] == '-'
		|| str[j] == '+') && !j))
			return (0);
	if (!ft_check_range(str))
		return (0);
	return (1);
}

int			ft_is_comment(char *line, int del)
{
	if (line && *line && line[0] == '#')
	{
		ft_free_line(&line, NULL);
		return (1);
	}
	if (del)
		ft_free_line(&line, NULL);
	return (0);
}
