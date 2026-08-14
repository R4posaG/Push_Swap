/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:30:39 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/14 23:06:42 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Auxiliar O(n^2): Encontra o menor, roda pelo caminho mais curto e joga em B
static void	push_current_min(t_program *program)
{
	t_stack	*min;
	int		pos;

	min = find_min(program->stack_a);
	pos = get_pos(program->stack_a, min);
	if (pos <= program->size_a / 2)
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

// Algoritmo Seleção/Extração O(n^2) Limpo e Otimizado (15 linhas)
void	sort_simple(t_program *program)
{
	if (!program || program->size_a <= 1 || is_sorted(program->stack_a))
		return ;
	// Esvazia a stack A enviando sempre o menor de cada vez para B
	while (program->size_a > 3)
		push_current_min(program);
	// Ordena os 3 que restaram de forma ultra rápida
	sort_three(program);
	// Devolve tudo ordenado para a stack A
	while (program->size_b > 0)
		pa(program);
}
