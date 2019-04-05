# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 14:55:38 by ybuhai            #+#    #+#              #
#    Updated: 2019/04/05 07:27:05 by akorobov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

LIB			=	libftprintf/
LIB_N		=	libftprintf.a

SRC_D		=	src/
SRC			=	$(SRC_D)main.c \
				$(SRC_D)read_flags.c \
				$(SRC_D)function_for_help.c \
				$(SRC_D)set_players.c \
				$(SRC_D)init_game.c \
				$(SRC_D)validate_heroes.c \
				$(SRC_D)print_function.c \
				$(SRC_D)full_game.c \
				$(SRC_D)read_argtype.c \
				$(SRC_D)check_who_die.c \
				$(SRC_D)vs_init.c \
				$(SRC_D)vs_dinit_win.c \
				$(SRC_D)vs_control_arena.c \
				$(SRC_D)vs_key.c \
				$(SRC_D)vs_up_statusbar.c \
				$(SRC_D)vs_init_status_bar.c \
				$(SRC_D)ftoa.c \
				$(SRC_D)operation0.c \
				$(SRC_D)operation5.c \
				$(SRC_D)operation10.c \
				$(SRC_D)operation16.c \

OBJ_D		=	obj/
OBJ			=	$(addprefix $(OBJ_D), $(SRC:.c=.o))

INCLUDE		=	-I includes/
CFLAGS		=	-Wall -Wextra -Werror -Ofast
LIBNC		=	-lncurses
C			=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@$(C) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)$(LIB_N) $(INCLUDE) $(LIBNC)

$(OBJ): $(OBJ_D)

$(OBJ_D):
	@mkdir -p $(OBJ_D)$(SRC_D)

$(OBJ_D)%.o: %.c
	@$(C) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)
	@rm -rf $(OBJ_D)

re: fclean all

.PHONY: all clean fclean re
