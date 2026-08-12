void	display_benchmark(t_program *program)
{
	if (!program)
		return ;
	ft_printf("[bench] disorder: %i.", program->disorder / 100);
	if ((program->disorder % 100) == 0)
		ft_printf("00%%\n");
	else
		ft_printf("%i%%\n", program->disorder % 100);
	ft_printf("[bench] strategy: %s\n", program->strategy);
	ft_printf("[bench] total_ops: %d\n", program->total_ops);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n",
		program->sa, program->sb, program->ss, program->pa, program->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		program->ra, program->rb, program->rr, program->rra, program->rrb, program->rrr);
}
