NAME = fractol

SRC = main.c julia.c julia_move.c julia_colors.c mandelbrot.c mandelbrot_colors.c mandelbrot_move.c \
burning_ship.c burning_ship_colors.c burning_ship_move.c fractols_utils.c hooks.c zoom.c

CC = cc
CFLAGS = -Wall -Wextra -Werror 
LIBS = -lmlx -framework OpenGL -framework AppKit
INCLUDE = fractol.h

all:$(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(LIBS) $(SRC) -I$(INCLUDE) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all