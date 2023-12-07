NAME := cub2d

CC := cc

#CFLAGS := -g
#CFLAGS :=  -fsanitize=address -g
CFLAGS := -Wall -Wextra -Werror -g3
# find / -name libreadline.aCFLAGS := $(CFLAGS) -fsanitize=address
SRC :=	main.c map.c map_check_line.c map_lengths.c map_tools.c get_identifier.c free.c

#INCLUDES := -I inc -I tools/ft_printf -I $(HOME)/goinfre/.brew/opt/readline/include/readline/ -L $(HOME)/goinfre/.brew/opt/readline/lib/
#INCLUDES := -I inc -I tools/ft_printf -I readline/include/readline -L readline/lib

OBJ := $(SRC:%.c=$(OBJ)%.o)

#INCLUDES := -I inc -I tools/ft_printf  -I${READLINE_PATH}/includes -L${READLINE_PATH}/lib -lreadline -lhistory -ltermcap
INCLUDES := -I inc -I ../ft_printf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ../ft_printf


	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) ../ft_printf/libftprintf.a $(INCLUDES)
#	@echo "Linking $(NAME)"

$(OBJ_DIR)/%.o: $(SRC)/%.c inc/
#	@make -C ../ft_printf
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "Compiling $<"

clean:
	@make -C ../ft_printf clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@make -C ../ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re