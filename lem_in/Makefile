# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 18:29:33 by akondaur          #+#    #+#              #
#    Updated: 2018/12/14 01:42:28 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

# srcs, path and obj

SRC_N			=	get_next_line.c \
					lem_in.c \
					li_bool_free.c \
					li_checkers.c \
					li_creators.c \
					li_paths1.c \
					li_paths2.c \
					li_paths3.c \
					li_prints.c \
					li_stuff.c 

SRC_P 			= ./src/
OBJ 			= $(addprefix $(OBJ_P),$(SRC_N:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ./includes/
HEADER			= $(addprefix $(INC_P), lem_in.h)

# libft

LIB_P			= ./libft/
VIS_P			= ./visual/
ADD_LIB			= $(addprefix $(LIB_P),libft.a)
INC_LIB			= -I ./libft
LNK_LIB			= -L ./libft -l ft

# compiler

CC 				= gcc
CC_FLAGS 		= -Wall -Wextra -Werror

all: obj $(ADD_LIB) $(NAME) $(VIS_P)

obj:
	mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	$(CC) $(CC_FLAGS) $(INC_LIB) -I $(INC_P) -o $@ -c $<

$(ADD_LIB):
	make -C $(LIB_P)
	make -C $(VIS_P)

$(VIS_P):
	make -C $(VIS_P)

$(NAME): $(OBJ)
	$(CC) $(LNK_LIB) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_P)
	make -C $(LIB_P) clean
	make -C $(VIS_P) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_P) fclean
	make -C $(VIS_P) fclean

re: fclean all

.PHONY: all clean fclean re
