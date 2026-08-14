/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:08:41 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/14 23:27:57 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_two(t_program *program)
{
	if (program->stack_a->index > program->stack_a->next->index)
		sa(program);
}

void	sort_three(t_program *program)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(program->stack_a))
		return ;
	top = program->stack_a->index;
	mid = program->stack_a->next->index;
	bot = program->stack_a->prev->index;
	if (top > mid && mid < bot && top < bot)
		sa(program);
	else if (top > mid && mid > bot)
	{
		sa(program);
		rra(program);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(program);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(program);
		ra(program);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(program);
}

static void	push_current_min(t_program *program)
{
	t_stack	*min;
	int		pos;

	min = find_min(program->stack_a);
	pos = get_pos(program->stack_a, min);
	if (pos <= program->size_a / 2)
	{
		while (program->stack_a != min)
			ra(program);
	}
	else
	{
		while (program->stack_a != min)
			rra(program);
	}
	pb(program);
}

static void	sort_four_five(t_program *program, int size)
{
	if (size == 5)
		push_current_min(program);
	push_current_min(program);
	sort_three(program);
	pa(program);
	if (size == 5)
		pa(program);
}

void	sort_small(t_program *program)
{
	int	size;

	if (!program)
		return ;
	size = program->size_a;
	if (size <= 1)
		return ;
	if (size == 2)
		sort_two(program);
	else if (size == 3)
		sort_three(program);
	else if (size == 4 || size == 5)
		sort_four_five(program, size);
}
