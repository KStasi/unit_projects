# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 20:05:21 by akondaur          #+#    #+#              #
#    Updated: 2018/10/22 20:06:14 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = $(S)ft_putchar.c $(S)ft_putstr.c $(S)ft_strcmp.c $(S)ft_strlen.c $(S)ft_swap.c
OBJECTS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
S = ./srcs/
IN = includes
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) -IIN $(FILES)
	ar rc $@ $(OBJECTS)
	ranlib $@  

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
