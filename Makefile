# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 06:00:52 by elakhfif          #+#    #+#              #
#    Updated: 2023/05/22 06:21:08 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc -Wall -Wextra -Werror -g -O3

NAME	= fractol
SRC	= mandatory/control.c\
	  mandatory/draw.c\
	  mandatory/main.c\
	  mandatory/utils.c\

NAME_BONUS	= fractol_bonus
BONUS_SRC	= bonus/control.c\
		  bonus/draw.c\
		  bonus/main.c\
		  bonus/utils.c\


OBJ  = $(SRC:.c=.o)

BONUS_OBJ  = $(BONUS_SRC:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS) : $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

%.o : %.c fractol.h
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all
