# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 12:38:29 by daparici          #+#    #+#              #
#    Updated: 2026/10/19 22:30:38 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = So_long
CC = gcc 
CFLAGS = -Wall -Werror -Wextra -I. -I./Libft -I./GetNextLine -I./printf -I/usr/include -Imlx_linux -O3 -g #-g -fsanitize=address -g3

SRCS = main.c check_map_1.c check_map_2.c game.c Exit.c move_goku_ki.c move_goku.c key_select.c \
	 move_goku_2.c map.c key_select_2.c  enemies.c \
enemies_init.c \
enemies_move.c \
enemies_step.c \
enemy_bfs.c \
enemy_plan.c \
enemy_utils.c \
enemy_decide.c \
enemy_wander.c

GNL = get_next_line.c get_next_line_utils.c
GNLPATH = $(addprefix ./GetNextLine/,$(GNL))
LIBFT = ./Libft/libft.a
PRINTF_LIB = ./printf/libftprintf.a

OBJS = ${SRCS:.c=.o}
GNLOBJ = $(GNLPATH:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Wall -Wextra  -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) $(GNLOBJ) libraries
	$(CC) $(CFLAGS) $(OBJS) $(GNLOBJ) $(LIBFT) $(PRINTF_LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

libraries:
	$(MAKE) -C ./Libft bonus
	$(MAKE) -C ./printf

all: $(NAME)

clean:
	$(RM) $(OBJS) $(GNLOBJ)
	$(MAKE) -C ./Libft clean
	$(MAKE) -C ./printf clean
fclean: clean
	$(RM) $(NAME) $(LIBFT) $(PRINTF_LIB)
re: fclean all
.PHONY: all libraries clean fclean re
