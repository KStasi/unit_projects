/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_miscellaneous.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:29:07 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:29:57 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_free_all_rooms(t_graph *graph)
{
	t_room *room;

	room = graph->all_rooms;
	while (room)
	{
		room->d = -1;
		room = room->next;
	}
}

void	ft_posses(t_graph *graph, char *line, char *name)
{
	t_room *room;

	room = graph->all_rooms;
	while (room)
	{
		if (!ft_strcmp(room->name, name))
			room->d = ft_atoi(line + 1);
		room = room->next;
	}
}

void	ft_put_them(t_graph *graph, SDL_Renderer *ren)
{
	SDL_Surface	*screen;
	t_room		*room;
	int			*coefs;
	int			i;

	screen = SDL_CreateRGBSurface(0, 1100, 1100, 32, 0, 7, 18, 255);
	SDL_SetRenderDrawColor(ren, 0, 7, 18, 255);
	SDL_RenderClear(ren);
	room = graph->all_rooms;
	SDL_SetRenderDrawColor(ren, 255, 183, 1, 255);
	coefs = ft_find_max(graph);
	while (room && (i = -1))
	{
		while (++i < room->list_size)
			SDL_RenderDrawLine(ren, room->x * coefs[0], room->y * coefs[1],
			room->list[i]->x * coefs[0], room->list[i]->y * coefs[1]);
		if (room->status == 1 || room->status == -1)
			SDL_SetRenderDrawColor(ren, 159, 33, 18, 255);
		ft_draw_step(ren, room, coefs);
		room = room->next;
	}
	SDL_RenderPresent(ren);
	SDL_Delay(1000);
	SDL_FreeSurface(screen);
	free(coefs);
}

void	ft_redraw(t_graph *graph, char *line, SDL_Renderer *ren)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(line, ' ');
	i = -1;
	ft_free_all_rooms(graph);
	while (arr[++i])
		ft_posses(graph, arr[i], ft_strchr(arr[i], '-') + 1);
	ft_put_them(graph, ren);
	ft_free_arr(arr);
}
