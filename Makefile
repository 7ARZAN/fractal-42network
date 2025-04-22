# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 06:00:52 by elakhfif          #+#    #+#              #
#    Updated: 2023/05/26 20:44:32 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3 -Ofast
SRC = src/control.c src/draw.c main.c src/utils.c
OBJ = $(SRC:.c=.o)
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CLR_RMV := \033[0m
RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
BLUE := \033[1;34m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo "$(BLUE)Compiled $(YELLOW)$(NAME) $(GREEN)successfully! ✔️$(CLR_RMV)"

%.o: %.c include/fractol.h
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Object files deleted! $(GREEN)✔️$(CLR_RMV)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted! $(GREEN)✔️$(CLR_RMV)"

re: fclean all

.PHONY: all clean fclean re
