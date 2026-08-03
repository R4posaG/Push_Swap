#include "push_swap.h"

// Executa a estratégia selecionada ou decide a adaptativa (20 linhas)
void	apply_strategy(t_program *program)
{
	double	disorder;

	disorder = subject_disorder(&program->stack_a);
	program->disorder = disorder * 100.0;
	if (program->strategy == ADAPTIVE)
	{
		if (disorder < 0.2)
			program->strategy = SIMPLE;
		else if (disorder < 0.5)
			program->strategy = MEDIUM;
		else
			program->strategy = COMPLEX;
	}
	if (program->strategy == SIMPLE)
		sort_simple(program);
	else if (program->strategy == MEDIUM)
		sort_medium(program);
	else if (program->strategy == COMPLEX)
		sort_complex(program);
}
