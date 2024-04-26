SRC =  main.c bubble_sort.c push_swap_operations.c rotate_operations.c order_stack.c set_stack.c operations_utils.c radix.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.c.o: $(SRC)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(TESTNAME): $(OBJT) $(LIBFT)
	$(CC) $(FLAGS) $(OBJT) $(LIBFT) -o $(NAME)

.c.o: $(TEST)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft/

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

tclean:
	rm -rf $(OBJT)
	rm -rf $(TESTNAME)
	make fclean -C libft/

ret: fclean all

re: fclean all

.PHONY: clean fclean re
