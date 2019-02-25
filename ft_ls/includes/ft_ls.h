/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:51:23 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/23 13:13:57 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/xattr.h>
# include <time.h>

typedef struct		s_info
{
	char			*name;
	char			type;
	char			*right;
	char			*usr;
	char			*group;
	char			*size;
	char			*time;
	char			*link;
	nlink_t			st_nlink;
	time_t			tm;
	long			blksize;
	struct stat		*lstat;
}					t_info;

typedef struct		s_file
{
	char			*name;
	char			npr;
	int				count;
	int				width[6];
	struct s_file	*next;
}					t_file;

typedef struct		s_manager
{
	short int		flags[12];
	int				list_size;
	t_file			*files;
	t_info			**file_list;
	t_file			*dir_list;
	t_file			*list_end;
	t_file			*curr_dir;
}					t_manager;

void				ft_push_result(t_manager *data);
void				ft_finalize_singledata(t_manager *data);
void				ft_finalize_dir(t_manager *data);
void				ft_carry_line(int *n, int col, struct winsize w);
void				ft_info_copy(t_info **arr1, t_info **arr2);
void				ft_swap_info(t_info **arr1, t_info **arr2);
void				ft_add_end(t_manager **data, char *name, char *d_name);
void				ft_add_file(char *name, t_manager *data, int *j,
					char *path);
void				ft_add_dir(char *name, t_manager *data);
void				ft_add_last_dir(t_manager *data, char *name);
void				ft_create_file_list(int i, int ac, char **av,
					t_manager *data);
void				ft_print_arr_long(int place, const short *flags,
					t_info **arr, t_file *file);
void				ft_print_files(t_manager *data);
void				ft_print_result(t_manager *data);
void				ft_print_dir_name(int place, t_file *file);
void				ft_print_with_break(int *n, int col, char *name,
					struct winsize w);
void				ft_print_without_break(int *n, int col, char *name,
					struct winsize w);
void				ft_print_arr_col(int place, int col, t_info **arr,
					t_file *file);
void				ft_print_head(int place, const short *flags, t_file *file,
					int *i);
void				ft_free_arr(t_info ***arr);
void				ft_free_lstat(struct stat **ls);
void				ft_free_line(char **p);
void				ft_free_files(t_file *file);
void				ft_free_info(t_info *info);
void				ft_free_file_list(t_info **list, int size);
void				*ft_free_data(t_manager **data);
void				ft_init_singledata(t_manager *data);
void				ft_init_data(t_manager *data, int ac);
void				ft_init_arr(t_info ***arr, int *i, t_file *file);
void				ft_sort_alphabet(t_info **arr, int l, int r, int mod);
void				ft_sort_time_t(t_info **arr, int l, int r, int mod);
void				ft_sort_arr(t_file *file, t_manager **data, t_info **arr);
void				ft_set_flags(char flag, t_manager	**data);
void				ft_set_all_stuff(t_file *file, struct stat *stat);
void				ft_set_npr(t_manager *data, int j);
void				ft_set_curr_dir(t_manager **data, char *name);
void				ft_set_col(int *col, char *name);
void				ft_set_extra_stuff(t_info *file, short int *flags,
					char *name);
int					ft_set_w(struct winsize *w, int col, int *n, t_file *file);
int					ft_add_new_file(t_info **new, t_file *file, char *d_name,
					int *i);
int					ft_error_generate(int err, char *str);
int					ft_parse_flags(int ac, char **av, t_manager	**data);
int					ft_opendir(DIR **dir, char *name, int *col);
int					ft_count_files(char *name, t_manager **data, int *count);
int					partition_a(t_info **arr, int l, int r, int mod);
int					partition_t(t_info **arr, int l, int r, int mod);
int					ft_check_time1(t_info *el, t_info *cur, int mod);
int					ft_check_time2(t_info *el, t_info *cur, int mod);
int					ft_check_time3(t_info *el, t_info *cur, int mod);
int					ft_check_time4(t_info *el, t_info *cur, int mod);
int					ft_check_flag(char c);
int					ft_check_a(char *name, short int *flags);
int					ft_check_aa(char *name, short int *flags);
int					ft_check_correct(char **av, int ac);
int					ft_check_dir(t_manager **data, char *name);
char				*ft_check_link(t_info *file, char *name);
char				*ft_rght(mode_t m);
char				*ft_get_link(char *path, char *name);
char				*ft_get_size(t_info *file);
char				*ft_get_time(t_info *file, short int *flags);
char				*ft_get_group(t_info *file, short int *flags);
char				*ft_get_usr(t_info *file, short int *flags);
t_manager			*ft_get_names(int ac, char **av);
t_manager			*ft_create_singledata(t_manager	*data);
t_info				**ft_create_arr(t_file *file, t_manager **data);
t_file				*ft_create_file(char *file);
t_file				*ft_find_last(t_manager **data);
t_file				*ft_posses_dir(t_manager **data, char *name, char *file);
long				ft_set_blksize(t_info *file, short int *flags);
char				ft_tp(mode_t m);
#endif
