#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc < 2)
		return (0);
	program->stack_a = NULL;
	program->stack_b = NULL;
	program->size_a = 0;
	program->size_b = 0;
	if (!parse_arguments(argc, argv, &program))
	{
		write(2, "Error\n", 6);
		free_stack(&program.stack_a);
		return (1);
	}
	// program.size_a = stack_size(program.stack_a);
	
	// TODO: Add your sorting logic here
	// if (!is_sorted(program.stack_a))
	//     sort_stack(&program);

	free_stack(&program->stack_a);
	free_stack(&program->stack_b);
	return (0);
}
