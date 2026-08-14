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

#include "../../push_swap.h"

// Calcula a raiz quadrada aproximada de forma compacta
static int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

// Fase 1: Envia os elementos para a Stack B usando a janela móvel (Chunks)
static void	push_to_b_chunks(t_program *program, int chunk_size)
{
	int	i;

	i = 0;
	while (program->size_a > 0)
	{
		if (program->stack_a->index <= i)
		{
			pb(program);
			rb(program);
			i++;
		}
		else if (program->stack_a->index <= i + chunk_size)
		{
			pb(program);
			i++;
		}
		else
			ra(program);
	}
}

// Fase 2: Puxa de volta para a Stack A, trazendo sempre o maior de cada vez
static void	pull_to_a_ordered(t_program *program)
{
	t_stack	*max_node;
	int		pos;

	while (program->size_b > 0)
	{
		max_node = find_highest(program->stack_b);
		pos = get_pos(program->stack_b, max_node);
		if (pos <= program->size_b / 2)
		{
			while (program->stack_b != max_node)
				rb(program);
		}
		else
		{
			while (program->stack_b != max_node)
				rrb(program);
		}
		pa(program);
	}
}

// Função principal do Medium Algorithm O(n√n) - Ambas as sub-funções passam na Norme
void	sort_medium(t_program *program)
{
	int	chunk_size;

	if (!program || program->size_a <= 5)
		return ;
	chunk_size = ft_sqrt(program->size_a) * 15 / 10;
	push_to_b_chunks(program, chunk_size);
	pull_to_a_ordered(program);
}

