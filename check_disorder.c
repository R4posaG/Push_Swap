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
