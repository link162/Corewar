# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 14:55:38 by ybuhai            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2019/03/29 15:41:32 by akorobov         ###   ########.fr        #
=======
#    Updated: 2019/03/29 17:14:16 by ybuhai           ###   ########.fr        #
>>>>>>> e8f838fdd7efcc5831d8e43a2d55fabbc7dbaa2f
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

LIB			=	libftprintf/
LIB_N		=	libftprintf.a

SRC_D		=	src/
SRC			=	$(SRC_D)main.c \
				$(SRC_D)read_flags.c \
				$(SRC_D)error_case.c \
				$(SRC_D)function_for_help.c \
				$(SRC_D)set_players.c \
				$(SRC_D)init_game.c \
				$(SRC_D)validate_heroes.c \
				$(SRC_D)print_function.c \
				$(SRC_D)full_game.c \
				$(SRC_D)read_command.c \
				$(SRC_D)vs_init.c \
				$(SRC_D)vs_dinit_win.c \
				$(SRC_D)vs_control_arena.c \
<<<<<<< HEAD
				$(SRC_D)vs_init_status_bar.c \
=======
				$(SRC_D)operation0.c \
				$(SRC_D)operation5.c \
				$(SRC_D)operation10.c \
>>>>>>> e8f838fdd7efcc5831d8e43a2d55fabbc7dbaa2f

OBJ_D		=	obj/
OBJ			=	$(addprefix $(OBJ_D), $(SRC:.c=.o))

INCLUDE		=	-I includes/
CFLAGS		=	-g3 -O0
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
