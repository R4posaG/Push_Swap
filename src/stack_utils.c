/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:35:26 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/03 17:00:05 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1; // Inicializado a -1 até ser calculado
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack *last;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return ;
	}
	last = (*stack)->prev;
	last->next = new_node;
	new_node->prev = last;
	new_node->next = *stack;
	(*stack)->prev = new_node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_node;
	t_stack	*current;
	t_stack *last;

	if (!stack || !*stack)
		return ;
	last = (*stack)->prev;
	current = *stack;
	while (current != last)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(last);
	*stack = NULL;
}

int	is_sorted(t_stack *stack)
{
	t_stack	*head;

	if (!stack)
		return (1);
	head = stack;
	while (stack->next != head)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int has_duplicate(t_stack *stack, int num)
{
	t_stack	*head;

	if (!stack)
		return (0);
	head = stack;
	if (head->value == num)
		return (1);
	stack = stack->next;
	while (stack != head)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}