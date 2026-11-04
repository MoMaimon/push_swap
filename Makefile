NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# add files when u add function in them <3
SRC = main.c operations_push.c operations_reverse_rotate.c operations_rotate.c operations_swap.c disorder.c benchmark.c parse.c stack_utils.c parse_number.c bench_init.c medium.c medium_utils.c optimization_utils.c optimization.c sort_utils.c
OBJ = $(SRC:%.c= $(BIN)/%.o)

SRC_BONUS = checker_bonus.c operations_push.c operations_reverse_rotate.c operations_rotate.c operations_swap.c disorder.c benchmark.c parse.c stack_utils.c parse_number.c bench_init.c medium.c medium_utils.c optimization_utils.c optimization.c sort_utils.c

OBJ_BONUS = $(SRC_BONUS:%.c= $(BIN)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

BIN = bin

all: $(NAME)

bonus: $(BONUS_NAME)

$(BIN)/%.o: %.c
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)

clean:
	rm -fr $(BIN)
	make -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all clean fclean re bonus
