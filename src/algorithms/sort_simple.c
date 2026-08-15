/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:30:39 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/15 12:29:41 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

void	sort_simple(t_program *program)
{
	if (!program || program->size_a <= 1 || is_sorted(program->stack_a))
		return ;
	while (program->size_a > 3)
		push_current_min(program);
	sort_three(program);
	while (program->size_b > 0)
		pa(program);
}
