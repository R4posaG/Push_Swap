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

static const char	*g_op_names[OP_COUNT] = {
	"sa", "sb", "ss", "pa", "pb",
	"ra", "rb", "rr", "rra", "rrb", "rrr"
};
 
static const char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}
 
/*
** disorder is stored as a double (already scaled to a 0-100 percentage
** by apply_strategy). Split it into whole and hundredths parts by hand
** so we never format a double with an integer conversion (%i/%d), and
** never use '%' on it either, since that's only valid on integer types.
*/
static void	print_disorder(double disorder)
{
	int	whole;
	int	decimals;
 
	whole = (int)disorder;
	decimals = (int)((disorder - whole) * 100.0 + 0.5);
	if (decimals == 100)
	{
		decimals = 0;
		whole++;
	}
	ft_printf("[bench] disorder: %d.", whole);
	if (decimals < 10)
		ft_printf("0%d%%\n", decimals);
	else
		ft_printf("%d%%\n", decimals);
}

static void	print_strategy(t_strategy strategy)
{
	ft_printf(2, "[bench] strategy: %s ", strategy_name(strategy));
	if (strategy == SIMPLE)
		ft_printf(2, "/ \n");

}
/*
** All output goes to stderr, deliberately: stdout must contain ONLY the
** operation lines (sa\n, pb\n, ...) or the norm/checker will fail.
*/
void	display_benchmark(t_program *program)
{
	int	i;
 
	if (!program)
		return ;
	print_disorder(program->disorder);
	print_strategy(program->strategy);
	ft_printf(2, "[bench] total_ops: %d\n", program->total_ops);
	i = 0;
	while (i < OP_COUNT)
	{
		ft_printf(2, "  %s: %d\n", g_op_names[i], program->op_counts[i]);
		i++;
	}
}
 