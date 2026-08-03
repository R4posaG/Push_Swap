/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:30:38 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/03 17:53:49 by hjacinto         ###   ########.fr       */
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
		write(1, "rra\n", 4);
}

void	rrb(t_program *program)
{
	if (program && rev_rotate(&program->stack_b))
		write(1, "rrb\n", 4);
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
		write(1, "rrr\n", 4);
}
