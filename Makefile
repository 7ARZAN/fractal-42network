NAME = fractol
CC 	 = gcc -Wall -Wextra -Werror
SRC  = control.c\
			 draw.c\
		   main.c\
		   utils.c\

OBJ  = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c fractol.h
	$(CC) -c $< -o $@

bonus : all

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
