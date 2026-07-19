int	parse_arguments(int argc, char **argv, t_program program)
{
	int i;
	t_stack	*new_node;

	i = 1;
	while (argv[i])
	{
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
			return (0);
		stack_add_back(&program.stack_a, new_node);
		i++;
	}
	return (1);
}