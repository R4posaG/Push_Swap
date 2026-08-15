/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:28:58 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/15 15:17:26 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_indices(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;
	int		count;

	if (!stack)
		return ;
	current = stack;
	while (1)
	{
		count = 0;
		runner = stack;
		while (1)
		{
			if (runner->value < current->value)
				count++;
			runner = runner->next;
			if (runner == stack)
				break ;
		}
		current->index = count;
		current = current->next;
		if (current == stack)
			break ;
	}
}
