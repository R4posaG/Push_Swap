/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:43:56 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/15 12:09:03 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	subject_disorder(t_stack **stack_a)
{
	long	mistakes;
	long	total_pairs;
	t_stack	*current;
	t_stack	*next;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = *stack_a;
	while (1)
	{
		next = current->next;
		while (next != *stack_a)
		{
			total_pairs++;
			if (current->value > next->value)
				mistakes++;
			next = next->next;
		}
		current = current->next;
		if (current == *stack_a)
			break ;
	}
	return ((double)mistakes / total_pairs);
}
