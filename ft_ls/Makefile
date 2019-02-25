# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 18:29:33 by akondaur          #+#    #+#              #
#    Updated: 2018/12/03 18:29:37 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

# srcs, path and obj

SRC_N			=	ft_ls.c \
                    ft_printers1.c \
                    ft_printers2.c \
                    get_next_line.c \
                    ls_addrs.c \
                    ls_cheacks1.c \
                    ls_cheacks2.c \
                    ls_creators.c \
                    ls_dir_hand.c \
                    ls_file_hand.c \
                    ls_free1.c \
                    ls_free2.c \
                    ls_getters1.c \
                    ls_getters2.c \
                    ls_init.c \
                    ls_setters1.c \
                    ls_setters2.c \
                    ls_sort.c \
                    ls_stuff.c

SRC_P 			= ./src/
OBJ 			= $(addprefix $(OBJ_P),$(SRC_N:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ./includes/
HEADER			= $(addprefix $(INC_P), ft_ls.h)

# libft

LIB_P			= ./libft/
ADD_LIB			= $(addprefix $(LIB_P),libft.a)
INC_LIB			= -I ./libft
LNK_LIB			= -L ./libft -l ft

# compiler

CC 				= gcc
CC_FLAGS 		= -Wall -Wextra -Werror

all: obj $(ADD_LIB) $(NAME)

obj:
	mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	$(CC) $(CC_FLAGS) $(INC_LIB) -I $(INC_P) -o $@ -c $<

$(ADD_LIB):
	make -C $(LIB_P)

$(NAME): $(OBJ)
	$(CC) $(LNK_LIB) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_P)
	make -C $(LIB_P) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_P) fclean

re: fclean all

.PHONY: all clean fclean re
