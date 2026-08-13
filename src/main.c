/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:42:21 by hjacinto          #+#    #+#             */
/*   Updated: 2026/08/08 17:19:25 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_program(t_program *program)
{
	int	i;

	program->stack_a = NULL;
	program->stack_b = NULL;
	program->size_a = 0;
	program->size_b = 0;
	program->strategy = ADAPTIVE;
	program->bench_mode = 0;
	program->total_ops = 0;
	program->disorder = 0.0;
	i = 0;
	while (i < OP_COUNT)
	{
		program->op_counts[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program	program;
	int			i;

	if (argc < 2)
		return (0);
	initialize_program(&program);
	i = count_flags(argc, argv);
	while (i--)
		read_flags(argv[i], &program);
	if (!parse_arguments(argc, argv, &program))
	{
		free_stack(&program.stack_a);
		return (print_error(), 1);
	}
	assign_indices(program.stack_a);
	if (!is_sorted(program.stack_a))
		apply_strategy(&program);
	if (program.bench_mode)
		display_benchmark(&program);
	free_stack(&program.stack_a);
	free_stack(&program.stack_b);
	return (0);
}
