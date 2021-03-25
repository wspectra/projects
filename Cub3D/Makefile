NAME		= cub3D

SRCS		= main.c read_file.c\
			./parsing/parsing.c ./parsing/check_resolution_validity.c\
			./parsing/check_colors_validity.c ./parsing/check_path_validity.c\
			./parsing/check_map_validity.c ./parsing/check_cell.c\
			delete.c ./game/make_game.c ./game/make_image.c game/draw_textures.c\
			./game/make_sprite.c ./game/make_screenshot.c parsing/check_diag.c\
			make_structure.c ./game/moves.c utils.c

OBJS		=  $(SRCS:.c=.o)

LIBFT		= ./libft/libft.a

MLX			= ./mlx/libmlx.dylib

INCL		= cub3d.h

CC			= gcc

RM			= rm -f

FLAGS		= -Wall -Wextra -Werror

FLAGS_MLX	= -framework OpenGL -framework AppKit

all:	$(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		$(CC) -L./mlx $(FLAGS_MLX) -lmlx -L./libft/ -lft $(OBJS) -o $(NAME)

$(LIBFT):
		make -C ./libft/

$(MLX):
		make -C ./mlx/
		cp ./mlx/libmlx.dylib ./

%.o: %.c $(INCL)
		 $(CC) $(FLAGS) -I ./mlx.h -c $< -o $@

clean:
		$(RM) $(OBJS)
		make clean -C ./libft/
		make clean -C ./mlx/

fclean: clean
		$(RM) $(NAME)
		$(RM) libmlx.dylib
		$(RM) ./mlx/libmlx.dylib
		make fclean -C ./libft/

re:		fclean all

.PHONY:
		all, clean, fclean, re