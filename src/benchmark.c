/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:28:28 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/14 22:22:52 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*get_op_name(t_op op)
{
	if (op == SA) return ("sa");
	if (op == SB) return ("sb");
	if (op == SS) return ("ss");
	if (op == PA) return ("pa");
	if (op == PB) return ("pb");
	if (op == RA) return ("ra");
	if (op == RB) return ("rb");
	if (op == RR) return ("rr");
	if (op == RRA) return ("rra");
	if (op == RRB) return ("rrb");
	if (op == RRR) return ("rrr");
	return ("");
}

static void	print_disorder(double disorder)
{
	int	whole;
	int	decimals;
 
	whole = (int)disorder;
	decimals = (int)((disorder - whole) * 100.0 + 0.5); // 0.5 serve para arredondar para cima
	if (decimals == 100)
	{
		decimals = 0;
		whole++;
	}
	print_text("[bench] disorder: ", whole, ".");
	if (decimals < 10)
		print_text("0", decimals, "%\n");
	else
		print_text("", decimals, "%\n");
}

static void	print_strategy(t_program *program)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(program), 2);
}

static void print_total_ops(t_program *program)
{
	int	i;

	print_text("[bench] total_ops: ", program->total_ops, "\n");
	i = 0;
	ft_putstr_fd("[bench] ", 2);
	while (i < 5)
	{
		ft_putstr_fd(get_op_name(i), 2);
		print_text(":  ", program->op_counts[i], "");
		if (i != 4)
			ft_putstr_fd("  ", 2);
		i++;
	}
	ft_putstr_fd("\n[bench] ", 2);
	while (i < OP_COUNT)
	{
		ft_putstr_fd(get_op_name(i), 2);
		print_text(":  ", program->op_counts[i], "");
		if (i != OP_COUNT - 1)
			ft_putstr_fd("  ", 2);
		i++;
	}
	ft_putstr_fd("\n", 2);
}

void	display_benchmark(t_program *program)
{
	if (!program)
		return ;
	print_disorder(program->disorder);
	print_strategy(program);
	print_total_ops(program);
}
