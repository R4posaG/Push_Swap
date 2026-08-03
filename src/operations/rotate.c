/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:38:54 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/03 17:53:53 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	*stack = (*stack)->next;
	return (1);
}

void	ra(t_program *program)
{
	if (program && rotate(&program->stack_a))
		write(1, "ra\n", 3);
}

void	rb(t_program *program)
{
	if (program && rotate(&program->stack_b))
		write(1, "rb\n", 3);
}

void	rr(t_program *program)
{
	int	rotated_a;
	int	rotated_b;

	if (!program)
		return ;
	rotated_a = rotate(&program->stack_a);
	rotated_b = rotate(&program->stack_b);
	if (rotated_a && rotated_b)
		write(1, "rr\n", 3);
}
