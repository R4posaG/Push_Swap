static const char	*g_op_names[OP_COUNT] = {
	"sa", "sb", "ss", "pa", "pb",
	"ra", "rb", "rr", "rra", "rrb", "rrr"
};

static const char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple / O(n^2)\n");
	if (strategy == MEDIUM)
		return ("Medium / O(n√n)\n");
	if (strategy == COMPLEX)
		return ("Complex / O(n log n)\n");
	return ("Adaptive");
}

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
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(strategy), 2);
}

static void print_total_ops(t_program *program)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(program->total_ops, 2);
	i = 0;
	ft_putstr_fd("\n[bench] ", 2);
	while (i < 5)
	{
		ft_putstr_fd(g_op_names[i], 2);
		ft_putstr_fd(":  ", 2);
		ft_putnbr_fd(program->op_counts[i], 2);
		ft_putstr_fd("  ", 2);
		i++;
	}
	ft_putstr_fd("\n[bench] ", 2);
	while (i < OP_COUNT)
	{
		ft_putstr_fd(g_op_names[i], 2);
		ft_putstr_fd(":  ", 2);
		ft_putnbr_fd(program->op_counts[i], 2);
		ft_putstr_fd("  ", 2);
		i++;
	}
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
	print_total_ops(program);
}

/*
	ft_printf("[bench] total_ops: %d\n", program->total_ops);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n",
		program->sa, program->sb, program->ss, program->pa, program->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
		program->ra, program->rb, program->rr, program->rra, program->rrb, program->rrr);
*/