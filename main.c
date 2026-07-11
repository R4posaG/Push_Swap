#include "push_swap.h"
#include <stdio.h>

static int     ft_atoi(const char *str)
{
	int     sign;
	int     result;

	sign = 1;
	result = 0;
	if (*str != '-')
	{
			while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			str++;
		}
	}
	return (result * sign);
}

int	ft_disorder(int	*numbers, double len)
{
	int i = 0;
	double disorder = 0;
	int count = 0;

	i = 0;
	count = 0;
	disorder = 0;
	while (i < len - 1)
	{
		if (numbers[i] > numbers[i + 1])
		{
			disorder += (100 / len);
			count++;
		}
		i++;
	}
	if (count == len - 1)
		disorder += (100 / len);
	return (disorder);
}

int	main(int argc, char **argv)
{
	int	numbers[argc - 1];
	int i;

	if (argc > 1)
	{
		i = 0;
		while (i < argc - 1)
		{
			numbers[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}



	i = 0;
	while (i < argc - 1)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n%d%%\n", ft_disorder(numbers, argc - 1));
	return (0);
}
