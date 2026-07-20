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

int	parse_arguments(int argc, char **argv, t_program program)
{
	int i;
	t_stack	*new_node;

	i = 1;
	while (argv[i])
	{
		new_node = create_node(ft_atol(argv[i]));
		if (!new_node)
			return (0);
		stack_add_back(&program.stack_a, new_node);
		program.size_a++;
		i++;
	}
	return (1);
}