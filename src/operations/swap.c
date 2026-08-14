/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:53:57 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/03 19:34:33 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	first = *stack;
	second = first->next;
	if (second->next == first) // Caso especial: Stack tem exatamente 2 elementos
	{
		*stack = second;
		return (1);
	}
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_program *program)
{
	if (program && swap(&program->stack_a))
		regist_operation(program, SA, "sa\n");
}

void	sb(t_program *program)
{
	if (program && swap(&program->stack_b))
		regist_operation(program, SB, "sb\n");
}

void	ss(t_program *program)
{
	int	swapped_a;
	int	swapped_b;

	if (!program)
		return ;
	// Verificamos e executamos ambas de forma segura
	swapped_a = swap(&program->stack_a);
	swapped_b = swap(&program->stack_b);
	// Se pelo menos uma trocou, o enunciado diz para imprimir (ou apenas se ambas, dependendo do critério estrito, mas habitualmente se ambas)
	if (swapped_a && swapped_b)
		regist_operation(program, SS, "ss\n");
}
