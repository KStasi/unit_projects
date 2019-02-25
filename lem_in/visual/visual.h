/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:37:40 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/05 19:37:44 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/syscall.h>
# include <fcntl.h>
# include <sys/param.h>
# include "./frameworks/SDL2.framework/Headers/SDL.h"
# include "./frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					list_size;
	int					status;
	int					d;
	struct s_room		*next;
	struct s_room		**list;
}						t_room;

typedef struct			s_path
{
	int					path_size;
	t_room				**rooms;
}						t_path;

typedef struct			s_graph
{
	int					n_nodes;
	int					n_ants;
	int					n_pathes;
	t_room				*all_rooms;
	t_path				**pathes;

}						t_graph;

typedef struct			s_lines
{
	char				*line;
	struct s_lines		*next;
}						t_lines;

int						*ft_find_max(t_graph *graph);
int						ft_error_generate(void);
int						ft_read_tubes(t_graph *graph, char **line,
						t_lines *lines);
int						ft_create_node(char *line, t_graph *graph, int status);
int						ft_create_graph(t_graph *graph, t_lines *lines);
int						ft_get_status(char *line);
int						ft_set_attrs(int **atrs, int status);
int						ft_check_range(char *s);
int						ft_check_arr(char **arr);
int						ft_check_format(t_graph *graph, char *line);
int						ft_check_atrs(int **atrs);
int						ft_is_num(char *str);
int						ft_is_comment(char *line, int del);
void					ft_free_line(char **line, t_lines **lines);
void					ft_free_arr(char **arr);
void					ft_free_stuff(SDL_Renderer *ren, TTF_Font **sans);
void					ft_free_all_rooms(t_graph *graph);
void					ft_set_lines(char **line, t_lines **lines);
void					ft_set_col(SDL_Color *col, int d);
void					ft_get_n_ants(char *line, t_graph *graph, int *status);
void					ft_add_tube(t_room *a, t_room *b, int size);
void					ft_create_tube(t_graph *graph, char *line, int *tubes);
void					ft_create_room(t_room **last, char **arr, int status);
void					ft_read_lems(char **line, t_lines *lines);
void					ft_put_name(TTF_Font **sans, t_room *room,
						SDL_Color col, SDL_Surface **surf);
void					ft_put_name1(SDL_Rect *rect, t_room *room,
						SDL_Renderer *ren, int *coefs);
void					ft_put_name2(SDL_Surface **surf, SDL_Rect *rect,
						int *coefs, SDL_Renderer *ren);
void					ft_put_ant(SDL_Surface **surf, SDL_Rect *rect,
						SDL_Renderer *ren);
void					ft_put_ant1(SDL_Surface **surf, SDL_Rect *rect,
						SDL_Renderer *ren);
void					ft_put_them(t_graph *graph, SDL_Renderer *ren);
void					ft_put_ant2(SDL_Rect *rect, t_room *room, int *coefs);
void					ft_draw_room(SDL_Renderer *ren, t_room *room, int *cof);
void					ft_draw_step(SDL_Renderer *ren, t_room *room, int *cof);
void					ft_draw_steps(t_graph *graph, t_lines *lines,
						SDL_Renderer *ren);
void					ft_redraw(t_graph *graph, char *line, SDL_Renderer *rn);
void					ft_posses(t_graph *graph, char *line, char *name);
void					draw1(t_graph *graph, SDL_Renderer *ren);
void					draw(t_graph *graph, t_lines *lines);
#endif
