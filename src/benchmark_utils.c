#include "../push_swap.h"

void	print_text(char *before, int value, char *after)
{
	ft_putstr_fd(before, 2);
	ft_putnbr_fd(value, 2);
	ft_putstr_fd(after, 2);
}

static char	*adaptive_complexity(double dis)
{
	if (dis < 20.0)
		return ("Adaptive / O(n^2)\n");
	else if (dis < 50.0)
		return ("Adaptive / O(n√n))\n");
	else
		return ("Adaptive / O(n log n)\n");
}

char	*strategy_name(t_program *program)
{
	if (program->strategy == SIMPLE)
		return ("Simple / O(n^2)\n");
	if (program->strategy == MEDIUM)
		return ("Medium / O(n√n)\n");
	if (program->strategy == COMPLEX)
		return ("Complex / O(n log n)\n");
	return (adaptive_complexity(program->disorder));
}
