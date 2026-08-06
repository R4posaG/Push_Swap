/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algorithms.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ajoao <ajoao@student.42.fr>               #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/02 11:08:48 by ajoao            #+#    #+#              */
/*   Updated: 2026/08/06 11:27:42 by ajoao           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Abaixo seguem os algoritmos mëdios de ordenação para stacks de diferentes tamanhos

// Ordena exatamente 3 elementos em no máximo 2 movimentos

void	sort_three(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a);
	else if ((*a)->next == highest)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

// Auxiliar para 4 e 5 elementos: traz o menor nó pro topo e joga em B

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		pos;
	int		size;

	min = find_min(*a);
	pos = get_pos(*a, min);
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		while (*a != min)
			ra(a);
	}
	else
	{
		while (*a != min)
			rra(a);
	}
	pb(b, a);
}

// Ordena 4 e 5 elementos em no máximo 12 movimentos

void	sort_four_five(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}

// Algoritmo Radix Bit a Bit para mais de 5 elementos

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	index_stack(*a);
	size = ft_lstsize(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) > 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(b, a);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

// Ponto central de decisão do algoritmo

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_four_five(a, b);
	else
		radix_sort(a, b);
}
