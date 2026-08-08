/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:08:48 by ajoao             #+#    #+#             */
/*   Updated: 2026/08/08 21:17:38 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Abaixo seguem os algoritmos mëdios de ordenação para stacks de diferentes tamanhos

// Ordena exatamente 3 elementos em no máximo 2 movimentos
void	sort_three(t_program *program)
{
	t_stack	*highest;

	highest = find_highest(program->stack_a);
	if (program->stack_a == highest)
		ra(program);
	else if (program->stack_a->next == highest)
		rra(program);
	if (program->stack_a->value > program->stack_a->next->value)
		sa(program);
}

// Auxiliar para 4 e 5 elementos: traz o menor nó pro topo e joga em B
static void	push_min_to_b(t_program *program)
{
	t_stack	*min;
	int		pos;
	int		size;

	min = find_min(program->stack_a);
	pos = get_pos(program->stack_a, min);
	size = ft_lstsize(program->stack_a);
	if (pos <= size / 2)
	{
		while (program->stack_a != min)
			ra(program);
	}
	else
	{
		while (program->stack_a != min)
			rra(program);
	}
	pb(program);
}

// Ordena 4 e 5 elementos em no máximo 12 movimentos

void	sort_four_five(t_program *program)
{
	while (ft_lstsize(program->stack_a) > 3)
		push_min_to_b(program);
	sort_three(program->stack_a);
	while (program->size_b > 0)
		pa(program);
}

// Algoritmo Radix Bit a Bit para mais de 5 elementos

void	radix_sort(t_program *program)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	index_stack(program->stack_a);
	size = ft_lstsize(program->stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) > 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((program->stack_a->index >> i) & 1) == 0)
				pb(program);
			else
				ra(program);
		}
		while (program->size_b > 0)
			pa(program);
		i++;
	}
}

// Ponto central de decisão do algoritmo

void	sort_stack(t_program *program)
{
	int	size;

	if (!program || !program->stack_a || is_sorted(program->stack_a))
		return ;
	size = ft_lstsize(program->stack_a);
	if (size == 2)
		sa(program);
	else if (size == 3)
		sort_three(program);
	else if (size <= 5)
		sort_four_five(program);
	else
		radix_sort(program);
}
