/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:50:40 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 06:55:30 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_LEM_IN_H
# define LI_LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/syscall.h>
# include <fcntl.h>
# include <sys/param.h>
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
	int					move;
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

int						ft_poses_ants(t_graph *graph, int ants);
void					ft_push_ants(t_graph *graph);
void					ft_realloc_path(t_graph *graph);
void					ft_add_tube(t_room *a, t_room *b, int size);
void					ft_free_paths(t_room *rooms, t_graph *graph);
void					ft_free_line(char **line, t_lines **lines);
void					ft_free_arr(char **arr);
void					ft_print_ants(t_graph *graph);
void					ft_print_result(t_graph *graph);
void					ft_print_input(t_lines *lines);
void					ft_print_if_dirrect(t_graph *graph, t_lines *lines);
void					ft_hide_path(t_graph *graph, t_path *path);
void					ft_reset_path(int d, t_path *path, t_room *end);
void					ft_create_paths(t_graph *graph, t_lines *lines);
void					ft_create_room(t_room **last, char **arr, int status);
void					ft_create_tube(t_graph *graph, char *line, int *n_tubes,
		t_lines *lines);
int						ft_create_node(char *line, t_graph *graph, int status,
		t_lines *lines);
int						ft_create_graph(t_graph *graph, t_lines *lines);
int						ft_is_dirrect(t_room *start, t_room *end);
int						ft_is_empty(t_graph *graph);
int						ft_is_num(char *str);
int						ft_is_comment(char *line, int del, t_lines *lines);
int						ft_is_approp(t_graph *graph, char **line,
		t_lines *lines, int d);
int						ft_wave(t_room *all, int d, int size);
int						ft_check_range(char *s);
int						ft_check_arr(char **arr);
int						ft_check_format(t_graph *graph, char *line);
int						ft_check_atrs(int **atrs);
int						ft_check_nodes(t_graph graph);
int						ft_error_generate(int err);
int						ft_set_attrs(int **atrs, int status);
int						ft_read_tubes(t_graph *graph, char **line,
		t_lines *lines);
int						ft_get_status(char *line);
t_room					*ft_get_start(t_room *all_rooms);
t_room					*ft_get_end(t_room *all_rooms);
t_path					*ft_getpath(t_room *start, t_room *end, t_graph *graph);
#endif
