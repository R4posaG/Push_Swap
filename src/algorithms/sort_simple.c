#include "push_swap.h"

// Executa uma rotação completa na stack simulando uma iteração (24 linhas)
static int	bubble_pass(t_program *program)
{
	int		swapped;
	int		i;
	int		size;

	swapped = 0;
	i = 0;
	size = program->size_a;
	while (i < size - 1)
	{
		if (program->stack_a->index > program->stack_a->next->index)
		{
			sa(program);
			swapped = 1;
		}
		ra(program);
		i++;
	}
	ra(program);
	return (swapped);
}

// Algoritmo principal Bubble Sort O(n^2) (13 linhas)
void	sort_simple(t_program *program)
{
	int	has_swapped;

	if (program->size_a <= 1)
		return ;
	if (program->size_a == 2)
	{
		if (program->stack_a->index > program->stack_a->next->index)
			sa(program);
		return ;
	}
	has_swapped = 1;
	while (has_swapped)
	{
		has_swapped = bubble_pass(program);
	}
}
