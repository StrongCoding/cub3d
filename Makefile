SRC_DIR 	=	./source
OBJ_DIR 	=	./objects
INC_DIR		= 	./includes

FILES 		=	main \
				movement \
				hooks \
				init \
				sprite \
				render \
				bresenham \
				dda \
				painting \
				../parsing/map \
                ../parsing/map_lengths \
                ../parsing/get_identifier \
                ../parsing/get_colors \
                ../parsing/get_map \
                ../parsing/map_check \
                ../parsing/convert_struct \
                ../parsing/free \
                ../minimap/minimap

SRCS 		= 	$(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJS 		= 	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

NAME		=	cub3D
#FLAGS		=	-Wall -Werror -Wextra -g
FLAGS		= 	-g -fsanitize=address
#FLAGS		= 	-g -fsanitize=memory
MLX_FLAGS	=	-L/usr/X11/lib -lX11 -lXext -lm
INC			=	-I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR) -I /usr/X11/include

LIBFT_DIR = ./ft_printf
LIBFT = ./ft_printf/libftprintf.a

MLX_DIR = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	cc $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C ./parsing fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re

