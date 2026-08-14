NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

LIBFT = libft/libft.a

SRC = src/main.c src/stack_utils.c src/parsing.c src/utils.c \
	src/check_disorder.c src/flags.c src/strategy.c src/indexing.c \
	src/benchmark.c src/benchmark_utils.c \
	src/operations/register.c src/operations/push.c src/operations/swap.c \
	src/operations/rotate.c src/operations/rev_rotate.c \
	src/algorithms/algorithms_utils.c src/algorithms/sort_simple.c \
	src/algorithms/sort_medium.c src/algorithms/sort_complex.c src/algorithms/sort_small.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re