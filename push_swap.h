#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;


typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}			t_strategy;

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   				t_stack;

typedef struct s_program
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size_a;
	int			size_b;
	t_strategy	strategy;
	int			bench_mode;
	int			op_counts[OP_COUNT];
	int			total_ops;
	double		disorder;
}				t_program;

/* stack_utils.c */
t_stack	*create_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
int		has_duplicate(t_stack *stack, int num);

/* utils.c */
void	free_matrix(char **matrix);
long	ft_atol(const char *str);
void	print_error(void);

/* parsing.c */
int		parse_arguments(int argc, char **argv, t_program *program);

/* flags.c */
int		check_flags(char *arg);
void	read_flags(char *arg, t_program *program);
int		count_flags(int argc, char **argv);

/* indexing.c */
void	assign_indices(t_stack *stack);

/* algorithms_utils.c */
t_stack	*find_highest(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int		get_pos(t_stack *stack, t_stack *target);
void	index_stack(t_stack *a);

/* strategy.c */
void	apply_strategy(t_program *program);

/* check_disorder.c */
double	subject_disorder(t_stack **stack);

/* sort_simple.c */
void	sort_simple(t_program *program);

/* sort_medium.c */
void	sort_three(t_program *program);
void	sort_four_five(t_program *program);
void	sort_stack(t_program *program);

/* sort_complex.c */
void	radix_sort(t_program *program);

/* register.c */
void	regist_operation(t_program *program, t_op op_type, char *op_str);

/* operations: swap.c / push.c / rotate.c / rev_rotate.c */
void	sa(t_program *program);
void	sb(t_program *program);
void	pa(t_program *program);
void	pb(t_program *program);
void	ra(t_program *program);
void	rb(t_program *program);
void	rr(t_program *program);
void	rra(t_program *program);
void	rrb(t_program *program);
void	rrr(t_program *program);

/* benchmark.c */
void	display_benchmark(t_program *program);

/* benchmark_utils.c*/
void	print_text(char *before, int value, char *after);
char	*strategy_name(t_program *program);

/* main.c */
int	main(int argc, char **argv);

#endif
