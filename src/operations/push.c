/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:25:57 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/15 15:17:06 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	insert_dest(t_stack **dest, t_stack *node)
{
	if (!*dest)
	{
		*dest = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *dest;
		node->prev = (*dest)->prev;
		(*dest)->prev->next = node;
		(*dest)->prev = node;
		*dest = node;
	}
}

static int	push(t_stack **src, t_stack **dest)
{
	t_stack	*node_to_move;

	if (!src || !*src)
		return (0);
	node_to_move = *src;
	if (node_to_move->next == node_to_move)
		*src = NULL;
	else
	{
		node_to_move->prev->next = node_to_move->next;
		node_to_move->next->prev = node_to_move->prev;
		*src = node_to_move->next;
	}
	insert_dest(dest, node_to_move);
	return (1);
}

void	pa(t_program *program)
{
	if (program && push(&program->stack_b, &program->stack_a))
	{
		program->size_a++;
		program->size_b--;
		regist_operation(program, PA, "pa\n");
	}
}

void	pb(t_program *program)
{
	if (program && push(&program->stack_a, &program->stack_b))
	{
		program->size_a--;
		program->size_b++;
		regist_operation(program, PB, "pb\n");
	}
}
