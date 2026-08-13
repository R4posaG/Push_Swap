NAME = pushswap

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

LIBFT = libft/libft.a

SRC = main.c stack_utils.c parsing.c utils.c \
	check_disorder.c flags.c strategy.c indexing.c benchmark.c \
	operations/register.c operations/push.c operations/swap.c \
	operations/rotate.c operations/rev_rotate.c \
	algorithms/algorithms_utils.c algorithms/sort_simple.c \
	algorithms/sort_medium.c algorithms/sort_complex.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ)
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