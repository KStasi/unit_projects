/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:12:35 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:25:20 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_draw_room(SDL_Renderer *ren, t_room *room, int *coefs)
{
	SDL_Rect	rect;
	SDL_Surface	*surf;
	TTF_Font	*sans;
	SDL_Texture	*message;
	SDL_Color	col;

	TTF_Init();
	ft_set_col(&col, 0);
	sans = TTF_OpenFont("./FreeSans.ttf", 30);
	surf = TTF_RenderText_Solid(sans, room->name, col);
	message = SDL_CreateTextureFromSurface(ren, surf);
	rect.w = (coefs[0] * 0.8) ? coefs[0] * 0.8 : 2;
	rect.h = (coefs[1] * 0.8) ? coefs[1] * 0.8 : 2;
	rect.x = (room->x * coefs[0]) ? room->x * coefs[0] : room->x * 2;
	rect.y = (room->y * coefs[1]) ? room->y * coefs[1] : room->y * 2;
	SDL_RenderFillRect(ren, &rect);
	SDL_RenderCopy(ren, message, NULL, &rect);
	SDL_SetRenderDrawColor(ren, 255, 183, 1, 255);
	SDL_DestroyTexture(message);
	SDL_FreeSurface(surf);
	TTF_CloseFont(sans);
	TTF_Quit();
}

void	ft_draw_step(SDL_Renderer *ren, t_room *room, int *coefs)
{
	SDL_Rect	rect;
	SDL_Surface	*surf;
	TTF_Font	*sans;
	SDL_Color	col;

	TTF_Init();
	ft_set_col(&col, room->d);
	ft_put_name(&sans, room, col, &surf);
	ft_put_name1(&rect, room, ren, coefs);
	ft_put_name2(&surf, &rect, coefs, ren);
	surf = TTF_RenderText_Blended(sans, "/\\/\\        ", col);
	ft_put_ant2(&rect, room, coefs);
	ft_put_ant(&surf, &rect, ren);
	surf = TTF_RenderText_Blended(sans, "  \\_\\  _..._", col);
	rect.y = (rect.y + rect.h) ? rect.y + rect.h : room->y * 2;
	ft_put_ant1(&surf, &rect, ren);
	surf = TTF_RenderText_Blended(sans, "  (\" )(_..._)", col);
	rect.y = (rect.y + rect.h) ? rect.y + rect.h : room->y * 2;
	ft_put_ant1(&surf, &rect, ren);
	surf = TTF_RenderText_Blended(sans, "   ^^  // \\\\", col);
	rect.y = (rect.y + rect.h) ? rect.y + rect.h : room->y * 2;
	ft_put_ant1(&surf, &rect, ren);
	ft_free_stuff(ren, &sans);
	TTF_Quit();
}

void	ft_draw_steps(t_graph *graph, t_lines *lines, SDL_Renderer *ren)
{
	t_lines *l;

	l = lines;
	while (l)
	{
		ft_redraw(graph, l->line, ren);
		l = l->next;
	}
}

void	draw1(t_graph *graph, SDL_Renderer *ren)
{
	t_room		*room;
	int			i;
	int			*coefs;

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
		ft_draw_room(ren, room, coefs);
		room = room->next;
	}
	SDL_RenderPresent(ren);
	SDL_Delay(3000);
	free(coefs);
}

void	draw(t_graph *graph, t_lines *lines)
{
	SDL_Surface		*screen;
	SDL_Window		*win;
	SDL_Renderer	*ren;

	SDL_Init(SDL_INIT_NOPARACHUTE);
	win = SDL_CreateWindow("Lem-in", 0, 0, 1100, 1100, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	screen = SDL_CreateRGBSurface(0, 1100, 1100, 32, 0, 7, 18, 255);
	SDL_SetRenderDrawColor(ren, 0, 7, 18, 255);
	SDL_RenderClear(ren);
	draw1(graph, ren);
	ft_draw_steps(graph, lines, ren);
	SDL_FreeSurface(screen);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
