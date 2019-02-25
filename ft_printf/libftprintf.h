/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 08:48:28 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/02 09:05:06 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stddef.h>
# include <locale.h>
# include <limits.h>

int						g_printed;

typedef struct			s_elem
{
	char				flags[10];
	int					width;
	int					precision;
	int					length;
	int					type;
}						t_elem;

typedef union			u_data
{
	char				c;
	wchar_t				wc;
	wchar_t				*ws;
	char				*s;
	signed long long	lli;
	unsigned long long	llu;
	intmax_t			ji;
	uintmax_t			ju;
}						t_data;

int						ft_printf(const char *format, ...);
int						ft_is_flag(char c);
int						ft_is_length(char c);
int						ft_is_type(char c);
void					ft_init(t_elem **el);
void					ft_getflags(char **s, t_elem **el);
void					ft_getwidth(char **s, t_elem **el, va_list *args);
void					ft_getprecision(char **s, t_elem **el, va_list *args);
void					ft_getlength(char **s, t_elem **el);
void					ft_gettype(char **s, t_elem *el);
int						ft_shorten_w(t_elem *el, t_data *data, int n, int *w);
void					ft_lengthen_r(t_elem *el, t_data *data, int n);
void					ft_lengthen_l(t_elem *el, t_data *data, int n);
void					ft_prepare_int(t_elem *el, t_data *data);
void					ft_get_type_int(t_elem *el, va_list *args);
long long				ft_unlen(unsigned long long n);
long long				ft_unlen(unsigned long long n);
void					ft_lengthen_ru(t_elem *el, t_data *data, int n);
void					ft_lengthen_lu(t_elem *el, t_data *data, int n);
void					ft_prepare_uint(t_elem *el, t_data *data);
char					*ft_zero_line(void);
int						ft_fix_zero(t_elem *el);
int						ft_prepare_int_spec2(t_elem *el, t_data *data, int n,
	int size);
void					ft_prepare_int_spec(t_elem *el, t_data *data);
void					ft_get_type_int_spec(t_elem *el, va_list *args);
void					ft_prepare_chr(t_elem *el, t_data *data);
void					ft_get_type_chr(t_elem *el, va_list *args);
void					ft_get_sign(t_elem *el);
void					ft_get_undef_type(t_elem *el);
void					ft_get_type_ptr(t_elem *el, va_list *args);
void					ft_correct_bywchar(t_elem *el, t_data *data);
void					ft_print_str(t_elem *el, t_data *data);
void					ft_get_type_str(t_elem *el, va_list *args);
void					ft_correct_prec(t_elem *el, t_data *data);
void					ft_prepare_flags_int(t_elem *el, t_data *data);
long long				ft_mod(signed long long a);
void					ft_fix_old_style(t_elem *el);
void					ft_try_print(t_elem *el, va_list *args);
void					ft_getcomnd(const char *format, t_elem *el,
	va_list *args);

char					*ft_itoa_base(long long value, int base);
void					ft_putunbr(unsigned long long n);
long long				ft_nlen(long long n);
char					*ft_putcstr(char *str, char c);
char					*ft_strchr(const char *s1, int c);
void					ft_putchar(int c);
void					ft_putchar_utf8(int c);
int						ft_putstr(const char *str);
int						ft_putstr_utf8(const wchar_t *str);
void					ft_putnbr(signed long long n);
int						ft_atoi(const char *s);
size_t					ft_strlen(const char *str);
size_t					ft_strllen(const wchar_t *str);
void					ft_bzero(void *b, size_t length);
void					ft_strclr(char *s);
int						ft_isdigit(int c);
void					*ft_memset(void *dest, int c, size_t n);
void					*ft_memcpy(void *dest, const void *source,
	size_t count);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_isprint(int c);
char					*ft_strdup(const char *src);
#endif
