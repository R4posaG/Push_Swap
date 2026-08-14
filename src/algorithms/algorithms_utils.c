/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 18:06:01 by ajoao             #+#    #+#             */
/*   Updated: 2026/08/08 21:18:27 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*find_highest(t_stack *stack)
{
	t_stack	*highest;
	t_stack	*head;

	if (!stack)
		return (NULL);
	head = stack;
	highest = stack;
	while (1)
	{
		if (stack->value > highest->value)
			highest = stack;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (highest);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*head;

	if (!stack)
		return (NULL);
	head = stack;
	min = stack;
	while (1)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (min);
}

int	get_pos(t_stack *stack, t_stack *target)
{
	t_stack	*head;
	int		pos;

	if (!stack || !target)
		return (0);
	head = stack;
	pos = 0;
	while (1)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (pos);
}
