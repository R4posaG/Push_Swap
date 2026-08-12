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
}	t_strategy;

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

void	sa(t_program *program);
void	pa(t_program *program);
void	ra(t_program *program);
void	rra(t_program *program);

void	sb(t_program *program);
void	pb(t_program *program);
void	rb(t_program *program);
void	rrb(t_program *program);

t_stack	*create_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
int		has_duplicates(t_stack *stack);

int		check_flags(char *arg);
void	read_flags(char *arg, t_program *program);

int	main(int argc, char **argv);

#endif
