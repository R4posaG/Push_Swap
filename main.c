#include "push_swap.h"
#include <stdio.h>

double subject_disorder(int *numbers, int len)
{
	int i = 0;
	int j;
	int total_pairs = 0;
	int mistakes = 0;

	while (i < len - 1)
	{
		j = i + 1;
		while (j < len) // Corrigido: vai até ao último elemento (index len - 1)
		{
			total_pairs++;
			if (numbers[i] > numbers[j])
				mistakes++;
			j++;
		}
		i++;
	}
	// Proteção contra divisão por zero (se já estiver ordenado, desordem é 0.0)
	if (total_pairs == 0 || mistakes == 0)
		return (0.0);

	// Cast feito antes da divisão para preservar os números decimais
	return ((double)mistakes / total_pairs);
}

int	ft_disorder(int	*numbers, double len)
{
	int	i;
	double disorder;
	double count;

	if (len <= 1)
		return (0);
	i = 0;
	count = 0;
	disorder = 0;
	while (i < len - 1)
	{
		if (numbers[i] > numbers[i + 1])
		{
			disorder += (100.0 / len);
			count++;
		}
		i++;
	}
	if (count == len - 1)
		disorder += (100.0 / len);
	return (disorder);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	t_program	program;
	int i;

	if (argc < 2)
		return (0);
	program.stack_a = NULL;
	program.stack_b = NULL;
	program.size_a = 0;
	program.size_b = 0;
	if (!parse_arguments(argc, argv, &program))
	{
		write(2, "Error\n", 6);
		free_stack(&program.stack_a);
		return (1);
	}
	program.size_a = stack_size(program.stack_a);
	
	// TODO: Add your sorting logic here
	// if (!is_sorted(program.stack_a))
	//     sort_stack(&program);

	free_stack(&program.stack_a);
	return (0);


	i = 1;
	while (argv[i])
	{
		stack_add_back(&program.stack_a, create_node(ft_atoi(argv[i])));
		i++;
	}


	ft_printf("\n%d%%\n", ft_disorder(numbers, argc - 1));
	ft_printf("%d%%\n", subject_disorder(numbers, argc - 1));

	free_stack(&program.stack_a);
	free_stack(&program.stack_b);
	return (0);
}
