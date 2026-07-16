#include "push_swap.h"
#include <stdio.h>

static int     ft_atoi(const char *str)
{
	int     sign;
	int     result;

	sign = 1;
	result = 0;
	if (*str == '-')
	{
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

double	ft_disorder2(int *numbers, int len)
{
	int		i;
	int		count;
	double	disorder;

	// Proteção para listas vazias ou com apenas 1 elemento (já estão ordenadas)
	if (len <= 1)
		return (0.0);

	i = 0;
	count = 0;
	while (i < len - 1)
	{
		if (numbers[i] > numbers[i + 1])
		{
			count++;
		}
		i++;
	}

	// Calcula a percentagem real de quebras na lista
	// (len - 1) é o número total de comparações feitas
	disorder = ((double)count / (len - 1)) * 100.0;

	return (disorder);
}

int	ft_disorder(int	*numbers, double len)
{
	int i = 0;
	double disorder = 0.0;
	double count = 0.0;

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

int	main(int argc, char **argv)
{
	t_program	program;
	int	numbers[argc - 1];
	int i;

	program.stack_a = NULL;
	program.stack_b = NULL;
	program.size_a = 0;
	program.size_b = 0;

	if (argc < 2)
		return ;
	i = 1;
	while (argv[i])
	{
		create_node(argv[i]);
		i++;
	}


	i = 0;
	while (i < argc - 1)
	{
		if (!ft_isdigit(argv[i + 1]))
		{
			ft_printf("Invalid argument type!")
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}


	i = 0;
	while (i < argc - 1)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n%d%%\n", ft_disorder(numbers, argc - 1));
	printf("%f%%\n", subject_disorder(numbers, argc - 1));
	printf("%f%%\n", ft_disorder2(numbers, argc - 1));

	free_stack(&program.stack_a);
	free_stack(&program.stack_b);
	return (0);
}
