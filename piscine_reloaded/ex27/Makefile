# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 20:11:51 by akondaur          #+#    #+#              #
#    Updated: 2018/10/22 20:12:10 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = srcs/ft_display_file.c

all: $(NAME)

$(NAME): 
	gcc -Wall -Wextra -Werror -Iinclds -o $(NAME)  $(SRC)

clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

re: fclean all
