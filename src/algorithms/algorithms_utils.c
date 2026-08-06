/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algorithms_utils.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ajoao <ajoao@student.42.fr>               #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/30 18:06:01 by ajoao            #+#    #+#              */
/*   Updated: 2026/08/04 11:22:40 by ajoao           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Por enquanto temos estas funções auxiliares, mas podemos adicionar mais conforme necessário.
// Alg. 1 - Verifica se a pilha já está em ordem crescente
bool is_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//  Alg. 2 - Retorna o nó com o maior valor na pilha

t_stack	*find_highest(t_stack *stack)
{
	t_stack	*highest;

	if (!stack)
		return (NULL);
	highest = stack;
	while (stack)
	{
		if (stack->value > highest->value)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

//  Alg. 4 - Retorna o nó com o menor valor na pilha

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

//  Alg. 5 - Retorna a posição (índice 0, 1, 2...) do nó desejado na pilha

int	get_pos(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

//  Alg. 6 - Normaliza os valores brutos para índices de 0 a N-1 (essencial para o Radix)

void	index_stack(t_stack *a)
{
	t_stack	*curr;
	t_stack	*compare;
	int		idx;

	curr = a;
	while (curr)
	{
		idx = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < curr->value)
				idx++;
			compare = compare->next;
		}
		curr->index = idx;
		curr = curr->next;
	}
}
