# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 06:00:52 by elakhfif          #+#    #+#              #
#    Updated: 2023/05/23 07:44:13 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc -Wall -Wextra -Werror -g -O3

NAME	= fractol
SRC	= mandatory/control.c\
	  mandatory/draw.c\
	  mandatory/main.c\
	  mandatory/utils.c\

NAME_BONUS	= ultrafractol
BONUS_SRC	= bonus/control.c\
		  bonus/draw.c\
		  bonus/main.c\
		  bonus/utils.c\


OBJ  = $(SRC:.c=.o)

BONUS_OBJ  = $(BONUS_SRC:.c=.o)

all : $(NAME) 

bonus : $(NAME_BONUS)


CLR_RMV:= \033[0m
RED:= \033[1;31m
GREEN:= \033[1;32m
YELLOW:= \033[1;33m
BLUE:= \033[1;34m
CYAN:= \033[1;36m


$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(BLUE)Compilation of ${YELLOW}$(NAME) $(RED)BY 7ARZAN ..."
	@echo "$(GREEN)HAK HAHOWA $(YELLOW)$(NAME) $(GREEN)M9AD  ✔️"

$(NAME_BONUS) : $(BONUS_OBJ)
	@$(CC) $(BONUS_OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "$(BLUE)Compilation of ${YELLOW}$(NAME_BONUS) $(RED)BY 7ARZAN ..."
	@echo "$(GREEN)HAK HAHOWA $(YELLOW)$(NAME_BONUS) $(GREEN)M9AD  ✔️"

%.o : %.c fractol.h
	@$(CC) -c $< -o $@

clean :
	@rm -rf $(OBJ) $(BONUS_OBJ)
	@echo "$(RED)$(NAME) $(GREEN)OBJS DELETED ✔️"
	@echo "$(RED)$(NAME_BONUS) $(GREEN)OBJS DELETED ✔️"

fclean : clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "$(RED)$(NAME) $(GREEN)DELETED ✔️"
	@echo "$(RED)$(NAME_BONUS) $(GREEN)DELETED ✔️"

re : fclean all
