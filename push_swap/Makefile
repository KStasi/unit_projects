# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akondaur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 02:52:30 by akondaur          #+#    #+#              #
#    Updated: 2018/11/22 19:25:25 by akondaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME_CH		=	checker
NAME_PS		=	push_swap
FLAGS		=	-Wextra -Wall -Werror
SRCS_CH		=	c_exec.c c_init.c c_ops.c c_opscheck.c checker.c
SRCS_PS		=	ps_checks.c ps_fifthalg1.c ps_fifthalg2.c ps_firstalg.c \
				ps_forthalg.c ps_getinfo1.c ps_getinfo2.c ps_getset.c \
				ps_ops1.c ps_ops2.c ps_optimize.c ps_secondalg.c \
				ps_sixthalg1.c ps_sixthalg2.c ps_sixthalg3.c ps_sixthalg4.c \
				ps_sixthalg5.c ps_sixthalg6.c ps_sixthalg7.c ps_sixthalg8.c \
				ps_stackmanager.c ps_thirdalg.c ps_visual.c push_swap.c

CH_DIR		=	../ch/
PS_DIR		=	../ps/
INCS_DIR	=	./includes/

LIBFT		=	./libft/
LIBFT_A		=	libft.a
OBJS_DIR	=	./objects/

CH_SRCS		=	$(addprefix $(CH_DIR), $(SRCS_CH))
PS_SRCS		=	$(addprefix $(PS_DIR), $(SRCS_PS))
OBJS_CH		=	$(addprefix $(OBJS_DIR), $(SRCS_CH:.c=.o))
OBJS_PS		=	$(addprefix $(OBJS_DIR), $(SRCS_PS:.c=.o))

all				:	objects $(OBJS_CH) $(OBJS_PS) $(LIBFT_A) $(NAME_CH) $(NAME_PS)

$(NAME_CH)		:
	$(CC) $(FLAGS) $(OBJS_CH) -I$(INCS_DIR) -I$(LIBFT) -o $(NAME_CH) -L$(LIBFT) -lft

$(NAME_PS)		: 
	$(CC) $(FLAGS) $(OBJS_PS) -I$(INCS_DIR) -I$(LIBFT) -o $(NAME_PS) -L$(LIBFT) -lft

$(LIBFT_A)		:
	cd $(LIBFT) && $(MAKE)

objects			:
	@mkdir -p $(OBJS_DIR)

$(OBJS_CH)		:
	cd $(OBJS_DIR) && $(CC) -c $(FLAGS) $(CH_SRCS) -I../$(INCS_DIR) -I../$(LIBFT)

$(OBJS_PS)		:
	cd $(OBJS_DIR) && $(CC) -c $(FLAGS) $(PS_SRCS) -I../$(INCS_DIR) -I../$(LIBFT)

clean			:
	/bin/rm -rf $(OBJS_DIR)
	cd $(LIBFT) && $(MAKE) clean
 
fclean			:	clean
	cd $(LIBFT) && $(MAKE) fclean
	/bin/rm -rf $(NAME_CH)
	/bin/rm -rf $(NAME_PS)

re				:	fclean all

.PHONY			:	all clean fclean re
