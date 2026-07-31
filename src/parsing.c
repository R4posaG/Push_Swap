static int is_valid(char *arg)
{
	int i;

	i = 0;
	while (arg[i] == ' ' || (arg[i] >= '\t' && arg[i] <= '\r'))
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;	
	while (is_digit(arg[i]))
		i++;
	if (!is_digit(arg[i]))
		return (0);
	return (1);
}

static long	ft_atol(const char *str)
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

// Função auxiliar para libertar a matriz do split em caso de erro
static void free_matrix(char **matrix)
{
    int i;

    if (!matrix)
        return ;
    i = 0;
    while (matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}


int	parse_arguments(int argc, char **argv, t_program *program)
{
	int		i;
	int		j;
	long	num;
	char    **args;
	t_stack	*new_node;

	i = 1;
	while (argv[i])
	{
		if (!is_valid(argv[i]))
			return (0);
		args = ft_split(argv[i], ' ');
    	if (!args)
        	return (0);
		j = 0;
		while (args[j])
		{
			num = ft_atol(args[j]);
			if (num < INT_MIN || num > INT_MAX)
			{
				free(args);
				return (0);
			}
			new_node = create_node(num);
			if (!new_node)
				return (0);
			stack_add_back(&program->stack_a, new_node);
			program->size_a++;
			free(args[j]);
			j++;
		}
		free(args);
		i++;
	}
	return (1);
}
