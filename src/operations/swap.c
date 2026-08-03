/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:53:57 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/03 17:53:58 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	first->prev = second;
	second->next = first;
	second->prev = first->prev;
	*stack = second;
	return (1);
}

void	sa(t_program *program)
{
	if (program && swap(&program->stack_a))
		write(1, "sa\n", 3);
}

void	sb(t_program *program)
{
	if (program && swap(&program->stack_b))
		write(1, "sb\n", 3);
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
		write(1, "ss\n", 3);
}
