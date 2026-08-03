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
    int             value;       // O número original recebido no argumento
    int             index;       // A posição correta do número após a ordenação (essencial para o algoritmo)
    struct s_stack  *next;       // Aponta para o elemento abaixo
    struct s_stack  *prev;       // Aponta para o elemento acima
}   t_stack;

typedef struct s_program
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;

	t_strategy	strategy;
	int			bench_mode;
	int			op_counts[OP_COUNT];
	int			total_ops;
	double		disorder;
}	t_program;

void	sa(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);

void	sb(t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rrb(t_stack **stack_b);

t_stack	*create_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
int		has_duplicates(t_stack *stack);

int	main(int argc, char **argv);

#endif
/*
push_swap/
├── push_swap.h        <- Contém a struct e protótipos
├── main.c             <- Ponto de entrada, validação inicial e chamada do algoritmo
├── stack_utils.c      <- Funções para criar, limpar e manipular os nós da lista
├── algorithms/        <- A lógica principal de ordenação (ex: Turk, Radix, ...)
└── operations/        <- Pasta com as instruções obrigatórias
    ├── swap.c         <- Implementação de sa, sb, ss
    ├── push.c         <- Implementação de pa, pb
    ├── rotate.c       <- Implementação de ra, rb, rr
    └── rev_rotate.c   <- Implementação de rra, rrb, rrrr
*/