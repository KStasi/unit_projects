# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 17:31:20 by akondaur          #+#    #+#              #
#    Updated: 2018/12/05 17:31:39 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual

# srcs, path and obj

SRC_N			= visual.c get_next_line.c vi_checks.c vi_draw.c vi_free.c \
                  vi_get_set.c vi_miscellaneous.c vi_put_ants.c vi_put_name.c \
                  vi_rooms_tubes.c vi_staff_data.c

SRC_P 			= ./
OBJ 			= $(addprefix $(OBJ_P),$(SRC_N:.c=.o))
OBJ_P			= ./obj/
INC 			= $(addprefix -I, $(INC_P))
INC_P			= ../includes/
HEADER			= $(addprefix $(INC_P), lem_in.h)

# libft

LIB_P			= ../libft/
ADD_LIB			= $(addprefix $(LIB_P),libft.a)
INC_LIB			= -I ../libft
LNK_LIB			= -L ../libft -l ft

# compiler

CC 				= gcc
CC_FLAGS 		= -g -Wall -Wextra -Werror
CC_FRAM			= -F frameworks -framework SDL2 -framework SDL2_ttf

# framework

SDL				=  -I ./frameworks/SDL2.framework/Headers/
SDL_TTF			=  -I ./frameworks/SDL2_ttf.framework/Headers/
INCLUDES_SDL	= $(SDL) $(SDL_TTF)

all: obj $(ADD_LIB) $(NAME)

obj:
	mkdir -p $(OBJ_P)

$(OBJ_P)%.o:$(SRC_P)%.c $(HEADER)
	$(CC) $(CC_FLAGS) $(INC_LIB) $(INCLUDES_SDL) -I $(INC_P) -o $@ -c $<

$(ADD_LIB):
	make -C $(LIB_P)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(CC_FRAM) $(LNK_LIB) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_P)
	make -C $(LIB_P) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_P) fclean

re: fclean all

.PHONY: all clean fclean re
