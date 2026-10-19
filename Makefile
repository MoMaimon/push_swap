NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = operations_push.c  operations_reverse_rotate.c  operations_rotate.c  operations_swap.c  parse.c  sort_large.c  sort_smail.c  stack_init.c  stack_utils.c
OBJ = $(SRC:.c=.o)
all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
