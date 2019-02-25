# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 14:06:00 by akondaur          #+#    #+#              #
#    Updated: 2018/11/11 16:36:56 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = ft_printf.c		ft_strllen.c \
ft_putchar.c		ft_tolower.c \
checkers.c		ft_putchar_utf8.c	ft_toupper.c \
ft_atoi.c		ft_putcstr.c		getters.c \
ft_bzero.c		ft_putnbr.c		int.c \
ft_isdigit.c		ft_putstr.c		intspec.c \
ft_isprint.c		ft_putunbr.c \
ft_itoa_base.c		ft_strchr.c		otherypes.c \
ft_memcpy.c		ft_strclr.c		str.c \
ft_memset.c		ft_strdup.c		stuff.c \
ft_nlen.c		ft_strlen.c		uint.c
OBJECTS = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(FILES)
	ar rc $@ $(OBJECTS)
	ranlib $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
