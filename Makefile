SRC = *.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Werror -Wextra -g
NAME = push_swap

all:$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

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
