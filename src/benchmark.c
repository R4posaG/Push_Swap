#include "../push_swap.h"

static const char	*g_op_names[OP_COUNT] = {
	"sa", "sb", "ss", "pa", "pb",
	"ra", "rb", "rr", "rra", "rrb", "rrr"
};

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
		ft_putstr_fd(g_op_names[i], 2);
		print_text(":  ", program->op_counts[i], "");
		if (i != 4)
			ft_putstr_fd("  ", 2);
		i++;
	}
	ft_putstr_fd("\n[bench] ", 2);
	while (i < OP_COUNT)
	{
		ft_putstr_fd(g_op_names[i], 2);
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
