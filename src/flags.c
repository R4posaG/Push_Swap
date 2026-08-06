int	check_flags(int argc, char **argv, t_program *program)
{
	return (ft_strcmp(argv[1], "--Complex") || ft_strcmp(argv[1], "--Simple") 
		|| ft_strcmp(argv[1], "--Medium") || ft_strcmp(argv[1], "--Adaptive"));
}

void	read_flags(int argc, char **argv, t_program *program)
{
		if (ft_strcmp(argv[1], "--Simple"))
			program->strategy = SIMPLE;
		else if (ft_strcmp(argv[1], "--Medium"))
			program->strategy = MEDIUM;
		else if (ft_strcmp(argv[1], "--Complex"))
			program->strategy = COMPLEX;
		else
			program->strategy = ADAPTIVE;
}
