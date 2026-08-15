/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:30:23 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/15 12:28:37 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_complex(t_program *program)
{
	int	i;
	int	j;
	int	max_bits;

	if (!program || !program->stack_a || is_sorted(program->stack_a))
		return ;
	max_bits = 0;
	while (((program->size_a - 1) >> max_bits) > 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < program->size_a)
		{
			if ((((program->stack_a)->index >> i) & 1) == 0)
				pb(program);
			else
				ra(program);
			j++;
		}
		while (program->size_b > 0)
			pa(program);
		i++;
	}
}
