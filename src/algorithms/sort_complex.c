#include "push_swap.h"

void	radix_sort(t_program *program)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	index_stack(program->stack_a);
	size = ft_lstsize(program->stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) > 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((program->stack_a)->index >> i) & 1) == 0)
				pb(program);
			else
				ra(program);
		}
		while (program->stack_b)
			pa(program);
		i++;
	}
}
