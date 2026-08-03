/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:55:52 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/03 19:26:42 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(t_strategy strat)
{
	write(2, "[bench] strategy: ", 18);
	if (strat == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (strat == MEDIUM)
		ft_putstr_fd("Medium / O(n*sqrt(n))\n", 2);
	else if (strat == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
}


static void	print_operations(t_program *p)
{
	int			i;
	static char	*ops[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};

	i = 0;
	while (i < OP_COUNT)
	{
		ft_putstr_fd("[bench] count ", 2);
		ft_putstr_fd(ops[i], 2);
		if (i == 0 || i == 1 || i == 2 || i == 5 || i == 6 || i == 7)
			ft_putstr_fd(" : ", 2);
		else
			ft_putstr_fd(": ", 2);
		ft_putnbr_fd(p->op_counts[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
}

// Exemplo de como formatar a saída de acordo com a página 17 do PDF
void	display_benchmark(t_program *p)
{
	if (!p->bench_mode)
		return ;
	write(2, "[bench] disorder: ", 18);
	ft_putnbr_fd((int)p->disorder, 2);

	ft_putchar_fd('.', 2);
	if ((int)p->disorder < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(((int)(p->disorder * 100 + 0.5)) % 100, 2);
	ft_putstr_fd("%\n", 2);
	
	print_strategy(p->strategy);

	ft_putstr_fd("[bench] total operations: ", 2);
	ft_putnbr_fd(p->total_ops, 2);
	ft_putchar_fd('\n', 2);

	print_operations(p);
	// ... aplicar o prefixo "[bench] " a todas as outras linhas exigidas!
}
