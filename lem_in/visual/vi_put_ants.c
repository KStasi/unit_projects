/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_put_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:30:22 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:31:28 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_put_ant1(SDL_Surface **surf, SDL_Rect *rect, SDL_Renderer *ren)
{
	SDL_Texture *message;

	message = SDL_CreateTextureFromSurface(ren, *surf);
	SDL_RenderCopy(ren, message, NULL, rect);
	SDL_DestroyTexture(message);
	SDL_FreeSurface(*surf);
}

void	ft_put_ant2(SDL_Rect *rect, t_room *room, int *coefs)
{
	rect->y = (room->y * coefs[1] + rect->h) ? room->y * coefs[1] + rect->h :
	room->y * 2;
	rect->w = (coefs[0] * 0.7) ? coefs[0] * 0.7 : 2;
	rect->h = (coefs[1] * 0.1) ? coefs[1] * 0.1 : 1;
}

void	ft_put_ant(SDL_Surface **surf, SDL_Rect *rect, SDL_Renderer *ren)
{
	SDL_Texture *message;

	message = SDL_CreateTextureFromSurface(ren, *surf);
	SDL_RenderCopy(ren, message, NULL, rect);
	SDL_DestroyTexture(message);
	SDL_FreeSurface(*surf);
}
