/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_put_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:31:58 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:32:51 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_put_name2(SDL_Surface **surf, SDL_Rect *rect, int *coefs,
		SDL_Renderer *ren)
{
	SDL_Texture *message;

	message = SDL_CreateTextureFromSurface(ren, *surf);
	rect->w = (coefs[0] * 0.4) ? coefs[0] * 0.4 : 1;
	rect->h = (coefs[1] * 0.4) ? coefs[1] * 0.4 : 1;
	SDL_RenderCopy(ren, message, NULL, rect);
	SDL_DestroyTexture(message);
	SDL_FreeSurface(*surf);
}

void	ft_put_name1(SDL_Rect *rect, t_room *room, SDL_Renderer *ren,
		int *coefs)
{
	rect->w = (coefs[0] * 0.8) ? coefs[0] * 0.8 : 2;
	rect->h = (coefs[1] * 0.8) ? coefs[1] * 0.8 : 2;
	rect->x = (room->x * coefs[0]) ? room->x * coefs[0] : room->x * 2;
	rect->y = (room->y * coefs[1]) ? room->y * coefs[1] : room->y * 2;
	if (room->d != -1)
		SDL_RenderFillRect(ren, rect);
	else
		SDL_RenderDrawRect(ren, rect);
}

void	ft_put_name(TTF_Font **sans, t_room *room, SDL_Color col,
		SDL_Surface **surf)
{
	char *name;

	*sans = TTF_OpenFont("./FreeSans.ttf", 255);
	name = ft_itoa(room->d);
	if (room->d != -1)
		*surf = TTF_RenderText_Solid(*sans, name, col);
	else
		*surf = TTF_RenderText_Solid(*sans, " ", col);
	free(name);
}
