/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:30:38 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/03 19:35:20 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rev_rotate(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

void	rra(t_program *program)
{
	if (program && rev_rotate(&program->stack_a))
		regist_operation(program, RRA, "rra\n");
}

void	rrb(t_program *program)
{
	if (program && rev_rotate(&program->stack_b))
		regist_operation(program, RRB, "rrb\n");
}

void	rrr(t_program *program)
{
	int	rev_a;
	int	rev_b;

	if (!program)
		return ;
	rev_a = rev_rotate(&program->stack_a);
	rev_b = rev_rotate(&program->stack_b);
	if (rev_a && rev_b)
		regist_operation(program, RRR, "rrr\n");
}
