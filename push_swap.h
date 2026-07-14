#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
    int             value;       // O número original recebido no argumento
    int             index;       // A posição correta do número após a ordenação (essencial para o algoritmo)
    struct s_stack  *next;       // Aponta para o elemento abaixo
    struct s_stack  *prev;       // Aponta para o elemento acima
}   t_stack;

void	sa(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
int		stack_size(t_stack *stack);

int	main(int argc, char **argv);

#endif
/*
push_swap/
├── push_swap.h        <- Contém a struct e protótipos
├── main.c             <- Ponto de entrada, validação inicial e chamada do algoritmo
├── stack_utils.c      <- Funções para criar, limpar e manipular os nós da lista
├── algorithm.c        <- A lógica principal de ordenação (ex: Turk ou Radix)
└── operations/        <- Pasta com as instruções obrigatórias
    ├── swap.c         <- Implementação de sa, sb, ss
    ├── push.c         <- Implementação de pa, pb
    ├── rotate.c       <- Implementação de ra, rb, rr
    └── rev_rotate.c   <- Implementação de rra, rrb, rrrr
*/