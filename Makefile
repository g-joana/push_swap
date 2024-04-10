SRC = bubble_sort.c push_swap.c set_stack.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
LIBFT = libft/libft.a

all:$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

.c.o: $(SRC)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft/

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: clean fclean re
