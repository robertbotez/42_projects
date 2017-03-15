NAME = fdf

SRC = read.c draw.c get_next_line.c get_points.c main.c projection.c get_color.c expose_hook.c config_map.c default.c

OBJ = read.o draw.o get_next_line.o get_points.o main.o projection.o get_color.o expose_hook.o config_map.o default.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

MLX = -Lincludes/minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L libft/ -lft

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc -I $(INC) $(FLAGS) -c $(SRC)
	gcc $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
