/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:30:23 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/14 21:30:24 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_complex(t_program *program)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (!program || !program->stack_a || is_sorted(program->stack_a))
		return ;
	size = program->size_a;
	max_bits = 0;
	// Calcula quantos bits precisamos de analisar com base no maior índice (size - 1)
	while (((size - 1) >> max_bits) > 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			// Se o bit atual for 0, envia para a stack B
			if ((((program->stack_a)->index >> i) & 1) == 0)
				pb(program);
			else
				ra(program);
			j++;
		}
		// Devolve todos os elementos de B para A de forma segura
		while (program->size_b > 0)
			pa(program);
		i++;
	}
}
